#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

// Typ do reprezentacji macierzy
using Matrix = std::vector<std::vector<double>>;

// Funkcja pomocnicza do wyświetlania macierzy
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << std::endl;
    }
}

// Funkcja obliczająca macierz odwrotną za pomocą metody Gaussa-Jordana
Matrix inverseGaussJordan(const Matrix& mat) {
    int n = mat.size();
    Matrix augmented(n, std::vector<double>(2 * n));

    // Tworzymy rozszerzoną macierz [A|I]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = mat[i][j];
        }
        augmented[i][i + n] = 1;
    }

    // Eliminacja Gaussa-Jordana
    for (int i = 0; i < n; ++i) {
        // Znajdź wiersz z największym elementem w kolumnie i zamień go z wierszem i
        double maxEl = abs(augmented[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(augmented[k][i]) > maxEl) {
                maxEl = abs(augmented[k][i]);
                maxRow = k;
            }
        }

        // Zamień wiersze
        std::swap(augmented[i], augmented[maxRow]);

        // Sprawdź czy macierz jest osobliwa
        if (augmented[i][i] == 0) {
            throw std::runtime_error("Macierz jest osobliwa, nie można obliczyć macierzy odwrotnej.");
        }

        // Normalizuj wiersz
        double diagElement = augmented[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= diagElement;
        }

        // Eliminuje inne wiersze
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Wyodrębnij macierz odwrotną
    Matrix inv(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = augmented[i][j + n];
        }
    }

    return inv;
}

int main() {
    Matrix mat = {
        {4, 3},
        {3, 2}
    };

    try {
        Matrix inv = inverseGaussJordan(mat);
        std::cout << "Macierz odwrotna:" << std::endl;
        printMatrix(inv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
