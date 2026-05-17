import numpy as np


class ODESolver:

    @staticmethod
    def Euler(model, initial_state, h, N):
        t = 0
        state = np.zeros((N, len(initial_state)))
        t_values = np.zeros(N)
        state[0] = initial_state
        for i in range(0, N-1):
            derivatives = model.rhs(state[i])
            state[i+1] = state[i] + h*(np.array(derivatives))
            t += h
            t_values[i+1] = t


        return np.round(state, 1), t_values