#include <iostream>
#include <vector>

using namespace std;


double GillMoller(const vector<float>& numbers){
    int n = numbers.size();
    vector<double> partial_sums(n, 0.0);

    for(int i = 0; i < n; i++){
        double x = numbers[i];
        for(int j = 0; j<=i; j++){
            double y = partial_sums[j];
            if(abs(x) >= abs(y)){
                swap(x,y);
            }
            partial_sums[j] = x+y;
            x = y-partial_sums[j];
        }
        partial_sums[i] = x;
    }

    double sum = 0.0;
    for(int i = 0; i<n; i++){
        sum += partial_sums[i];
    }

    return sum;
}

int main(){

    int n = 16;
    int m = 4;

    vector<float> array;

    for(int k=0; k<n; k++){
        array.push_back(1.0/((k%m+1)*(k%m+2))); 
    }

    float result = GillMoller(array);

    cout << result << endl;

    return 0;
}