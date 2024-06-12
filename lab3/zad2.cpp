#include <iostream>
#include <vector>

using namespace std;

// Funkcja zwracająca transpozycję macierzy
vector<vector<double>> transposeMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Tworzymy macierz transponowaną z odpowiednimi wymiarami
    vector<vector<double>> transposed(cols, vector<double>(rows));
    
    // Przechodzimy przez macierz oryginalną i przepisujemy elementy do macierzy transponowanej
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

int main() {
    // Przykładowa macierz 3x2
    vector<vector<double>> matrix = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    // Transponowanie macierzy
    vector<vector<double>> transposed = transposeMatrix(matrix);
    
    // Wyświetlanie macierzy transponowanej
    cout << "Macierz transponowana:" << endl;
    for (const auto& row : transposed) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    return 0;
}
