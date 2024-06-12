#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x) {
    return x * x - 4; 
}

double metodaBisekcji(double a, double b, double dokladnosc) {
    if (funkcja(a) * funkcja(b) >= 0) {
        cout << "przedział niepoprawny" << endl;
        return -1;
    }

    double c = a;
    while (abs((b - a)) >= dokladnosc) {
        c = (a + b) / 2;

        if (funkcja(c) == 0.0)
            break;

        else if (funkcja(c) * funkcja(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a, b, dokladnosc;
    
    cout << " przedział (podaj liczby przedzielone spacją): ";
    cin >> a >> b;
    cout << "dokładność: ";
    cin >> dokladnosc;

    double miejsceZerowe = metodaBisekcji(a, b, dokladnosc);

    if (miejsceZerowe == -1)
        cout << "nie udało się znaleźć miejsca zerowego" << endl;
    else
        cout << "miejsce zerowe: " << miejsceZerowe << endl;

    return 0;
}
