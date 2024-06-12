#include <iostream>
#include <vector>

using namespace std;

// Funkcja do mnożenia dwóch macierzy
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int m = matrix1.size();
    int n = matrix1[0].size();
    int p = matrix2[0].size();

    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Funkcja do wyświetlania macierzy
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Funkcja do sprawdzania przemienności dwóch macierzy
bool checkCommutativity(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    vector<vector<int>> result1 = multiplyMatrix(matrix1, matrix2);
    vector<vector<int>> result2 = multiplyMatrix(matrix2, matrix1);
    
    return result1 == result2;
}

int main() {
    // Przykładowe macierze
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                    {4, 5, 6}};
    vector<vector<int>> matrix2 = {{7, 8},
                                    {9, 10},
                                    {11, 12}};

    // Wyświetlenie macierzy
    cout << "Macierz 1:" << endl;
    displayMatrix(matrix1);
    cout << "Macierz 2:" << endl;
    displayMatrix(matrix2);

    // Mnożenie macierzy
    vector<vector<int>> result = multiplyMatrix(matrix1, matrix2);

    // Wyświetlenie wyniku mnożenia
    cout << "Wynik mnożenia:" << endl;
    displayMatrix(result);

    // Sprawdzenie przemienności
    if (checkCommutativity(matrix1, matrix2)) {
        cout << "Mnożenie macierzy jest przemienne." << endl;
    } else {
        cout << "Mnożenie macierzy nie jest przemienne." << endl;
    }

    return 0;
}
