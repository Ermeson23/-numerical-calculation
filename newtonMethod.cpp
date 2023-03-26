#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return x*x*x -9*x + 3;
}

double f_linha(double x){//Derivada da função
    return (3*(x*x)) - 9;
}

void newton(double x0, double precision, int max_iterations){
    int iterations = 0;
    double x = x0;
    while(iterations < max_iterations){
        double fx = f(x);
        if (abs(fx) <= precision) {
            cout << "A raiz e: " << x << " com " <<iterations << endl;
            return;
        }
        double f_linhaX = f_linha(x);
        double x_old = x;
        x = x_old - (fx / f_linhaX);
        iterations++;
        if(abs(x - x_old) < precision){
            cout << "A raiz e: " << x << endl;
            return;
        }
    }
    cout << "O metodo de Newton não convergiu apos " << max_iterations << " iteracoes" << endl;
}

int main(){
    double x0=0.5, precision=0.0001;
    int max_iterations=4;
    newton(x0, precision, max_iterations);
    return 0;
}

