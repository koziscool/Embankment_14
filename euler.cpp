
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <utility>
#include <vector>
#include "utils.h"


using namespace std;

int e1(int limit){
    int total = 0;
    for( int i = 1; i < limit; i++ ){
        if( i % 3 == 0 || i % 5 == 0 )
            total += i;
    }
    
    return total;
}

int e2(int limit){
    int total = 0;
    pair<int, int> f(1,2);
    
    while (f.second <= limit){
        if(f.second % 2 == 0)
            total += f.second;
        f = { f.second, f.first + f.second };
    }
    
    return total;
}

int e7(vector<long int>* primes, int limit){
    return primes->at(limit-1);
}

long int e10(vector<long int>* primes, int limit){
    long int total = 0;
    vector<long int>::iterator i = primes->begin();
    while( *i < limit ){
        total += *i;
        i++;
    } 
    return total;
}

int main(){

    auto start = chrono::steady_clock::now();

    vector<long int> little_primes;
    Eratosthenes(&little_primes, 100);

    vector<long int> primes;
    Eratosthenes(&primes, pow(10, 7));

    auto finish_preprocess = chrono::steady_clock::now();
    auto duration_preprocess = chrono::duration<double, std::milli>(finish_preprocess - start);

    cout << endl;
    cout << "Preprocess:   " << duration_preprocess.count() << " milliseconds" << endl;
    cout << endl;

    auto start_problems = chrono::steady_clock::now();

    cout << "e1:     " << e1(1000) << endl;
    cout << "e2:     " << e2(4 * pow(10,6)) << endl;
    cout << "e7:     " << e7(&primes, 10001) << endl;
    cout << "e10:    " << e10(&primes, 2 * pow(10,6)) << endl;

    auto finish = chrono::steady_clock::now();
    auto duration_problems = chrono::duration<double, std::milli>(finish - start_problems);

    cout << endl;
    cout << "all completed problems:   " << duration_problems.count() << " milliseconds" << endl;
    cout << endl;

    auto duration_total = chrono::duration<double, std::milli>(finish - start);
    cout << "total runtime:   " << duration_total.count() << " milliseconds" << endl;
    cout << endl;



    return 0;
}
