#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    double a = 1e16;
    double b = 1.0;
    double c = -1e16;

    double one = (a+b)+c;
    double two = a+(b+c);

    cout << setprecision(50);

    cout << one << endl;
    cout << two << endl;

    //powinny wychodzic inne wyniki 0 i 1 bo pochlanianie liczb przez mniejsze i wieksze i wgl 
    return 0;
}