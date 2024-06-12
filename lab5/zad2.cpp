#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Funkcja licząca normę wektora (norma euklidesowa)
double vectorNorm(const vector<double>& vec) {
    double sum = 0;
    for (double val : vec) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Funkcja implementująca metodę Gaussa-Seidla
vector<double> gaussSeidelMethod(const vector<vector<double>>& A, const vector<double>& b, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> x(n, 0); // Wektor rozwiązania
    vector<double> xOld(n, 0); // Wektor poprzedniego rozwiązania

    for (int iter = 0; iter < maxIterations; iter++) {
        xOld = x; // Zachowanie poprzednich przybliżeń

        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Obliczenie normy różnicy między kolejnymi przybliżeniami
        vector<double> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = x[i] - xOld[i];
        }
        double norm = vectorNorm(diff);

        // Warunek zatrzymania
        if (norm < tolerance) {
            cout << "Metoda Gaussa-Seidla zakończona po " << iter + 1 << " iteracjach." << endl;
            break;
        }
    }
    return x;
}

int main() {
    // Macierz współczynników A
    vector<vector<double>> A = {
        {4, -2, 0, 0},
        {-2, 5, -1, 0},
        {0, -1, 4, 2},
        {0, 0, 2, 3}
    };

    // Wektor wyrazów wolnych b
    vector<double> b = {0, 2, 3, -2};

    // Parametry dla metody Gaussa-Seidla
    int maxIterations = 1000; // Maksymalna liczba iteracji
    double tolerance = 1e-6; // Tolerancja dla normy różnicy

    // Rozwiązanie układu równań
    vector<double> solution = gaussSeidelMethod(A, b, maxIterations, tolerance);

    // Wyświetlenie rozwiązania
    cout << fixed << setprecision(6);
    cout << "Rozwiązanie układu równań:" << endl;
    for (int i = 0; i < solution.size(); i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
