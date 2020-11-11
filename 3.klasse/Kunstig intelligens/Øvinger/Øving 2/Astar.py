from Map import Map_Obj
import numpy as np


def bfsa(startpoint, endpoint):#best first search algorithm
    locked = {}
    unlocked = []
   
    firstNode = Node(None, startpoint)#Initial start state for node
    firstNode.g = 0 #Initial g(n0)
    firstNode.h = manhattan(startpoint, endpoint) #Find h(n0)
    firstNode.f = firstNode.g + firstNode.h #f(n0) = g(n0) + h(n0)

    unlocked.append(firstNode) #Add firstNode to unlocked

    while 1:
        if len(unlocked) == 0: #If emty array, return false
            return None, False

        node = unlocked.pop(0) #initialize node
        mappoint.set_cell_value(node.position, 3) #enter cell value
        locked[tuple(node.position)] = node #Change value of index


        if  endpoint == node.position: #Result we are looking for then printing map
            mappoint.show_map()
            return node, True
   

        node.chooseHeir(target=endpoint)
    
        for i in node.heir: # Checking for mulitple variations
            if i in unlocked:
                for j in range(len(unlocked)):
                    if i == unlocked[j]:
                        i = unlocked[j]
                        break

            if (i not in unlocked) and (tuple(i.position) not in locked.keys()):
                linkheirsToPosition(i, node, endpoint)
                unlocked.append(i)
                unlocked.sort(key=lambda x: x.f)

            if tuple(i.position) in locked.keys() and (i.g < locked[tuple(i.position)].g):
                linkheirsToPosition(i, node, endpoint)
                if tuple(i.position) in locked.keys():
                    ProduceRoad(i)


class Node:
    def __init__(self, heritage = None, position = None): #initialize node class
        self.heritage = heritage
        self.position = position
        self.f = 0
        self.g = 0
        self.h = 0
        self.heir = []

    def variableCheck(self, other): #Check variable
        return other.position == self.position

    def chooseHeir(self, target): #Traveling in the grid
        heirCoordinate = []
        i=1
        j=0

        if (mappoint.get_cell_value([self.position[j] + i, self.position[i]])) != -i: heirCoordinate.append([self.position[j] + i, self.position[i]])
        if (mappoint.get_cell_value([self.position[j] - i, self.position[i]])) != -i: heirCoordinate.append([self.position[j] - i, self.position[i]])
        if (mappoint.get_cell_value([self.position[j], self.position[i] + i])) != -i: heirCoordinate.append([self.position[j], self.position[i] + i])
        if (mappoint.get_cell_value([self.position[j], self.position[i] - i])) != -i: heirCoordinate.append([self.position[j], self.position[i] - i])

        for successor in heirCoordinate:
            heirs = Node(self, successor)
            heirs.g = self.g + mappoint.get_cell_value(successor)
            heirs.h = manhattan(successor, target)
            heirs.f = heirs.g + heirs.h
            self.heir.append(heirs)


def manhattan(startpoint: list, endpoint: list): #Calculate distance from data point to another
    startpointOne = np.abs(startpoint[1] - endpoint[1])
    startpointZero = np.abs(startpoint[0] - endpoint[0])
    return startpointOne +startpointZero  


def linkheirsToPosition(heirs: Node, heritage: Node, target: list): #Setting up heirs
    heirs.heritage = heritage
    heirs.g = heritage.g + mappoint.get_cell_value(heirs.position)
    heirs.h = manhattan(heirs.position, target)
    heirs.f = heirs.g + heirs.h


def ProduceRoad(heritage):
    for successor in heritage.heir: #initialzing successor
        if (heritage.g + mappoint.get_cell_value(successor.position) < successor.g):
            successor.heritage = heritage
            successor.g = heritage.g + mappoint.get_cell_value(successor.position)
            successor.f = successor.g + successor.h
            ProduceRoad(successor)


mappoint = Map_Obj(task=4)
result_node, greatResult = bfsa(mappoint.start_pos, mappoint.goal_pos)

if greatResult is True: #printing map
    while result_node is not mappoint.start_pos and result_node is not None:
        print(result_node.position)
        mappoint.set_cell_value(result_node.position, " G ")
        result_node = result_node.heritage
    mappoint.show_map()