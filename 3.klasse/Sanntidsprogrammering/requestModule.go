package requesthandler

import (
	"time"

	"../elevio"
)

func OrderExecution(CH_InternalFloorUpdate chan elevio.Elevator, CH_DirectionUpdate chan elevio.MotorDirection, CH_internalOrderUpdate chan elevio.Elevator, CH_LampUpdate chan elevio.Lamp, CH_FloorUpdateTX chan elevio.Elevator) {
	runOnce := true
	for {

		select {
		case elevatorState := <-CH_InternalFloorUpdate:
			for len(elevatorState.HallQueue) != 0 || len(elevatorState.CabQueue) != 0 || elevatorState.Behaviour != elevio.EB_Idle {
				switch elevatorState.Behaviour {
				case elevio.EB_Idle:

					if Requests_shouldStop(elevatorState) == true {

						// Clear lights in that order, we pick up everyone when stopping at a floor --> clear all lights on the floor
						cabLamp := elevio.Lamp{LampType: "button", Button: elevio.BT_Cab, Floor: elevatorState.Floor, Power: false}
						hallUpLamp := elevio.Lamp{LampType: "button", Button: elevio.BT_HallUp, Floor: elevatorState.Floor, Power: false}
						hallDownLamp := elevio.Lamp{LampType: "button", Button: elevio.BT_HallDown, Floor: elevatorState.Floor, Power: false}
						CH_LampUpdate <- cabLamp
						CH_LampUpdate <- hallUpLamp
						CH_LampUpdate <- hallDownLamp

						elevatorState, _ = Requests_clearAtCurrentFloor(elevatorState, -1)
						CH_FloorUpdateTX <- elevatorState
						CH_internalOrderUpdate <- elevatorState

						CH_DirectionUpdate <- elevio.MD_Stop
						elevatorState.Behaviour = elevio.EB_DoorOpen

					} else {
						elevatorState.Behaviour = elevio.EB_Moving
					}

				case elevio.EB_Moving:
					select {
					case elevatorState = <-CH_InternalFloorUpdate:
						elevatorState.Behaviour = elevio.EB_Moving
						if Requests_shouldStop(elevatorState) == true {
							runOnce = true
							elevatorState.Behaviour = elevio.EB_Idle
						}

					default:
						if runOnce == true {
							var newDirn = Requests_chooseDirection(elevatorState)
							//elevatorState.Floor = -1
							if newDirn != elevatorState.Dirn {
								elevatorState.Dirn = newDirn
								CH_DirectionUpdate <- elevatorState.Dirn
								runOnce = false
							}
						}

					}

				case elevio.EB_DoorOpen:
					CH_DirectionUpdate <- elevio.MD_Stop
					doorLamp := elevio.Lamp{LampType: "door", Power: true}
					CH_LampUpdate <- doorLamp
					time.Sleep(elevio.DOOR_OPEN_TIME)
					doorLamp = elevio.Lamp{LampType: "door", Power: false}
					CH_LampUpdate <- doorLamp
					elevatorState.Behaviour = elevio.EB_Idle
				}
			}
		}
	}
}

func Requests_shouldStop(e elevio.Elevator) bool {

	if len(e.CabQueue) != 0 {
		for i := 0; i < len(e.CabQueue); i++ {
			if e.Floor == e.CabQueue[i] {
				return true
			}
		}
	} else if len(e.HallQueue) != 0 {
		for i := 0; i < len(e.HallQueue); i++ {
			if e.Floor == e.HallQueue[i].Floor {
				return true
			}
		}
	} else if len(e.HallQueue) == 0 && len(e.CabQueue) == 0 {
		return true
	}

	return false
}

func Requests_chooseDirection(e elevio.Elevator) elevio.MotorDirection {

	if len(e.CabQueue) != 0 {
		if e.Floor > e.CabQueue[0] {
			return elevio.MD_Down
		} else if e.Floor < e.CabQueue[0] {
			return elevio.MD_Up
		}

	} else if len(e.HallQueue) != 0 {
		if e.Floor > e.HallQueue[0].Floor {
			return elevio.MD_Down
		} else if e.Floor < e.HallQueue[0].Floor {
			return elevio.MD_Up
		}
	}
	return elevio.MD_Stop
}

func Requests_clearAtCurrentFloor(e elevio.Elevator, floor int) (elevio.Elevator, int) {
	var arrivedAtRequest int

	for i := 0; i < len(e.CabQueue); i++ {
		if e.Floor == e.CabQueue[i] {
			e.CabQueue = removeCabOrder(e.CabQueue, i)
		}
	}

	for i := 0; i < len(e.HallQueue); i++ {
		if e.Floor == e.HallQueue[i].Floor {
			e.HallQueue = removeHallOrder(e.HallQueue, i)
		}
	}

	if e.Floor == floor {
		arrivedAtRequest = 1
		return e, arrivedAtRequest
	}

	arrivedAtRequest = 0
	return e, arrivedAtRequest

}

func removeHallOrder(slice []elevio.HallRequest, index int) []elevio.HallRequest {
	return append(slice[:index], slice[index+1:]...)
}

func removeCabOrder(slice []int, index int) []int {
	return append(slice[:index], slice[index+1:]...)
}

func AddRequestToQueue(elevatorState elevio.Elevator, request elevio.ButtonEvent) elevio.Elevator {
	if request.Button == elevio.BT_HallUp || request.Button == elevio.BT_HallDown {
		if len(elevatorState.HallQueue) != 0 {
			elevatorState.HallQueue = append(elevatorState.HallQueue, elevio.HallRequest{request.Floor, request.Button, false})
		} else {
			elevatorState.HallQueue = []elevio.HallRequest{{request.Floor, request.Button, false}}
		}

	} else if request.Button == elevio.BT_Cab {
		if len(elevatorState.CabQueue) != 0 {
			elevatorState.CabQueue = append(elevatorState.CabQueue, request.Floor)
		} else {
			elevatorState.CabQueue = []int{request.Floor}
		}
	}
	return elevatorState
}
