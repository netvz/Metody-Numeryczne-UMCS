#include <iostream>
#include <vector>

using namespace std;

// Funkcja wykonuje eliminację Gaussa
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
    // Macierz współczynników
    vector<vector<double>> A = {
        {1, 2, 1},
        {3, -7, 2},
        {2, 4, 5}
    };

    // Wektor wyrazów wolnych
    vector<double> B = {-9, 61, -9};

    // Rozwiązanie układu równań
    vector<double> solution = gaussElimination(A, B);

    // Wyświetlenie rozwiązania
    cout << "Rozwiązanie układu równań:" << endl;
    for (int i = 0; i < solution.size(); i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
