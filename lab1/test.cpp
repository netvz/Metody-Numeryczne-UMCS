#include <iostream>
#include <vector>

using namespace std;

double kahanSum(const vector<double>& numbers) {
    double sum = 0.0;
    double c = 0.0;

    for (double number : numbers) {
        double y = number - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return sum;
}

double gillMollerSum(const vector<double>& numbers) {
    int n = numbers.size();
    vector<double> partial_sums(n, 0.0);

    for (int i = 0; i < n; i++) {
        double x = numbers[i];
        for (int j = 0; j <= i; j++) {
            double y = partial_sums[j];
            if (abs(x) >= abs(y)) {
                swap(x, y);
            }
            partial_sums[j] = x + y;
            x = y - partial_sums[j];
        }
        partial_sums[i] = x;
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += partial_sums[i];
    }

    return sum;
}

int main() {
    vector<double> array;
    int n = 16;
    int m = 4;

    for (int k = 0; k < n; k++) {
        array.push_back(1.0 / ((k % m + 1) * (k % m + 2)));
    }

    double resultKahan = kahanSum(array);
    double resultGillMoller = gillMollerSum(array);

    cout << "Wynik Kahana: " << resultKahan << endl;
    cout << "Wynik Gilla-Mollera: " << resultGillMoller << endl;

    return 0;
}
