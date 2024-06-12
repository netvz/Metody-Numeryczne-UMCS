#include <iostream>
#include <vector>

using namespace std;

double divided_difference(const vector<double>& x_known, const vector<double>& y_known, int i, int j) {
    if (i == j) {
        return y_known[i];
    } else {
        return (divided_difference(x_known, y_known, i + 1, j) - divided_difference(x_known, y_known, i, j - 1)) /
               (x_known[j] - x_known[i]);
    }
}

double newton_interpolation(const vector<double>& x_known, const vector<double>& y_known, double x) {
    int n = x_known.size();
    double result = 0;
    double term = 1;

    for (int i = 0; i < n; ++i) {
        result += term * divided_difference(x_known, y_known, 0, i);
        term *= (x - x_known[i]);
    }

    return result;
}

int main() {
    vector<double> x_known = {-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2};
    vector<double> y_known = {11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99};
    double x = 1.5;

    double interpolated_y = newton_interpolation(x_known, y_known, x);
    cout << "interpolacja x = " << x << " y = " << interpolated_y << endl;

    return 0;
}
