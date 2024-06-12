#include <iostream>
#include <cstdlib>  // dla funkcji rand() i srand()
#include <ctime>    // dla funkcji time()

using namespace std;

double approximatePi(int n) {
    int pointsInsideCircle = 0;
    
    // Ustawienie ziarna dla generatora liczb pseudolosowych
    srand(time(0));
    
    // Iteracja przez n punktów
    for (int i = 0; i < n; ++i) {
        // Losowanie punktu (x, y) w przedziale [0, 1]
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        
        // Sprawdzenie, czy punkt (x, y) należy do koła jednostkowego
        if (x*x + y*y <= 1) {
            pointsInsideCircle++;
        }
    }
    
    // Obliczenie przybliżonej wartości π
    double pi = 4.0 * pointsInsideCircle / n;
    return pi;
}

int main() {
    int n;
    cout << "Podaj liczbę punktów do wylosowania: ";
    cin >> n;
    
    // Obliczenie przybliżonej wartości π
    double approxPi = approximatePi(n);
    
    // Wyświetlenie wyniku
    cout << "Przybliżona wartość liczby π: " << approxPi << endl;
    
    return 0;
}
