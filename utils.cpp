
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include "utils.h"

using namespace std;

void printVector(vector<long int> a){

    for( long int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMap(map<long int, int> a){

    for (auto i = a.begin(); i != a.end(); i++) 
        cout << i->first << "   " << i->second << endl; 

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

map<long int, int> primeFactors(vector<long int>* primes, long int n){

    long int remainder = n;
    map<long int, int> factors_map;

    for(auto p: *primes){

        if( remainder == 1 || p * p > remainder)
            break;
        while( remainder % p == 0 ){
            remainder /= p;
            factors_map[p] += 1;
        }
    }

    if( remainder > 1 )
        factors_map[remainder] = 1;    

    return factors_map;
}

long int numFactors( vector<long int> *primes, long int n ){
    map<long int, int> d = primeFactors(primes, n);
    long int retVal = 1;
    for (auto i = d.begin(); i != d.end(); i++) 
        retVal *= (i->second + 1);
    return retVal;
}




