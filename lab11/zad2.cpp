#include <iostream>
#include <vector>
#include <complex>

using namespace std;

// Funkcja do obliczania wartości wielomianu w punkcie
complex<double> wartosc_wielomianu(const vector<complex<double>>& wsp, complex<double> x) {
    complex<double> wynik(0.0, 0.0);
    for (size_t i = 0; i < wsp.size(); ++i) {
        wynik += wsp[i] * pow(x, static_cast<int>(i));
    }
    return wynik;
}

// Funkcja do obliczania pierwszej pochodnej wielomianu
vector<complex<double>> pierwsza_pochodna(const vector<complex<double>>& wsp) {
    vector<complex<double>> pochodna;
    for (size_t i = 1; i < wsp.size(); ++i) {
        pochodna.push_back(wsp[i] * static_cast<double>(i));
    }
    return pochodna;
}

// Funkcja do obliczania drugiej pochodnej wielomianu
vector<complex<double>> druga_pochodna(const vector<complex<double>>& wsp) {
    vector<complex<double>> pochodna;
    for (size_t i = 2; i < wsp.size(); ++i) {
        pochodna.push_back(wsp[i] * static_cast<double>(i) * static_cast<double>(i - 1));
    }
    return pochodna;
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

    // Obliczanie pierwszej i drugiej pochodnej dla wielomianu a
    vector<complex<double>> pochodna1_a = pierwsza_pochodna(coefficients_a);
    vector<complex<double>> pochodna2_a = druga_pochodna(coefficients_a);

    // Obliczanie wartości pochodnych w punkcie x dla wielomianu a
    complex<double> wartosc_pochodnej1_a = wartosc_wielomianu(pochodna1_a, x);
    complex<double> wartosc_pochodnej2_a = wartosc_wielomianu(pochodna2_a, x);

    // Obliczanie pierwszej i drugiej pochodnej dla wielomianu b
    vector<complex<double>> pochodna1_b = pierwsza_pochodna(coefficients_b);
    vector<complex<double>> pochodna2_b = druga_pochodna(coefficients_b);

    // Obliczanie wartości pochodnych w punkcie x dla wielomianu b
    complex<double> wartosc_pochodnej1_b = wartosc_wielomianu(pochodna1_b, x);
    complex<double> wartosc_pochodnej2_b = wartosc_wielomianu(pochodna2_b, x);

    // Wyświetlanie wyników
    cout << "Wartość pierwszej pochodnej dla wielomianu a w punkcie " << x << " wynosi: " << wartosc_pochodnej1_a << endl;
    cout << "Wartość drugiej pochodnej dla wielomianu a w punkcie " << x << " wynosi: " << wartosc_pochodnej2_a << endl;

    cout << "Wartość pierwszej pochodnej dla wielomianu b w punkcie " << x << " wynosi: " << wartosc_pochodnej1_b << endl;
    cout << "Wartość drugiej pochodnej dla wielomianu b w punkcie " << x << " wynosi: " << wartosc_pochodnej2_b << endl;

    return 0;
}
