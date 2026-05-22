import matplotlib.pyplot as plt
import numpy as np
from aquarel import load_theme


# Using the Aquarel library with some customization for the plots
theme = load_theme("boxy_dark")
theme.set_color(figure_background_color="#181818",
                plot_background_color="#242424")
theme.set_font(family="serif", size=9)
theme.apply_transforms()
theme.apply()


def plot(states, t_values, model_name="Not Set"):
    fig, ax = plt.subplots()
    prey = states[:, 0]
    predators = states[:, 1]
    ax.plot(t_values, prey, label='Prey', linewidth=2)
    ax.plot(t_values, predators, label='Predators', linewidth=2)
    ax.set_xlabel('Time')
    ax.set_ylabel('Population')
    ax.set_title(f'Lotka-Volterra | {model_name}')
    ax.legend()
    ax.grid(True, alpha=0.3)
    
    return fig


def plot_subplots_grid(results_dict, rows=2, cols=2, figsize=(15, 10)):
    n_methods = len(results_dict)
    n_plots = min(n_methods, rows * cols) # Handle proper number of sections and avoid errors
    
    fig, axes = plt.subplots(rows, cols, figsize=figsize)
    axes = axes.flatten()  # This is done for easier indexing
    
    for idx, (method_name, (states, t_values)) in enumerate(list(results_dict.items())[:n_plots]):
        prey = states[:, 0]
        predators = states[:, 1]
        
        axes[idx].plot(t_values, prey, label='Prey', linewidth=1.5)
        axes[idx].plot(t_values, predators, label='Predators', linewidth=1.5)
        axes[idx].set_title(method_name)
        axes[idx].legend(loc='upper left', fontsize=8)
        axes[idx].grid(True, alpha=0.3)
        axes[idx].set_ylabel('Population')
        axes[idx].set_xlabel('Time')
    
    fig.suptitle('Numerical Methods Comparison', fontsize=14, fontweight='bold')
    plt.tight_layout()
    
    return fig, axes


def plot_phase_space(model, solver_class, initial_conditions, h=0.01, N=5000):
    fig , ax = plt.subplots(figsize=(6,6))
    
    colors = plt.cm.Paired(np.linspace(0, 1, len(initial_conditions)))
    
    for ic, color in zip(initial_conditions, colors):
        solver = solver_class(model, ic, h, N)
        states, _ = solver.RK4()
        
        ax.plot(states[:, 0], states[:, 1], color=color, label=f'IC: {ic}')
        ax.plot(states[0, 0], states[0, 1], 'o', color=color) # Starting point
    
    ax.set_xlabel('Prey Population')
    ax.set_ylabel('Predator Population')
    ax.set_ylim(bottom=-1)
    ax.set_xlim(left=-5)
    ax.set_title('Phase Space Portrait')
    ax.legend()
    ax.grid(True, alpha=0.3)
    plt.tight_layout()

    return fig, ax
