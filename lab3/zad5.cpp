#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>

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

// Funkcja do mnożenia macierzy
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Funkcja do porównywania macierzy
bool areMatricesEqual(const Matrix& A, const Matrix& B, double epsilon = 1e-9) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::fabs(A[i][j] - B[i][j]) > epsilon) {
                return false;
            }
        }
    }
    return true;
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
        {4, 7, 2},
        {3, 6, 1},
        {2, 5, 1}
    };

    try {
        // Oblicz macierz odwrotną
        Matrix invMat = inverseGaussJordan(mat);

        // Mnożenie A * A^-1
        Matrix product1 = multiplyMatrices(mat, invMat);

        // Mnożenie A^-1 * A
        Matrix product2 = multiplyMatrices(invMat, mat);

        // Macierz jednostkowa do porównania
        Matrix identity = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        // Porównanie wyników
        std::cout << "A * A^-1:" << std::endl;
        printMatrix(product1);
        std::cout << std::endl;

        std::cout << "A^-1 * A:" << std::endl;
        printMatrix(product2);
        std::cout << std::endl;

        if (areMatricesEqual(product1, identity) && areMatricesEqual(product2, identity)) {
            std::cout << "Oba wyniki są równe macierzy jednostkowej." << std::endl;
        } else {
            std::cout << "Wyniki nie są równe macierzy jednostkowej." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
