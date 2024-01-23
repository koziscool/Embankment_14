
#include <vector>
#include <iostream>
#include <cmath>
#include "utils.h"

using namespace std;

void printVector(vector<long int> a){

    for( long int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Eratosthenes(vector<long int>* primes, long int limit){

    vector<bool> primeArray(limit, true);
    for( long int p = 2; p < sqrt(limit); p++){
        if( primeArray[p]){
            for(long int m = p*p; m < limit; m += 2 * p)
                primeArray[m] = false;
        }
    }

    primes->push_back(2);
    for(long int j = 3; j < limit; j += 2 ){
        if (primeArray[j])
            primes->push_back(j);
    }
}