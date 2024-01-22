
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

int main(){

    auto start = chrono::steady_clock::now();

    cout << endl;

    cout << "e1:   " << e1(1000) << endl;
    cout << "e2:   " << e2(4 * pow(10,6)) << endl;

    auto finish = chrono::steady_clock::now();
    auto duration = chrono::duration<double, std::milli>(finish - start);

    cout << endl;
    cout << "all completed problems:   " << duration.count() << " milliseconds" << endl;
    cout << endl;

    start = chrono::steady_clock::now();
    vector<long int> primes = Eratosthenes(pow(10, 7));
    finish = chrono::steady_clock::now();
    duration = chrono::duration<double, std::milli>(finish - start);

    cout << duration.count() << " milliseconds" << endl;
    cout << endl;

    
    return 0;
}
