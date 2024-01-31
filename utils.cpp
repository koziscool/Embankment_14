
#include <vector>
// vectors, obv

#include <iostream>
// cout

#include <cmath>
// sqrt, pow
#include <map>
// maps, ie hash tables

#include <string>
// strings, obv

#include <tuple>
// make_tuple, tic


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

bool isPrime(long int number){
    if (number != 2){
        if (number < 2 || number % 2 == 0) {
            return false;
        }
        for(long int i=3; (i*i)<=number; i+=2){
            if(number % i == 0 ){
                return false;
            }
        }
    }
    return true;
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

long int wordScore(string s){
    long int retTotal = 0;
    for (char c: s)
        retTotal += int(c) - int('A') + 1;

    return retTotal;
}

// assume a >= b and a and b > 0 
long int gcd( long int a, long int b ){  
    while( a % b > 0 )
        tie(a, b) = make_tuple(b, a % b);
    return b;
}
