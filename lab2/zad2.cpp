#include <iostream>
#include <cmath>

using namespace std;

// Odległość Euklidesowa
double euclideanDistance(pair<int, int> point1, pair<int, int> point2) {
    return sqrt(pow(point2.first - point1.first, 2) + pow(point2.second - point1.second, 2));
}

// Odległość Manhattan
double manhattanDistance(pair<int, int> point1, pair<int, int> point2) {
    return abs(point2.first - point1.first) + abs(point2.second - point1.second);
}

// Odległość w metryce rzecznej (Diagonalna, ale tylko w kierunkach pionowych i poziomych)
double riverDistance(pair<int, int> point1, pair<int, int> point2) {
    int dx = abs(point2.first - point1.first);
    int dy = abs(point2.second - point1.second);
    return dx + dy - min(dx, dy);
}

// Odległość w metryce kolejowej (Diagonalna)
double railwayDistance(pair<int, int> point1, pair<int, int> point2) {
    return max(abs(point2.first - point1.first), abs(point2.second - point1.second));
}

int main() {
    pair<int, int> point1 = make_pair(1, 2);  // Współrzędne pierwszego punktu
    pair<int, int> point2 = make_pair(4, 6);  // Współrzędne drugiego punktu

    double euclidean = euclideanDistance(point1, point2);
    double manhattan = manhattanDistance(point1, point2);
    double river = riverDistance(point1, point2);
    double railway = railwayDistance(point1, point2);

    cout << "Punkt 1: (" << point1.first << ", " << point1.second << ")" << endl;
    cout << "Punkt 2: (" << point2.first << ", " << point2.second << ")" << endl;
    cout << "Odległość Euklidesowa: " << euclidean << endl;
    cout << "Odległość Manhattan: " << manhattan << endl;
    cout << "Odległość w metryce rzecznej: " << river << endl;
    cout << "Odległość w metryce kolejowej: " << railway << endl;

    return 0;
}
