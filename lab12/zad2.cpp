#include <iostream>
#include <vector>
#include <random>

// Klasa implementująca generator LFG
class LFG {
public:
    LFG(unsigned long long seed, int p, int q, unsigned long long M)
        : p(p), q(q), M(M) {
        // Inicjalizuj generator losowy z ziarna
        std::mt19937_64 rng(seed);
        std::uniform_int_distribution<unsigned long long> dist(0, M-1);

        // Inicjalizuj początkową sekwencję
        for (int i = 0; i < p; ++i) {
            X.push_back(dist(rng));
        }
        currentIndex = p - 1;
    }

    unsigned long long next() {
        unsigned long long nextValue = (X[(currentIndex + p - q) % p] + X[currentIndex]) % M;
        currentIndex = (currentIndex + 1) % p;
        X[currentIndex] = nextValue;
        return nextValue;
    }

private:
    std::vector<unsigned long long> X; // Sekwencja liczb
    int p; // Wartość p
    int q; // Wartość q
    unsigned long long M; // Moduł
    int currentIndex; // Aktualny indeks
};

int main() {
    // Parametry LFG
    unsigned long long seed = 123456789; // Poczynkowa wartość (seed)
    int p = 10; // Przesunięcie p
    int q = 7;  // Przesunięcie q
    unsigned long long M = 4294967296; // Moduł (często stosowany 2^32)

    // Utwórz generator LFG
    LFG generator(seed, p, q, M);

    // Wygeneruj zbiór punktów
    std::vector<std::pair<unsigned long long, unsigned long long>> points;
    const int numPoints = 10; // Liczba punktów do wygenerowania

    for (int i = 0; i < numPoints; ++i) {
        unsigned long long x1 = generator.next();
        unsigned long long x2 = generator.next();
        points.push_back({x1, x2});
    }

    // Wyświetl wygenerowane punkty
    std::cout << "Wygenerowane punkty (Xi, Xi+1):" << std::endl;
    for (const auto& point : points) {
        std::cout << "(" << point.first << ", " << point.second << ")" << std::endl;
    }

    return 0;
}
