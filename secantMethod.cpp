#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return (x*x*x) - (9*x) + 3;
}

void secantMethod(double x0, double x1, double precision, double precision2, int max_iterations) {
    if(abs(f(x0)) < precision) {
        cout << "Raiz: " << x0 << " primeira interacao." << endl;
        return;
    }

    if(abs(f(x1)) < precision || (abs(x1 -x0)) < precision2) {
        cout << "Raiz: " << x1 << " primeira interacao." << endl;
        return;
    }

    int k=1;

    while(k < max_iterations ) {
        double x2 = x1 - ((f(x1)/ (f(x1) - f(x0)))*(x1 - x0));
        if(abs(f(x2)) < precision || abs(x2-x1) < precision2) {
            cout << "Raiz: " << x2 << " na " << k << " interacao." << endl;
            return;
        }

        x0 = x1;
        x1 = x2;
        k++;
    }

    cout << "O metodo nao convergiu apos " << k << " interacoes." <<endl;
}

int main() {
    double x0=0, x1=1, precision=0.0005, precision2=0.0005;
    int max_iterations=10;
    secantMethod(x0, x1, precision, precision2, max_iterations);
}