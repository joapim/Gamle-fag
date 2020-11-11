package controller

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"time"

	"../elevio"
	"../network/peers"
	requesthandler "../requestModule"
)

type Cost struct {
	State    elevio.Elevator
	duration int
}

func Controller(myID string, CH_StateUpdateRX chan elevio.Elevator, CH_InternalFloorUpdate chan elevio.Elevator, CH_internalOrderUpdate chan elevio.Elevator, peerUpdateCh chan peers.PeerUpdate, CH_FloorUpdateRX chan elevio.Elevator, CH_FloorUpdateTX chan elevio.Elevator, CH_LampUpdate chan elevio.Lamp) {
	plsNoCrashComputer := 0 // TODO: Denne stopper kanin-multiplikasjon av terminalvinduer om noke går gale
	var p peers.PeerUpdate

	var elev1Temp elevio.Elevator
	var elev2Temp elevio.Elevator

	elev1 := elevio.Elevator{ID: "1", Behaviour: elevio.EB_Idle}
	elev2 := elevio.Elevator{ID: "2", Behaviour: elevio.EB_Idle}

	elevator1 := &elev1
	elevator2 := &elev2

	//var newFloorUpdate elevio.Elevator
	//newFloorUpdatePointer := &newFloorUpdate
	fmt.Printf("start of controller\n")

	for {
		select {
		case newFloorUpdate := <-CH_FloorUpdateRX:

			if newFloorUpdate.ID != myID {
				if myID == "1" {
					fmt.Printf("FloorUpdateRX from Elev2: %+v\n", newFloorUpdate.Floor)
					elev2Temp = newFloorUpdate //TODO: try using elev1 instead of elev1Temp
					elevator2 = &elev2Temp     //&elev1Temp
					fmt.Printf("Elev2: %+v\n", elevator2)

				} else if myID == "2" {
					fmt.Printf("FloorUpdateRX from Elev1: %+v\n", newFloorUpdate.Floor)
					elev1Temp = newFloorUpdate
					elevator1 = &elev1Temp
					fmt.Printf("Elev1: %+v\n", elevator1)
				}
			} else if newFloorUpdate.ID == myID {
				if myID == "1" {
					*elevator1 = newFloorUpdate
				} else if myID == "2" {
					*elevator2 = newFloorUpdate
				}

			}

		case p = <-peerUpdateCh:
			fmt.Printf("Peer update:\n")
			fmt.Printf("  Peers:    %q\n", p.Peers)
			fmt.Printf("  New:      %q\n", p.New)
			fmt.Printf("  Lost:     %q\n", p.Lost)

			// When a new peer joins send a CH_FloorUpdateTX to it
			if len(p.New) != 0 {
				if len(p.Peers) > 1 { //p.New != myID &&
					if myID == "1" {
						fmt.Printf("FloorUpdateTX from Elev1: %+v\n", elevator1.Floor)
						CH_FloorUpdateTX <- *elevator1 // TODO: this might trigger the case below, but I think it wont

					} else if myID == "2" {
						fmt.Printf("FloorUpdateTX from Elev2: %+v\n", elevator2.Floor)
						CH_FloorUpdateTX <- *elevator2
					}
				}
			}

			timer1 := time.NewTimer(500 * time.Millisecond)
			select {
			case <-timer1.C:
				//plsNoCrashComputer = 0
				//fmt.Printf("Spam preventer")

			default:
				// Restarts a peer if it is lost
				if len(p.Lost) != 0 && plsNoCrashComputer < 3 {
					if p.Lost[0] != myID {

						plsNoCrashComputer++

						//Finds the path to the file that is currently running, aka restart code will work on any path in any OS:)
						dir, error1 := filepath.Abs(filepath.Dir(os.Args[0]))
						if error1 != nil {
							log.Fatal(error1)
						}

						if myID == "1" {
							cmd := exec.Command(`cmd`, `/C`, `start`, dir+`\main.exe`, `--id=2`, `--port=15658`)
							log.Printf("Restarting elevator %v and waiting for it to finish...\n", p.Lost[0])
							err := cmd.Run() // TODO: decide which to use: Run() runs the command and waits for it to complete. Start() runs and does not wait
							log.Printf("Restart finished with error: %v", err)
							// Send the restarted elevator it's old states and orders
							CH_FloorUpdateTX <- *elevator1

						} else if myID == "2" {
							cmd := exec.Command("cmd", "/C", "start", dir+`\main.exe`, "--id=1")
							log.Printf("Restarting elevator %v and waiting for it to finish...\n", p.Lost[0])
							err := cmd.Run()
							log.Printf("Restart finished with error: %v", err)
							CH_FloorUpdateTX <- *elevator2
						}

						// TODO: Check if we have been alone for a while (aka only elev1 manages to boot on full system init)
					}
					//Handle network segmentation if x restarts have failed, wait a bit and try again
				} else if plsNoCrashComputer >= 3 {
					fmt.Printf("plsNoCrashComputer has saved the day. No more terminal windows will open for a while:)")
					//TODO: add a timer here that resets plsNoCrashComputer after xx seconds so that we can try restarting again. Start goroutine that sleeps and then returns

				}

			}

			// newstate = instead?
		case newState := <-CH_StateUpdateRX:

			buttonLamp := elevio.Lamp{LampType: "button", Button: newState.Requests.Button, Floor: newState.Requests.Floor, Power: true}

			if newState.ID == myID && newState.Requests.Button == elevio.BT_Cab || len(p.Peers) < 2 {
				newState = requesthandler.AddRequestToQueue(newState, newState.Requests)
				CH_internalOrderUpdate <- newState
				CH_InternalFloorUpdate <- newState

				CH_LampUpdate <- buttonLamp

			} else if newState.Requests.Button != elevio.BT_Cab {
				if newState.ID == "1" {
					*elevator1 = newState

				} else if newState.ID == "2" {
					*elevator2 = newState
				}
				//fmt.Printf("Elev1 in controller: %+v\n", elevator1)
				//fmt.Printf("Elev2 in controller: %+v\n", elevator2)

				//Calculate cost as the duration it takes to serve the request
				durationElev1 := timeToServeRequest(*elevator1, newState.Requests)
				durationElev2 := timeToServeRequest(*elevator2, newState.Requests)

				fmt.Printf("Elev1 duration: %+v\n", durationElev1)
				fmt.Printf("Elev2 duration: %+v\n", durationElev2)

				if myID == "1" {
					if durationElev1 < durationElev2 {
						*elevator1 = requesthandler.AddRequestToQueue(*elevator1, newState.Requests)
						fmt.Printf("elev1 duration shortest, sending state to elevator_driver %+v\n", elevator1)
						CH_internalOrderUpdate <- *elevator1
						CH_InternalFloorUpdate <- *elevator1
						CH_LampUpdate <- buttonLamp

					} else if durationElev1 == durationElev2 {
						*elevator1 = requesthandler.AddRequestToQueue(*elevator1, newState.Requests)
						fmt.Printf("Duration equal, sending state to elevator_driver %+v\n", elevator1)
						CH_internalOrderUpdate <- *elevator1
						CH_InternalFloorUpdate <- *elevator1
						CH_LampUpdate <- buttonLamp

					} else {
						fmt.Printf("elev1 duration > elev2, Elevator 1 lost the competition \n")
					}

				} else if myID != "1" {
					if durationElev2 < durationElev1 {
						*elevator2 = requesthandler.AddRequestToQueue(*elevator2, newState.Requests) //newState.Requests
						fmt.Printf("elev2 duration shortest, sending state to elevator_driver %+v\n", elevator2)
						CH_internalOrderUpdate <- *elevator2
						CH_InternalFloorUpdate <- *elevator2
						CH_LampUpdate <- buttonLamp

					} else if durationElev1 == durationElev2 {
						// elevator 2 does nothing, Elevator 1 wins on ID

					} else {
						fmt.Printf("elev2 duration > elev1, Elevator 2 lost the competition \n")
					}
				}
			}
		}
	}

}

// Cost function
func timeToServeRequest(e_old elevio.Elevator, request elevio.ButtonEvent) time.Duration {
	e := e_old
	arrivedAtRequest := 0
	var duration time.Duration
	e = requesthandler.AddRequestToQueue(e, request)
	//fmt.Printf("elevator %+v after adding request in timeToServe: %+v\n", e.ID, e)

	// Switch that ensures we are ready for entering the simulation
	switch e.Behaviour {
	case elevio.EB_Idle:
		e.Dirn = requesthandler.Requests_chooseDirection(e)
		if e.Dirn == elevio.MD_Stop {
			return duration
		}

	case elevio.EB_Moving:
		duration += elevio.TRAVEL_TIME / 2
		if e.Dirn == elevio.MD_Up {
			e.Floor++
		} else if e.Dirn == elevio.MD_Down {
			e.Floor--
		}

	case elevio.EB_DoorOpen:
		duration -= elevio.DOOR_OPEN_TIME / 2
	}

	// Simulating order execution
	for {
		if requesthandler.Requests_shouldStop(e) {
			e, arrivedAtRequest = requesthandler.Requests_clearAtCurrentFloor(e, request.Floor)
			if arrivedAtRequest == 1 {
				return duration
			}
			duration += elevio.DOOR_OPEN_TIME
			e.Dirn = requesthandler.Requests_chooseDirection(e)
		}
		if e.Dirn == elevio.MD_Up {
			e.Floor++
		} else if e.Dirn == elevio.MD_Down {
			e.Floor--
		}
		duration += elevio.TRAVEL_TIME
	}
}
