# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
	"""
	  A reflex agent chooses an action at each choice point by examining
	  its alternatives via a state evaluation function.

	  The code below is provided as a guide.  You are welcome to change
	  it in any way you see fit, so long as you don't touch our method
	  headers.
	"""


	def getAction(self, gameState):
		"""
		You do not need to change this method, but you're welcome to.

		getAction chooses among the best options according to the evaluation function.

		Just like in the previous project, getAction takes a GameState and returns
		some Directions.X for some X in the set {North, South, West, East, Stop}
		"""
		# Collect legal moves and successor states
		legalMoves = gameState.getLegalActions()

		# Choose one of the best actions
		scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
		bestScore = max(scores)
		bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
		chosenIndex = random.choice(bestIndices) # Pick randomly among the best

		"Add more of your code here if you want to"

		return legalMoves[chosenIndex]

	def evaluationFunction(self, currentGameState, action):
		"""
		Design a better evaluation function here.

		The evaluation function takes in the current and proposed successor
		GameStates (pacman.py) and returns a number, where higher numbers are better.

		The code below extracts some useful information from the state, like the
		remaining food (newFood) and Pacman position after moving (newPos).
		newScaredTimes holds the number of moves that each ghost will remain
		scared because of Pacman having eaten a power pellet.

		Print out these variables to see what you're getting, then combine them
		to create a masterful evaluation function.
		"""
		# Useful information you can extract from a GameState (pacman.py)
		successorGameState = currentGameState.generatePacmanSuccessor(action)
		newPos = successorGameState.getPacmanPosition()
		newFood = successorGameState.getFood()
		newGhostStates = successorGameState.getGhostStates()
		newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

		"*** YOUR CODE HERE ***"
		return successorGameState.getScore()

def scoreEvaluationFunction(currentGameState):
	"""
	  This default evaluation function just returns the score of the state.
	  The score is the same one displayed in the Pacman GUI.

	  This evaluation function is meant for use with adversarial search agents
	  (not reflex agents).
	"""
	return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
	"""
	  This class provides some common elements to all of your
	  multi-agent searchers.  Any methods defined here will be available
	  to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

	  You *do not* need to make any changes here, but you can if you want to
	  add functionality to all your adversarial search agents.  Please do not
	  remove anything, however.

	  Note: this is an abstract class: one that should not be instantiated.  It's
	  only partially specified, and designed to be extended.  Agent (game.py)
	  is another abstract class.
	"""

	def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
		self.index = 0 # Pacman is always agent index 0
		self.evaluationFunction = util.lookup(evalFn, globals())
		self.depth = int(depth)

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


        def maxValue(gameState, depth):
            """
            We are building the minimax-tree using maxValue
            and minValue. Inside each function, they are calling
            each other. This creates the minimax algorithm
            which consits of two sides. The minimax-tree shows
            all possible moves and can estimate the best behavior.
            In the maxValue the calculations of the maximum value
            is estimated.
            """
            behavior = gameState.getLegalActions(0)
            behave = None
            minusInfinity = -(float("inf"))

            if len(behavior) == 0:
                return (self.evaluationFunction(gameState), None)      #Trivial start
            if len(behavior) == gameState.isWin():
                return (self.evaluationFunction(gameState), None)
            if len(behavior) == gameState.isLose():
                return (self.evaluationFunction(gameState), None)
            if depth == self.depth:
                return (self.evaluationFunction(gameState), None)

            for i in behavior:
                expectedBehavior = minValue(gameState.generateSuccessor(0, i), 1, depth)[0] #Calling minValue
                if(minusInfinity  < expectedBehavior ):
                    minusInfinity = expectedBehavior
                    behave = i
            return [minusInfinity, behave]




        def minValue(gameState, plant, depth):
            """
            This is very similar to the maxValue function. The
            difference are that we are starting with infinity
            and doing the opposite of the maxValue function.
            minValue  estimate the behavior with respect
            to the minimum cost.
            """
            behavior = gameState.getLegalActions(plant)
            behave = None
            infinity = float("inf")

            if len(behavior) == 0:  #Trivial start
                return(self.evaluationFunction(gameState), None)

            for i in behavior:
                if(plant != gameState.getNumAgents() -1): #Either calling minValue or maxValue
                    expectedBehavior = minValue(gameState.generateSuccessor(plant, i), plant + 1, depth)[0]
                else:
                    expectedBehavior = maxValue(gameState.generateSuccessor(plant, i), depth + 1)[0]
                if(infinity  > expectedBehavior):
                    infinity = expectedBehavior
                    behave = i
            return[infinity, behave]

        maxValue = maxValue(gameState, 0)
        maxValue = maxValue[1]
        return maxValue





class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        def maxValue(gameState, depth, alpha, beta):
            """
            The difference between the class minimaxAgent and the
            class AlphaBetaAgent is the time. The Alpha-Beta
            algorithm uses less time calculating than the minimax
            algorithm. This is done even though the behavior in
            maxValue in minimaxAgent is almost identical to the
            maxValue in AlphaBetaAgent. The difference is that the
            maxValue in AlphaBetaAgent is cutting off  one of the
            sides(depends on the if statements)
            """
            behavior = gameState.getLegalActions(0)
            behave = None
            minusInfinity = -(float("inf"))

            if len(behavior) == 0:                                  #Trivial start
                return (self.evaluationFunction(gameState), None)
            if len(behavior) == gameState.isWin():
                return (self.evaluationFunction(gameState), None)
            if len(behavior) == gameState.isLose():
                return (self.evaluationFunction(gameState), None)
            if depth == self.depth:
                return (self.evaluationFunction(gameState), None)

            for i in behavior: #Calling minValue
                expectedBehavior = minValue(gameState.generateSuccessor(0, i), 1, depth, alpha, beta)[0]
                if minusInfinity < expectedBehavior:
                    minusInfinity = expectedBehavior
                    behave = i
                if alpha > minusInfinity:
                    alpha = alpha
                if alpha < minusInfinity:
                    alpha =minusInfinity
                if minusInfinity > beta:
                    return [minusInfinity, behave]

            return [minusInfinity, behave]




        def minValue(gameState, plant, depth, alpha, beta):
            """
            From the tree the behavior  is calculated focused on
            low cost. As what we could expect from theory,
            the alpha-beta algorithm is an improved  version
            of the minimax algorithm.
            """
            behavior = gameState.getLegalActions(plant)
            behave = None
            infinity = float("inf")

            if len(behavior) == 0:  #Trivial start
                return (self.evaluationFunction(gameState), None)


            for i in behavior: #Either calling minValue or maxValue
                if (plant != gameState.getNumAgents() - 1):
                    expectedBehavior = minValue(gameState.generateSuccessor(plant, i), plant + 1, depth, alpha, beta)[0]
                else:
                    expectedBehavior = maxValue(gameState.generateSuccessor(plant, i), depth + 1, alpha, beta)[0]

                if infinity > expectedBehavior:
                    infinity = expectedBehavior
                    behave = i
                if infinity < alpha:
                    return [infinity, behave]
                if beta > infinity:
                    beta = infinity
                if beta < infinity:
                    beta = beta

            return[infinity, behave]

        alphaMax = -(float("inf"))
        betaMax = float("inf")

        maxValue = maxValue(gameState, 0, alphaMax, betaMax)
        maxValue = maxValue[1]
        return maxValue




class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
          Returns the expectimax action using self.depth and self.evaluationFunction

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"
        util.raiseNotDefined()

def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).

      DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction

