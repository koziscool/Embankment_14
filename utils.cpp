
#include <vector>
#include <iostream>
#include "utils.h"
#include <cmath>

using namespace std;

void printVector(vector<long int> a){

    for( long int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<long int> Eratosthenes(long int limit){
    
    vector<bool> primeArray(limit, true);
    for( long int p = 2; p < sqrt(limit); p++){
        if( primeArray[p]){
            for(long int m = p*p; m < limit; m += 2 * p)
                primeArray[m] = false;
        }
    }

    vector<long int> primes(1,2);
    for(long int j = 3; j < limit; j += 2 ){
        if (primeArray[j])
            primes.push_back(j);
    }
    return primes;
}