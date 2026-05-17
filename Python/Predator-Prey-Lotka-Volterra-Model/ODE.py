import numpy as np


class ODESolver:

    def __init__(self, model, initial_state, h, N):
        self.model = model
        self.initial_state = initial_state
        self.h = h
        self.N = N

    def _initialize(self):
        """Helper function to initialize parameters and avoid repeated code"""
        self.t = 0
        self.state = np.zeros((self.N, len(self.initial_state)))
        self.t_values = np.zeros(self.N)
        self.state[0] = self.initial_state

    def Euler(self):
        self._initialize()

        for i in range(self.N-1):
            derivatives = self.model.rhs(self.state[i])
            self.state[i+1] = self.state[i] + self.h*(np.array(derivatives))
            self.t += self.h
            self.t_values[i+1] = self.t

        return np.round(self.state, 1), self.t_values