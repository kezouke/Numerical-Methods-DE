#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double f(double x, double y) {
    return cos(x);
}

// Analytical solution
double g(double x, double x0, double y0) {
    return sin(x);
}

double eulerMethodApproximation(double x, double y, double h) {
    return y + h * f(x, y);
}

double improvedEulerMethodApproximation(double x, double y, double h) {
    double K1 = f(x, y);
    double K2 = f(x + h, y + h * K1);
    return y + h / 2 * (K1 + K2);
}

double rungeKuttaMethodApproximation(double x, double y, double h) {
    double K1 = f(x, y);
    double K2 = f(x + h / 2, y + h / 2 * K1);
    double K3 = f(x + h / 2, y + h / 2 * K2);
    double K4 = f(x + h, y + h * K3);
    return y + h / 6 * (K1 + 2 * K2 + 2 * K3 + K4);
}

int main() {
    // Hardcoded task parameters
    double x0 = 0.0;
    double y0 = 0.0;
    double interval_start = 0.0;
    double b = M_PI; // end of the interval
    int n1, n2, n;
    int task;

    cin >> n >> n1 >> n2 >> task;

    // Step size
    double h = (b - interval_start) / (n - 1);

    vector<double> xi, yi, localErrors;

    switch (task) {
        case 1: // Exact solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                yi.push_back(g(x, x0, y0));
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\ny(xi)=" << endl;
            for (double y: yi) {
                cout << fixed << setprecision(5) << y << " ";
            }
            cout << endl;
            break;

        case 2: // Euler's solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0); // Initial condition
                } else {
                    yi.push_back(eulerMethodApproximation(xi[i - 1], yi[i - 1], h));
                }
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\nEuler_yi=" << endl;
            for (double y: yi) {
                cout << fixed << setprecision(5) << y << " ";
            }
            cout << endl;
            break;

        case 3: // Improved Euler's solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0);
                } else {
                    yi.push_back(improvedEulerMethodApproximation(xi[i - 1], yi[i - 1], h));
                }
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\niEuler_yi=" << endl;
            for (double y: yi) {
                cout << fixed << setprecision(5) << y << " ";
            }
            cout << endl;
            break;

        case 4: // Runge-Kutta solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0);
                } else {
                    yi.push_back(rungeKuttaMethodApproximation(xi[i - 1], yi[i - 1], h));
                }
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\nRK4_yi=" << endl;
            for (double y: yi) {
                cout << fixed << setprecision(5) << y << " ";
            }
            cout << endl;
            break;

        case 5: // Local errors of Euler's solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0);
                } else {
                    yi.push_back(eulerMethodApproximation(xi[i - 1], yi[i - 1], h));
                }
                localErrors.push_back(fabs(yi[i] - g(x, x0, y0)));
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\nEuler_LE(xi)=" << endl;
            for (double error: localErrors) {
                cout << fixed << setprecision(5) << error << " ";
            }
            cout << endl;
            break;

        case 6: // Local errors of Improved Euler's solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0);
                    localErrors.push_back(y0);
                } else {
                    double improvedEulerValue = improvedEulerMethodApproximation(xi[i - 1], yi[i - 1], h);
                    yi.push_back(improvedEulerValue);
                    localErrors.push_back(fabs(improvedEulerValue - g(x, x0, y0)));
                }
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\niEuler_LE(xi)=" << endl;
            for (double error: localErrors) {
                cout << fixed << setprecision(5) << error << " ";
            }
            cout << endl;
            break;

        case 7: // Local errors of Runge-Kutta solution
            for (int i = 0; i < n; ++i) {
                double x = x0 + i * h;
                xi.push_back(x);
                if (i == 0) {
                    yi.push_back(y0);
                    localErrors.push_back(y0);
                } else {
                    double rungeKuttaValue = rungeKuttaMethodApproximation(xi[i - 1], yi[i - 1], h);
                    yi.push_back(rungeKuttaValue);
                    localErrors.push_back(fabs(rungeKuttaValue - g(x, x0, y0)));
                }
            }
            cout << "xi=" << endl;
            for (double x: xi) {
                cout << fixed << setprecision(5) << x << " ";
            }
            cout << "\nRK4_LE(xi)=" << endl;
            for (double error: localErrors) {
                cout << fixed << setprecision(5) << error << " ";
            }
            cout << endl;
            break;

        case 8: // Global errors of Euler's solution
            cout << "ni=" << endl;
            for (int i = n1; i <= n2; ++i) {
                cout << i << " ";
            }
            cout << "\nEuler_GE(n)=" << endl;

            for (int nPoints = n1; nPoints <= n2; ++nPoints) {
                double globalError = 0.0;
                double currentH = (b - x0) / (nPoints - 1);

                xi.clear();
                yi.clear();
                localErrors.clear();

                for (int i = 0; i <= nPoints; ++i) {
                    double x = x0 + i * currentH;
                    xi.push_back(x);
                    if (i == 0) {
                        yi.push_back(y0);
                    } else {
                        yi.push_back(eulerMethodApproximation(xi[i - 1], yi[i - 1], currentH));
                    }
                    localErrors.push_back(fabs(yi[i] - g(x, x0, y0)));
                }

                for (int j = 0; j <= nPoints; ++j) {
                    globalError = max(globalError, localErrors[j]);
                }

                cout << fixed << setprecision(5) << globalError << " ";
            }
            cout << endl;
            break;

        case 9: // Global errors of Improved Euler's solution
            cout << "ni=" << endl;
            for (int i = n1; i <= n2; ++i) {
                cout << i << " ";
            }
            cout << "\niEuler_GE(n)=" << endl;

            for (int nPoints = n1; nPoints <= n2; ++nPoints) {
                double globalError = 0.0;
                double currentH = (b - x0) / (nPoints - 1);

                xi.clear();
                yi.clear();
                localErrors.clear();

                for (int i = 0; i <= nPoints; ++i) {
                    double x = x0 + i * currentH;
                    xi.push_back(x);
                    if (i == 0) {
                        yi.push_back(y0);
                    } else {
                        yi.push_back(improvedEulerMethodApproximation(xi[i - 1], yi[i - 1], currentH));
                    }
                    localErrors.push_back(fabs(yi[i] - g(x, x0, y0)));
                }

                for (int j = 0; j <= nPoints; ++j) {
                    globalError = max(globalError, localErrors[j]);
                }

                cout << fixed << setprecision(5) << globalError << " ";
            }
            cout << endl;
            break;

        case 10: // Global errors of Runge-Kutta solution
            cout << "ni=" << endl;
            for (int i = n1; i <= n2; ++i) {
                cout << i << " ";
            }
            cout << "\nRK4_GE(n)=" << endl;

            for (int nPoints = n1; nPoints <= n2; ++nPoints) {
                double globalError = 0.0;
                double currentH = (b - x0) / (nPoints - 1);

                xi.clear();
                yi.clear();
                localErrors.clear();

                for (int i = 0; i <= nPoints; ++i) {
                    double x = x0 + i * currentH;
                    xi.push_back(x);
                    if (i == 0) {
                        yi.push_back(y0);
                    } else {
                        yi.push_back(rungeKuttaMethodApproximation(xi[i - 1], yi[i - 1], currentH));
                    }
                    localErrors.push_back(fabs(yi[i] - g(x, x0, y0)));
                }

                for (int j = 0; j <= nPoints; ++j) {
                    globalError = max(globalError, localErrors[j]);
                }

                cout << fixed << setprecision(5) << globalError << " ";
            }
            cout << endl;
            break;

        default:
            cout << "Invalid task number." << endl;
            break;
    }

    return 0;
}
