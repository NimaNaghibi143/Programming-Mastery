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
            derivatives = self.model.rhs(self.t, self.state[i])
            self.state[i+1] = self.state[i] + self.h*derivatives
            self.t += self.h
            self.t_values[i+1] = self.t

        return np.round(self.state, 1), self.t_values
    
    def RK2(self):
        self._initialize()

        for i in range(self.N-1):
            # In the general notation, x is the independent variable (mostly time)
            # and y the dependent variable. In our case, x is time (t) and y is the 
            # [prey, predator] vector. Although time is not in the dx and dy equations,
            # but is there for better compatibility of the code for non-autonomous systems.
            y = self.state[i]
            k1 = self.h * self.model.rhs(self.t, y)
            k2 = self.h * self.model.rhs(self.t + (self.h/2), y + k1)
            self.state[i+1] = y + (k1+k2)/2
            self.t += self.h
            self.t_values[i+1] = self.t
        
        return np.round(self.state, 1), self.t_values
        