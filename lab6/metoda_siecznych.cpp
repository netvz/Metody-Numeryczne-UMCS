#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x) {
    return pow(x, 2) - 4;
}

double sieczne(double x0, double x1, double epsilon, int max_iter) {
    double x_i = x0;
    double x_i_minus_1 = x1;
    double fx_i = funkcja(x_i);
    double fx_i_minus_1 = funkcja(x_i_minus_1);
    
    int iter = 0;
    while (fabs(fx_i) > epsilon && iter < max_iter) {
        double temp = x_i;
        x_i = x_i - (fx_i * (x_i_minus_1 - x_i) / (fx_i_minus_1 - fx_i));
        x_i_minus_1 = temp;
        fx_i = funkcja(x_i);
        fx_i_minus_1 = funkcja(x_i_minus_1);
        iter++;
    }
    
    if (fabs(fx_i) <= epsilon) {
        cout << "wynik: " << x_i << endl;
        return x_i;
    } else {
        cout << "niepowodzenie" << endl;
        return NAN;
    }
}

int main() {
    double x0 = 1.0; 
    double x1 = 2.0; 
    double epsilon = 0.0001; 
    int max_iter = 1000; 

    sieczne(x0, x1, epsilon, max_iter);

    return 0;
}
