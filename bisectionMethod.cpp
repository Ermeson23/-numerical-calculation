#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 5 * x - 9;
}

double bissecao(double a, double b, double tol, int max_iterations) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iterations = 0;
    while (iterations < max_iterations) {
        c = (a + b) / 2;
        fc = f(c);
        if (fabs(fc) < tol) {
            return c;
        }
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
        iterations++;
    }
    cout << "O método da bisseção não convergiu após " << max_iterations << " iterações." << endl;
    return c;
}

int main() {
    cout << bissecao(2, 3, 1e-5, 100) << endl;
    return 0;
}

