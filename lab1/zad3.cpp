#include <iostream>

using namespace std;

int main(){

    int n = 16;
    int m = 4;

    float *array = new float[n];

    for(int k=0; k<n; k++){
        array[k] = 1.0/((k%m+1)*(k%m+2)); 
    }

    float sum = 0;
    for(int i=0; i<n; i++){
        sum += array[i];
    }

    cout << sum;

    delete [] array;

    return 0;
}