#include <iostream>
#include <vector>

using namespace std;

float Kahan(const vector<double>& numbers){
    double suma = 0.0;
    double korekta = 0.0;

    for(float x : numbers){
        double y = x - korekta;
        double t = suma + y;
        korekta = (t - suma) - y;
        suma = t;
    }

    return suma;
}

int main(){

    int n = 16;
    int m = 4;

    vector<double> array;

    for(int k=0; k<n; k++){
        array.push_back(1.0/((k%m+1)*(k%m+2))); 
    }

    float result = Kahan(array);

    cout << result << endl;

    return 0;
}