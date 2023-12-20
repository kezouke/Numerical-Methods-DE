# Numerical Methods for Ordinary Differential Equations

This repository contains C++ programs that implement and analyze numerical methods for solving first-order ordinary differential equations (ODEs) and systems of ODEs.

## File 1: first_order_ODE.cpp

### Task Description:

**Objective:**
Implement and analyze numerical methods for solving a system of first-order ordinary differential equations (ODEs) of the form:

\[ y' = f(x, y) \]

with the initial condition \( y(x_0) = y_0 \) on the interval \([x_0, b]\). Perform the analysis of approximations using Euler's method, Improved Euler's method, and the Runge-Kutta method.

**Implementation Guidelines:**

1. **Numerical Methods:**
   - Implement Euler's method: \( y_{i+1} = y_i + h \cdot f(x_i, y_i) \)
   - Implement Improved Euler's method: \( y_{i+1} = y_i + h/2 \cdot (K_{1i} + K_{2i}) \)
   - Implement Runge-Kutta method: \( y_{i+1} = y_i + h/6 \cdot (K_{1i} + 2K_{2i} + 2K_{3i} + K_{4i}) \)

2. **Hardcoded Parameters:**
   - Hardcode the right-hand side function \( f(x, y) \).
   - Hardcode initial conditions \( x_0 \) and \( y_0 \).

3. **Analytical Solution:**
   - Manually solve the equation and hardcode the analytical solution function \( g(x, x_0, y_0) \).

4. **Error Analysis:**
   - For each numerical method, compute local errors \( LE(x_i) = |y_i - g(x_i)| \) for a given number of grid points \( n \).
   - Compute global errors \( GE_n = \max(LE_i) \) for various values of \( n \) within the range \( [n_1, n_2] \).

5. **Output Formatting:**
   - Implement functionality to print arrays to the console.
   - Format output as specified:
     - First line: Title of the array (e.g., "xi=").
     - Second line: Values stored in the array, formatted as "%.f5" and separated by spaces.
     - No space after the last item, with "\n" at the end of the line.
     - Use a dot (.) as the decimal separator.

**Test Example:**
Consider the system \( y' = \cos(x) \), \( y(0) = 0 \) on the interval \([0, \pi]\). Read the number of grid points \( n \) and the range parameters \( n_1 \) and \( n_2 \) for global error analysis from the console.

**Task Selection:**
- Task 1: Print the exact solution.
- Task 2: Print Euler's solution.
- Task 3: Print Improved Euler's solution.
- Task 4: Print Runge-Kutta solution.
- Task 5: Print local errors of Euler's solution.
- Task 6: Print local errors of Improved Euler's solution.
- Task 7: Print local errors of Runge-Kutta solution.
- Task 8: Print global errors of Euler's solution.
- Task 9: Print global errors of Improved Euler's solution.
- Task 10: Print global errors of Runge-Kutta solution.

## File 2: system_of_ODE.cpp

### Task Description:

**Objective:**
Implement and analyze numerical methods for solving a system of coupled first-order ordinary differential equations (ODEs) given by:

\[ x' = f(x, y, t) \]
\[ y' = g(x, y, t) \]

with the initial conditions \( x(t_0) = x_0 \) and \( y(t_0) = y_0 \) on the interval \([t_0, b]\). Implement Euler's method, Improved Euler's method, and the Runge-Kutta method as described in the tutorial.

**Implementation Guidelines:**

1. **Numerical Methods:**
   - Implement Euler's method: \( x_{i+1} = x_i + h \cdot f(x_i, y_i, t_i) \), \( y_{i+1} = y_i + h \cdot g(x_i, y_i, t_i) \)
   - Implement Improved Euler's method: \( x_{i+1} = x_i + h/2 \cdot (K_{1i} + K_{2i}) \), \( y_{i+1} = y_i + h/2 \cdot (L_{1i} + L_{2i}) \)
   - Implement Runge-Kutta method: \( x_{i+1} = x_i + h/6 \cdot (K_{1i} + 2K_{2i} + 2K_{3i} + K_{4i}) \), \( y_{i+1} = y_i + h/6 \cdot (L_{1i} + 2L_{2i} + 2L_{3i} + L_{4i}) \)

2. **Hardcoded Parameters:**
   - Hardcode the functions \( f(x, y, t) \) and \( g(x, y, t) \).
   - Hardcode initial conditions \( t_0, x_0, y_0 \).

3. **Test Example:**
   Consider the system:
   \[ x' = y \]
   \[ y' = -4x \]
   on the interval \([0, \pi]\) with initial conditions \( x_0 = 1 \) and \( y_0 = 2 \).

4. **Output Formatting:**
   - Implement functionality to print arrays to the console.
   - Format output as specified:
     - First line: Title of the array (e.g., "ti=").
     - Second line: Values stored in the array, formatted as "%.f5" and separated by spaces.
     - No space after the last item, with "\n" at the end of the line.
     - Use a dot (.) as the decimal separator.

**Concrete Task:**
- Read the number of grid points \( n \).
- Read the task number.

**Task Selection:**
- Task 1: Print Euler's solution (1 pt)
  - Print array of t-points with the title "ti=".
  - Print array of Euler's x-points with the title "Euler_xi=".
  - Print array of Euler's y-points with the title "Euler_yi=".

- Task 2: Print Improved Euler's solution (1 pt)
  - Print array of t-points with the title "ti=".
  - Print array of Improved Euler's x-points with the title "iEuler_xi=".
  - Print array of Improved Euler's y-points with the title "iEuler_yi=".

- Task 3:

 Print Runge-Kutta solution (2 pts)
  - Print array of t-points with the title "ti=".
  - Print array of RK4 x-points with the title "RK4_xi=".
  - Print array of RK4 y-points with the title "RK4_yi=".
