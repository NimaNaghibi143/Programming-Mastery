import matplotlib.pyplot as plt
from LotkaVolterra import LotkaVolterra
from ODE import Euler
from plot import plot


lv_model = LotkaVolterra()
states, t_values = Euler(lv_model, [10, 10], 0.001, 50000)

fig = plot(states, t_values)
plt.show()