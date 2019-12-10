import numpy as np
import matplotlib.pyplot as plt

# Writing x and y starting points
x_points = np.array([0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1])
y_points = np.array([0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1])
# Create a mesh with 1000 points from min(x)-0.05|min(x)| to max(x)+0.05|max(x)|
x = np.linspace(0, 1.05, 1000)

y=0.000000*(x**(2))+1.000000*x+0.000000

plt.plot(x_points, y_points, color="red", marker="+", linestyle="", label="Data points")
plt.plot(x, y, color="blue", linewidth=2.5, linestyle="-", label="src/PythonFiles/Data_Fitting_with_degree_2.py")
# Adding legends
plt.legend()

plt.show() # show figure