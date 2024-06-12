#include <iostream>
#include <cmath>

using namespace std;

double f1(double x) {
    return 2 * pow(x, 2) + 2;
}

double f2(double x) {
    return 2 * pow(x, 4) - pow(x, 2) + 3 * x - 7;
}

double f3(double x) {
    return pow(x, 2) * exp(x);
}

double derivative_backward(double (*f)(double), double x, double h) {
    double df = (f(x) - f(x - h)) / h;
    return df;
}

double derivative_central(double (*f)(double), double x, double h) {
    double df = (f(x + h) - f(x - h)) / (2 * h);
    return df;
}

int main() {
    double h_values[] = {pow(10, -2), pow(10, -4)};
    double x = 3; 

    for (auto func : {f1, f2, f3}) {
        cout << "Funkcja: " << (func == f1 ? "f1" : (func == f2 ? "f2" : "f3")) << endl;
        for (double h : h_values) {
            double df_backward = derivative_backward(func, x, h);
            double df_central = derivative_central(func, x, h);

            double exact_derivative;
            if (func == f1)
                exact_derivative = 4.0; 
            else if (func == f2)
                exact_derivative = 8 * pow(x, 3) - 2 * x + 3; 
            else if (func == f3)
                exact_derivative = (2 * exp(x) + x * x * exp(x)); 

            double relative_error_backward = fabs((df_backward - exact_derivative) / exact_derivative);
            double relative_error_central = fabs((df_central - exact_derivative) / exact_derivative);

            cout << " h = " << h << ": Pochodna (wsteczna) = " << df_backward << ", Błąd = " << relative_error_backward << endl;
            cout << " h = " << h << ": Pochodna (centralna) = " << df_central << ", Błąd = " << relative_error_central << endl;
        }
    }

    return 0;
}
