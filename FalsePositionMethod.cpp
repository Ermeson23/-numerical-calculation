#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - (9*x) +3;
}

double falsePosition(double a, double b, double precision, double tolerance, int& iterations) {
    double x;

    if((b-a) < precision) {
        iterations++;
        return x = a;
    }
    else if(fabs(f(a)) < tolerance || fabs(f(b)) < tolerance) {
        iterations++;
        return x=b;
    }

    double average = f(a);

    x = (a*f(b) - b*f(a))/(f(b)-f(a));
    if(fabs(f(x)) < tolerance) {
        iterations++;
        return x;
    }
    if (average*f(x) > 0) {
        a = x;//o valor de x sobrescreve a, o qual se perde na memória
        average = f(x);
        if((b-a) < tolerance) {
            iterations++;
            return x=(a+b)/2;
        }
    }
    else {
        b=x;
        return falsePosition(a, b, precision, tolerance, ++iterations);
    }
}

int main() {
    int iterations = 0;
    cout << "Raiz: " << falsePosition(0, 1, 0.0005, 0.0005, iterations) << endl;
    cout << "Iteracoes: " << iterations << endl;
    return 0;
}
