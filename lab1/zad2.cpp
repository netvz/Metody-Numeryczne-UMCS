#include <iostream>

using namespace std;

int main(){

    int n = 16;
    int m = 4;

    float *array = new float[n];

    for(int k=0; k<n; k++){
        array[k] = 1.0/((k%m+1)*(k%m+2)); //tu 1 musi byc floatem w sensie 1.0 bo nie przejdzie precyzja i zaokragli wszystko do 0
    }

    for(int i=0; i<n; i++){
        cout << array[i] << endl;
    }

    delete [] array;

    return 0;
}