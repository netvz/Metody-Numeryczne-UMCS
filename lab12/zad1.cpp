#include <iostream>
#include <vector>

class LCG {
public:
    LCG(unsigned long long seed, unsigned long long a, unsigned long long c, unsigned long long M)
        : X(seed), a(a), c(c), M(M) {}

    unsigned long long next() {
        X = (a * X + c) % M;
        return X;
    }

private:
    unsigned long long X;
    unsigned long long a;
    unsigned long long c;
    unsigned long long M;
};

int main() {
    // Parametry LCG: seed, a, c, M
    unsigned long long seed = 123456789; // Poczynkowa wartość (seed)
    unsigned long long a = 1664525;      // Typowy współczynnik dla LCG
    unsigned long long c = 1013904223;   // Typowy dodatek dla LCG
    unsigned long long M = 4294967296;   // Moduł (często stosowany 2^32)

    // Utwórz generator LCG
    LCG generator(seed, a, c, M);

    // Wygeneruj zbiór punktów
    std::vector<std::pair<unsigned long long, unsigned long long>> points;
    const int numPoints = 10; // Liczba punktów do wygenerowania

    for (int i = 0; i < numPoints * 2; i++) {
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
