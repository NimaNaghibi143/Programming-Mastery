import matplotlib.pyplot as plt
from LotkaVolterra import LotkaVolterra
from ODE import ODESolver
from plot import plot, plot_subplots_grid, plot_phase_space


lv_model = LotkaVolterra(alpha=1.1, beta=0.4, gamma=0.4, delta=0.1)
initial_state = [10, 10]
h = 0.01
N = 50000

results = {}
solver = ODESolver(lv_model, initial_state, h, N)
results['Euler'] = solver.Euler()
results['RK2'] = solver.RK2()
results['RK3'] = solver.RK3()
results['RK4'] = solver.RK4()

# Model comparison
fig, ax = plot_subplots_grid(results)
plt.show()

# Phase space
initial_conditions = [(5,5), (10,5), (15,10), (20,15), (8,20)]
fig, ax = plot_phase_space(lv_model, ODESolver, initial_conditions, h=0.01, N=50000)
plt.show()
