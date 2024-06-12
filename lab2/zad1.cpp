#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Funkcja do obliczania normy euklidesowej
double euclideanNorm(const vector<double>& vector) {
    double sum = 0.0;
    for (double value : vector) {
        sum += value * value;
    }
    return sqrt(sum);
}

// Funkcja do obliczania normy Manhattan
double manhattanNorm(const vector<double>& vector) {
    double sum = 0.0;
    for (double value : vector) {
        sum += abs(value);
    }
    return sum;
}

// Funkcja do obliczania normy maksimum
double maxNorm(const vector<double>& vector) {
    return *max_element(vector.begin(), vector.end(), [](double a, double b) { return abs(a) < abs(b); });
}

int main() {
    vector<double> vector = {1, 2, 3, 4, 5}; // Przykładowy wektor

    double euclidean = euclideanNorm(vector);
    double manhattan = manhattanNorm(vector);
    double maximum = maxNorm(vector);

    cout << "Wektor:";
    for (double value : vector) {
        cout << " " << value;
    }
    cout << endl;

    cout << "Norma Euklidesowa: " << euclidean << endl;
    cout << "Norma Manhattan: " << manhattan << endl;
    cout << "Norma maksimum: " << maximum << endl;

    return 0;
}
