import numpy as np


class LotkaVolterra:

    def __init__(self, alpha=1.1, beta=0.4, gamma=0.4, delta=0.1):
        self.alpha = alpha
        self.beta = beta
        self.gamma = gamma
        self.delta = delta

    def set_parameters(self, alpha=None, beta=None, gamma=None, delta=None):
        if alpha is not None:
            self.alpha = alpha
        if beta is not None:
            self.beta = beta
        if gamma is not None:
            self.gamma = gamma
        if delta is not None:
            self.delta = delta

    def get_parameters(self):
        return {
            "alpha": self.alpha,
            "beta": self.beta,
            "gamma": self.gamma,
            "delta": self.delta
        }
    
    def rhs(self, t, state):
        x, y = state
        
        dx_dt = self.alpha*x - self.beta*x*y
        dy_dt = -self.gamma*y + self.delta*x*y
        
        return np.array([dx_dt, dy_dt])