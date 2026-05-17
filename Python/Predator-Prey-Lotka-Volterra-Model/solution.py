import matplotlib.pyplot as plt
from LotkaVolterra import LotkaVolterra
from ODE import ODESolver
from plot import plot


lv_model = LotkaVolterra()
solver = ODESolver(lv_model, [10, 10], 0.01, 10000)
states, t_values = solver.Euler()

fig = plot(states, t_values)
plt.show()