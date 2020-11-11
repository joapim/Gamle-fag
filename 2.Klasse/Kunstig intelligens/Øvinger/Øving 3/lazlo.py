class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.
          Here are some method calls that might be useful when implementing minimax.
          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1
          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action
          gameState.getNumAgents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"
        def max_value(gameState,depth):
            Actions=gameState.getLegalActions(0)
            if len(Actions)==0 or gameState.isWin() or gameState.isLose() or depth==self.depth:             ###The trvial situations(state)
                return(self.evaluationFunction(gameState),None)
            w=-(float("inf"))                                                                               ###We are trying to implement the 2 sides of the minimax algorithm the max and the min
            Act=None
            for action in Actions:                                                                          ###In that way that the 2 functions are calling each other is like building the tree(diagrams from tha class)
                sucsValue=min_value(gameState.generateSuccessor(0,action),1,depth)                          #We have the available moves and we are seeking for the "best" one
                sucsValue=sucsValue[0]                                                                      #It is working exactly as the theory of minimax algorithm commands
                if(sucsValue>w):                                                                            #Here we have as start -infinite
                    w,Act=sucsValue,action
            return(w,Act)

        def min_value(gameState,agentID,depth):
            Actions=gameState.getLegalActions(agentID)
            if len(Actions) == 0:
                return(self.evaluationFunction(gameState),None)
            l=float("inf")                                                                                  ###As we see in contrast with max we begin from +infinte
            Act=None
            for action in Actions:
                if(agentID==gameState.getNumAgents() -1):
                    sucsValue=max_value(gameState.generateSuccessor(agentID,action),depth + 1)
                else:
                    sucsValue=min_value(gameState.generateSuccessor(agentID,action),agentID+1,depth)        ###We are doing exactly the opposite from the max "function"
                sucsValue=sucsValue[0]
                if(sucsValue<l):
                    l,Act=sucsValue,action
            return(l,Act)
        max_value=max_value(gameState,0)[1]
        return max_value                                                                                    ###We are starting from the max and it goes as a tree max min max min

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        def max_value(gameState,depth,a,b):
            Actions = gameState.getLegalActions(0) # Get actions of pacman
            if len(Actions)==0 or gameState.isWin() or gameState.isLose() or depth==self.depth:
                return (self.evaluationFunction(gameState), None)

            w=-(float("inf"))
            Act=None
                                                                                                            ###We can see that the alpha beta agent is almost the same as the minimax with the difference
                                                                                                            ###that now we have the pruning if w>a or w<b in the 2 "edges"
            for action in Actions:
                sucsValue=min_value(gameState.generateSuccessor(0,action),1,depth,a,b)
                sucsValue=sucsValue[0]
                if w<sucsValue:
                    w,Act=sucsValue,action
                if w>b:
                    return (w,Act)
                a=max(a,w)
            return (w,Act)

        def min_value(gameState,agentID,depth,a,b):
            " Cases checking "
            Actions=gameState.getLegalActions(agentID) # Get the actions of the ghost
            if len(Actions) == 0:
                return (self.evaluationFunction(gameState),None)
                                                                                                            ###As we know from theory the alpha beta algorithms is an improved version
                                                                                                            ###of the minimax in order to "pull through" some time,to have a better time
                                                                                                            ###complexity
            l = float("inf")
            Act = None
            for action in Actions:
                if (agentID == gameState.getNumAgents() - 1):
                    sucsValue = max_value(gameState.generateSuccessor(agentID,action),depth + 1,a,b)
                else:
                    sucsValue = min_value(gameState.generateSuccessor(agentID,action),agentID + 1,depth,a,b)
                sucsValue=sucsValue[0]
                if (sucsValue<l):
                    l,Act=sucsValue,action

                if (l<a):
                    return (l,Act)

                b=min(b,l)

            return(l,Act)                                                                                      ###I think there is nothing else to be said about this agent

        a=-(float("inf"))
        b=float("inf")
        max_value=max_value(gameState,0,a,b)[1]
        return max_value