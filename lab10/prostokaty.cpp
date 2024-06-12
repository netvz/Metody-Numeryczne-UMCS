#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double metodaProstokatow(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;  
    double suma = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;  
        suma += f(x);
    }

    return suma * h;
}

double bladWzgledny(double wartoscDokladna, double wartoscPrzyblizona) {
    return fabs((wartoscDokladna - wartoscPrzyblizona) / wartoscDokladna);
}

int main() {
    int n = 100; 

    auto f1 = [](double x) { return x * x; };
    double a1 = 0.0, b1 = 1.0;
    double dokladna1 = 1.0 / 3.0;
    double przyblizona1 = metodaProstokatow(f1, a1, b1, n);
    double blad1 = bladWzgledny(dokladna1, przyblizona1);

    auto f2 = [](double x) { return cos(x); };
    double a2 = 0.0, b2 = M_PI / 2;
    double dokladna2 = 1.0;
    double przyblizona2 = metodaProstokatow(f2, a2, b2, n);
    double blad2 = bladWzgledny(dokladna2, przyblizona2);

    auto f3 = [](double x) { return 1.0 / x; };
    double a3 = M_E, b3 = exp(2.0);
    double dokladna3 = 1.0;
    double przyblizona3 = metodaProstokatow(f3, a3, b3, n);
    double blad3 = bladWzgledny(dokladna3, przyblizona3);

    cout << "1: " << przyblizona1 << ", błąd " << blad1 << endl;
    cout << "2: " << przyblizona2 << ", błąd " << blad2 << endl;
    cout << "3: " << przyblizona3 << ", błąd " << blad3 << endl;

    return 0;
}
