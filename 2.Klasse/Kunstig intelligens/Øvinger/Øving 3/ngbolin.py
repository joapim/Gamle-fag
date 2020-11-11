class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """
    def minimax_value(self, gameState, depth, agent):
        if depth == 0 or not bool(gameState.getLegalActions(agent)): return self.evaluationFunction(gameState)

        if agent == 0: # Pacman is playing - aiming to maximise its own payoffs
            maxV = float('-inf')
            next_agent = agent + 1;

            for action in gameState.getLegalActions(agent):
                value = self.minimax_value(gameState.generateSuccessor(agent, action), depth, next_agent)
                maxV = max(value, maxV)
            return maxV

        else: # Ghosts are playing - aiming to minimise the payoff to PacMan
            minV = float('inf')
            if (int(agent) + 1) == int(gameState.getNumAgents()): depth -= 1; next_agent = 0
            else: next_agent = agent + 1

            for action in gameState.getLegalActions(agent):
                value = self.minimax_value(gameState.generateSuccessor(agent, action), depth, next_agent)
                minV = min(value, minV)
            return minV

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
        agent = self.index; depth = self.depth

        if (int(agent) + 1) == int(gameState.getNumAgents()): next_agent = 0
        else: next_agent = agent + 1

        return max(gameState.getLegalActions(agent),
                   key=lambda action: self.minimax_value(gameState.generateSuccessor(agent, action), depth, next_agent))

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def max_value(self, gameState, alpha, beta, depth, agent):
        if depth == 0 or not bool(gameState.getLegalActions(agent)): return self.evaluationFunction(gameState)

        next_agent = agent + 1

        v = float('-inf')
        for action in gameState.getLegalActions(agent):
            v = max(v, self.min_value(gameState.generateSuccessor(agent, action), alpha, beta, depth, next_agent))
            alpha = max(v, alpha)
            '''
            If it turns out that the minimum score that the maximising player can get (beta) is higher than the highest possible
            score that he can obtain from another subtree (alpha) - subject to his opponent's play, and it is currently his turn,
            there's no need to evaluate the subtree, as his opponent will force him to get the lowest possible score.
            '''
            if beta < alpha: break
        return v

    def min_value(self, gameState, alpha, beta, depth, agent):
        if depth == 0 or not bool(gameState.getLegalActions(agent)): return self.evaluationFunction(gameState)

        v = float('inf')
        if (int(agent) + 1) == int(gameState.getNumAgents()): depth -= 1; next_agent = 0
        else: next_agent = agent + 1

        for action in gameState.getLegalActions(agent):
            if next_agent > 0: # Ghost's turn to move **again**...
                v = min(v, self.min_value(gameState.generateSuccessor(agent, action), alpha, beta, depth, next_agent))
            else: # Pacman's turn to move!
                v = min(v, self.max_value(gameState.generateSuccessor(agent, action), alpha, beta, depth, next_agent))
            beta = min(v, beta)
            '''
            If it turns out that the highest possible score that our player can obtain by playing in another subtree (alpha) is
            higher than that of the minimum score that the maximising player is guaranteed of (beta), and it is the opponent's turn,
            we do not have to evaluate the subtree as the opponent will ensure that we will never get to the subtree.
            '''
            if beta < alpha: break
        return v

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        # Initializing alpha and beta values
        alpha = float('-inf') # Minimum value that PacMan can get
        beta = float('inf') # Maximum value that PacMan can get
        agent = self.index; depth = self.depth

        best_score, best_action = float('-inf'), None
        v = float('-inf')

        for action in gameState.getLegalActions(agent):
            v = max(v, self.min_value(gameState.generateSuccessor(agent, action), alpha, beta, depth, agent+1))
            if best_score < v:
                best_score = v
                best_action = action

            alpha = max(v, alpha)
            if beta < alpha: break

        return best_action
