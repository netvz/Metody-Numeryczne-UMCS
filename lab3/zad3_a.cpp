#include <iostream>
#include <vector>
#include <iomanip>

// Typ do reprezentacji macierzy
using Matrix = std::vector<std::vector<double>>;

// Funkcja obliczająca wyznacznik macierzy za pomocą rozwinięcia Laplace'a
double determinant(const Matrix& mat) {
    int n = mat.size();
    if (n == 1) {
        return mat[0][0];
    }
    if (n == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double det = 0;
    for (int i = 0; i < n; ++i) {
        Matrix subMatrix(n - 1, std::vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            int columnIndex = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                subMatrix[j - 1][columnIndex++] = mat[j][k];
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * determinant(subMatrix);
    }
    return det;
}

// Funkcja obliczająca macierz dopełnień algebraicznych
Matrix adjugate(const Matrix& mat) {
    int n = mat.size();
    Matrix adj(n, std::vector<double>(n));
    if (n == 1) {
        adj[0][0] = 1;
        return adj;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Matrix subMatrix(n - 1, std::vector<double>(n - 1));
            int subRow = 0;
            for (int row = 0; row < n; ++row) {
                if (row == i) continue;
                int subCol = 0;
                for (int col = 0; col < n; ++col) {
                    if (col == j) continue;
                    subMatrix[subRow][subCol++] = mat[row][col];
                }
                ++subRow;
            }
            adj[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * determinant(subMatrix);
        }
    }
    return adj;
}

// Funkcja obliczająca macierz odwrotną
Matrix inverse(const Matrix& mat) {
    int n = mat.size();
    double det = determinant(mat);
    if (det == 0) {
        throw std::runtime_error("Macierz jest osobliwa, nie można obliczyć macierzy odwrotnej.");
    }

    Matrix adj = adjugate(mat);
    Matrix inv(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = adj[i][j] / det;
        }
    }
    return inv;
}

// Funkcja pomocnicza do wyświetlania macierzy
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix mat = {
        {4, 3},
        {3, 2}
    };

    try {
        Matrix inv = inverse(mat);
        std::cout << "Macierz odwrotna:" << std::endl;
        printMatrix(inv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
