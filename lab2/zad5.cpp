#include <iostream>
#include <vector>

using namespace std;

// Funkcja wyznaczająca wyznacznik macierzy kwadratowej
double determinant(const vector<vector<double>>& matrix) {
    int size = matrix.size();
    
    // Bazowy warunek zakończenia rekurencji
    if (size == 1) {
        return matrix[0][0];
    }
    
    double det = 0;
    vector<vector<double>> submatrix(size - 1, vector<double>(size - 1));
    
    // Iteracja po pierwszym wierszu macierzy
    for (int i = 0; i < size; ++i) {
        int subi = 0; // Indeks dla podmacierzy
        for (int j = 1; j < size; ++j) {
            int subj = 0;
            for (int k = 0; k < size; ++k) {
                if (k == i) continue;
                submatrix[subi][subj] = matrix[j][k];
                ++subj;
            }
            ++subi;
        }
        det += (i % 2 == 1 ? -1 : 1) * matrix[0][i] * determinant(submatrix);
    }
    
    return det;
}

int main() {
    // Przykładowa macierz 3x3
    vector<vector<double>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    double det = determinant(matrix);
    
    cout << "Wyznacznik macierzy = " << det << endl;
    
    return 0;
}
