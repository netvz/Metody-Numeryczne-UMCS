#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Funkcja do obliczania normy Frobeniusa
double frobeniusNorm(const vector<vector<double>>& matrix) {
    double sum = 0.0;
    for (const auto& row : matrix) {
        for (double element : row) {
            sum += element * element;
        }
    }
    return sqrt(sum);
}

// Funkcja do obliczania normy Manhattan
double manhattanNorm(const vector<vector<double>>& matrix) {
    double sum = 0.0;
    for (const auto& row : matrix) {
        for (double element : row) {
            sum += abs(element);
        }
    }
    return sum;
}

// Funkcja do obliczania normy maksymalnej
double maxNorm(const vector<vector<double>>& matrix) {
    double maxElement = 0.0;
    for (const auto& row : matrix) {
        for (double element : row) {
            if (abs(element) > maxElement) {
                maxElement = abs(element);
            }
        }
    }
    return maxElement;
}

int main() {
    // Przykładowa macierz 3x3
    vector<vector<double>> matrix = {{1.0, 2.0, 3.0},
                                      {4.0, 5.0, 6.0},
                                      {7.0, 8.0, 9.0}};

    // Obliczanie norm
    double frobenius = frobeniusNorm(matrix);
    double manhattan = manhattanNorm(matrix);
    double max = maxNorm(matrix);

    // Wyświetlanie wyników
    cout << "Norma Frobeniusa: " << frobenius << endl;
    cout << "Norma Manhattan: " << manhattan << endl;
    cout << "Norma maksymalna: " << max << endl;

    return 0;
}
