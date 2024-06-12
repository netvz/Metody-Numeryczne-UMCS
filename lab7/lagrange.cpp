#include <iostream>
#include <vector>

using namespace std;

double lagrange_interpolation(const vector<double>& x_known, const vector<double>& y_known, double x) {
    int n = x_known.size();
    double result = 0;
    for (int i = 0; i < n; ++i) {
        double term = y_known[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (x - x_known[j]) / (x_known[i] - x_known[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    vector<double> x_known = {-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2};
    vector<double> y_known = {11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99};
    double x = 1.5;

    double interpolated_y = lagrange_interpolation(x_known, y_known, x);
    cout << "interpolacja x = " << x << " y = " << interpolated_y << endl;

    return 0;
}
