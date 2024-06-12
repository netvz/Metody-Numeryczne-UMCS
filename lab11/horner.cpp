#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

void horner(const vector<complex<double>>& coefficients, complex<double> x, 
            complex<double>& poly_val, complex<double>& first_derivative, complex<double>& second_derivative) {
    size_t n = coefficients.size() - 1;
    poly_val = coefficients[0];
    first_derivative = 0.0;
    second_derivative = 0.0;
    
    for (size_t i = 1; i <= n; ++i) {
        second_derivative = second_derivative * x + 2.0 * first_derivative;
        first_derivative = first_derivative * x + poly_val;
        poly_val = poly_val * x + coefficients[i];
    }
}

complex<double> laguerre(const vector<complex<double>>& coefficients, complex<double> x, int max_iter = 100, double tol = 1e-9) {
    size_t n = coefficients.size() - 1;
    complex<double> poly_val, first_derivative, second_derivative;

    for (int i = 0; i < max_iter; ++i) {
        horner(coefficients, x, poly_val, first_derivative, second_derivative);

        if (abs(poly_val) < tol) {
            return x;
        }

        complex<double> G = first_derivative / poly_val;
        complex<double> H = G * G - second_derivative / poly_val;
        complex<double> denom1 = G + sqrt(complex<double>((n - 1) * (n * real(H) - real(G * G))));
        complex<double> denom2 = G - sqrt(complex<double>((n - 1) * (n * real(H) - real(G * G))));
        complex<double> denom = abs(denom1) > abs(denom2) ? denom1 : denom2;
        complex<double> a = complex<double>(n) / denom;
        x -= a;

        if (abs(a) < tol) {
            return x;
        }
    }

    return x;
}

int main() {
    vector<complex<double>> coefficients_a = {1, -6, 11, -6}; 
    vector<complex<double>> coefficients_b = {1, -6, 11, -1}; 

    double real_part, imag_part;
    cout << "podaj cz. rzeczywistą: ";
    cin >> real_part;
    cout << "podaj cz. urojoną: ";
    cin >> imag_part;
    
    complex<double> x(real_part, imag_part);

    complex<double> root_a = laguerre(coefficients_a, x);
    complex<double> root_b = laguerre(coefficients_b, x);

    cout << "pierwiastek a): " << root_a << endl;
    cout << "pierwiastek b): " << root_b << endl;

    return 0;
}
