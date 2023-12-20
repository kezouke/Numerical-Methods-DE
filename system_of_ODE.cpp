#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y, double t) {
    return y;
}

double g(double x, double y, double t) {
    return sin(x);
}

void eulerMethodApproximation(vector<double>& t,
                              vector<double>& x,
                              vector<double>& y,
                              int n, double t0,
                              double x0,
                              double y0,
                              double step) {
    t.push_back(t0);
    x.push_back(x0);
    y.push_back(y0);

    for (int i = 1; i < n; ++i) {
        t.push_back(t[i-1] + step);
        x.push_back(x[i-1] + step * f(x[i-1], y[i-1], t[i-1]));
        y.push_back(y[i-1] + step * g(x[i-1], y[i-1], t[i-1]));
    }
}

void improvedEulerMethodApproximation(vector<double>& t,
                                      vector<double>& x,
                                      vector<double>& y,
                                      int n,
                                      double t0,
                                      double x0,
                                      double y0,
                                      double step) {
    t.push_back(t0);
    x.push_back(x0);
    y.push_back(y0);

    for (int i = 1; i < n; ++i) {
        t.push_back(t[i-1] + step);
        double k1x = step * f(x[i-1], y[i-1], t[i-1]);
        double k1y = step * g(x[i-1], y[i-1], t[i-1]);
        double k2x = step * f(x[i-1] + k1x, y[i-1] + k1y, t[i-1] + step);
        double k2y = step * g(x[i-1] + k1x, y[i-1] + k1y, t[i-1] + step);
        x.push_back(x[i-1] + 0.5 * (k1x + k2x));
        y.push_back(y[i-1] + 0.5 * (k1y + k2y));
    }
}

void rungeKuttaMethodApproximation(vector<double>& t,
                                   vector<double>& x,
                                   vector<double>& y,
                                   int n,
                                   double t0,
                                   double x0,
                                   double y0,
                                   double step) {
    t.push_back(t0);
    x.push_back(x0);
    y.push_back(y0);

    for (int i = 1; i < n; ++i) {
        t.push_back(t[i-1] + step);
        double k1x = step * f(x[i-1], y[i-1], t[i-1]);
        double k1y = step * g(x[i-1], y[i-1], t[i-1]);
        double k2x = step * f(x[i-1] + 0.5 * k1x, y[i-1] + 0.5 * k1y, t[i-1] + 0.5 * step);
        double k2y = step * g(x[i-1] + 0.5 * k1x, y[i-1] + 0.5 * k1y, t[i-1] + 0.5 * step);
        double k3x = step * f(x[i-1] + 0.5 * k2x, y[i-1] + 0.5 * k2y, t[i-1] + 0.5 * step);
        double k3y = step * g(x[i-1] + 0.5 * k2x, y[i-1] + 0.5 * k2y, t[i-1] + 0.5 * step);
        double k4x = step * f(x[i-1] + k3x, y[i-1] + k3y, t[i-1] + step);
        double k4y = step * g(x[i-1] + k3x, y[i-1] + k3y, t[i-1] + step);

        x.push_back(x[i-1] + (k1x + 2 * k2x + 2 * k3x + k4x) / 6);
        y.push_back(y[i-1] + (k1y + 2 * k2y + 2 * k3y + k4y) / 6);
    }
}

int main() {
    // Hardcoded task parameters
    double t0 = 0.0;
    double x0 = 10;
    double y0 = M_PI;
    double start_range_t = 0.0;
    double b = 3 * M_PI;  // π
    int n;


    // Read the number of grid points
    cin >> n;

    // Read the task number
    int task;
    cin >> task;

    vector<double> t, x, y;
    double step = (b - start_range_t) / (n - 1);

    switch (task) {
        case 1: // Euler's solution
            eulerMethodApproximation(t, x, y, n, t0, x0, y0, step);
            break;

        case 2: // Improved Euler's solution
            improvedEulerMethodApproximation(t, x, y, n, t0, x0, y0, step);
            break;

        case 3: // Runge-Kutta solution
            rungeKuttaMethodApproximation(t, x, y, n, t0, x0, y0, step);
            break;

        default:
            cout << "Invalid task number." << endl;
            return 1;
    }

    cout << "ti=" << endl;
    for (double time : t) {
        cout << fixed << setprecision(5) << time << " ";
    }

    switch (task) {
        case 1: // Euler's solution
            cout << "\nEuler_xi=" << endl;
            for (double val : x) {
                cout << fixed << setprecision(5) << val << " ";
            }
            cout << "\nEuler_yi=" << endl;
            for (double val : y) {
                cout << fixed << setprecision(5) << val << " ";
            }
            break;

        case 2: // Improved Euler's solution
            cout << "\niEuler_xi=" << endl;
            for (double val : x) {
                cout << fixed << setprecision(5) << val << " ";
            }
            cout << "\niEuler_yi=" << endl;
            for (double val : y) {
                cout << fixed << setprecision(5) << val << " ";
            }
            break;

        case 3: // Runge-Kutta solution
            cout << "\nRK4_xi=" << endl;
            for (double val : x) {
                cout << fixed << setprecision(5) << val << " ";
            }
            cout << "\nRK4_yi=" << endl;
            for (double val : y) {
                cout << fixed << setprecision(5) << val << " ";
            }
            break;

        default:
            cout << "Invalid task number." << endl;
            break;
    }

    cout << endl;

    return 0;
}


