#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Funkcja do rozkładu LU
bool luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Inicjalizacja macierzy L i U
    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        // Górna macierz U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Dolna macierz L
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1; // Ustawienie elementów diagonalnych na 1
            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return true;
}

// Funkcja do rozwiązania układu równań po rozkładzie LU
vector<double> solveLU(const vector<vector<double>>& L, const vector<vector<double>>& U, const vector<double>& B) {
    int n = B.size();
    vector<double> Y(n, 0);
    vector<double> X(n, 0);

    // Rozwiązanie L * Y = B
    for (int i = 0; i < n; i++) {
        Y[i] = B[i];
        for (int j = 0; j < i; j++) {
            Y[i] -= L[i][j] * Y[j];
        }
        Y[i] /= L[i][i];
    }

    // Rozwiązanie U * X = Y
    for (int i = n - 1; i >= 0; i--) {
        X[i] = Y[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= U[i][j] * X[j];
        }
        X[i] /= U[i][i];
    }

    return X;
}

// Funkcja do eliminacji Gaussa
vector<double> gaussElimination(vector<vector<double>> A, vector<double> B) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        // Szukamy maksymalnego elementu w kolumnie
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Zamieniamy maksymalny wiersz z bieżącym
        for (int k = i; k < n; k++) {
            swap(A[maxRow][k], A[i][k]);
        }
        swap(B[maxRow], B[i]);

        // Zerowanie kolumny poniżej aktualnego wiersza
        for (int k = i + 1; k < n; k++) {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
            B[k] += c * B[i];
        }
    }

    // Rozwiązanie
    vector<double> X(n);
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            B[k] -= A[k][i] * X[i];
        }
    }
    return X;
}

int main() {
    // Macierz współczynników z zadania 1
    vector<vector<double>> A = {
        {1, 2, 1},
        {3, -7, 2},
        {2, 4, 5}
    };

    // Wektor wyrazów wolnych z zadania 1
    vector<double> B = {-9, 61, -9};

    // Rozkład LU
    vector<vector<double>> L, U;

    // Pomiar czasu dla rozkładu LU
    auto start = high_resolution_clock::now();
    bool success = luDecomposition(A, L, U);
    auto stop = high_resolution_clock::now();
    auto durationLU = duration_cast<microseconds>(stop - start);
    
    // Rozwiązanie układu równań przy użyciu rozkładu LU
    start = high_resolution_clock::now();
    vector<double> solutionLU = solveLU(L, U, B);
    stop = high_resolution_clock::now();
    auto durationSolveLU = duration_cast<microseconds>(stop - start);

    // Wyświetlenie wyniku rozkładu LU
    cout << "Rozwiązanie układu równań za pomocą rozkładu LU:" << endl;
    for (int i = 0; i < solutionLU.size(); i++) {
        cout << "x" << i + 1 << " = " << solutionLU[i] << endl;
    }

    // Pomiar czasu dla eliminacji Gaussa
    start = high_resolution_clock::now();
    vector<double> solutionGauss = gaussElimination(A, B);
    stop = high_resolution_clock::now();
    auto durationGauss = duration_cast<microseconds>(stop - start);

    // Wyświetlenie wyniku eliminacji Gaussa
    cout << "\nRozwiązanie układu równań za pomocą eliminacji Gaussa:" << endl;
    for (int i = 0; i < solutionGauss.size(); i++) {
        cout << "x" << i + 1 << " = " << solutionGauss[i] << endl;
    }

    // Porównanie czasów
    cout << "\nCzas wykonania (rozkład LU): " << durationLU.count() << " mikrosekund" << endl;
    cout << "Czas wykonania (rozwiązanie LU): " << durationSolveLU.count() << " mikrosekund" << endl;
    cout << "Czas wykonania (eliminacja Gaussa): " << durationGauss.count() << " mikrosekund" << endl;

    return 0;
}
