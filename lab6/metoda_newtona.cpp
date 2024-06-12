#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x) {
    return x*x - 4;
}

double pochodna(double x) {
    return 2*x;
}

double newton(double x0, double epsilon, int max_iter) {
    double xn = x0;
    int iter = 0;
    double err = fabs(funkcja(xn));

    while (err > epsilon && iter < max_iter) {
        xn = xn - funkcja(xn) / pochodna(xn);
        err = fabs(funkcja(xn));
        iter++;
    }

    cout << "iter: " << iter << endl;
    return xn;
}

int main() {
    double x0 = 1.5;
    int max_iter = 100; 
    double epsilon;

    cout << "podaj epsilon: " << endl;
    cin >> epsilon;
     
    double rozwiazanie = newton(x0, epsilon, max_iter);

    cout << "wynik: " << rozwiazanie << endl;

    return 0;
}
