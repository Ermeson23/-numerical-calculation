#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return (x*x*x) - 9*x + 3;
}

double g(double x){
    return ((pow(x,3))/9) + (1/3) ;
}

void ponto_fixo(double x0, double precision, double precision2, int max_iterations){
    int k=0;
    if(abs(f(x0)) < precision) {
        cout << "A raiz e: " << x0 <<endl;
        return;
    }

    while ( k < max_iterations )
    {
        double x1=g(x0);
        if(abs(f(x1)) < precision || (abs(x1-x0)) < precision2) {
            cout << "A raiz e: " << x1 << endl;
            return;
        }

        x0 = x1;
        k++;   
    }
}

int main(){
    double x0=0.5, precision=0.0005, precision2=0.0005;
    int max_iterations=100;
    ponto_fixo(x0, precision, precision2, max_iterations);
    return 0;
}