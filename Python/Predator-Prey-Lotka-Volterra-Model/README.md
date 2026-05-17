# Predator-Prey Lotka-Volterra Model

The famous Predator-Prey model, also know as the Lotka-Volterra model, is a simplified dynamic simulation of a biological system. This simple system contains only 2 species, know as predator and prey. The population of each group depnds on the other. This relation is described mathematicaly as below:

$$\frac{dx}{dt} = \alpha x - \beta xy$$
$$\frac{dy}{dt} = - \gamma x + \delta xy$$

where $x$ and $y$ represent preys and predetors population respectively. Parameters $\alpha$, $\beta$, $\delta$, and $\gamma$ are positve constants.

Write a program to plot the population of two groups over time. To solve the ODEs, you could use RK4, Euler, Huen, or any other methods available.