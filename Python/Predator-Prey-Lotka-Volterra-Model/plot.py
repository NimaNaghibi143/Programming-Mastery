import matplotlib.pyplot as plt
from aquarel import load_theme


# Using the Aquarel library with some customization for the plots
theme = load_theme("boxy_dark")
theme.set_color(figure_background_color="#181818",
                plot_background_color="#242424")
theme.set_font(family="serif", size=9)
theme.apply_transforms()
theme.apply()


def plot(states, t_values):
    fig, ax = plt.subplots()
    prey = states[:, 0]
    predators = states[:, 1]
    ax.plot(t_values, prey, label='Prey', linewidth=2)
    ax.plot(t_values, predators, label='Predators', linewidth=2)
    ax.set_xlabel('Time')
    ax.set_ylabel('Population')
    ax.set_title('Lotka-Volterra Predator-Prey Model')
    ax.legend()
    ax.grid(True, alpha=0.3)
    
    return fig