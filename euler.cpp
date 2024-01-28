
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
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

long int e3(vector<long int>* primes, long int n){
    long int max_prime = 0;
    long int remainder = n;

    for(auto p: *primes){
        if( remainder == 1 || p*p > remainder )
            break;
        if( remainder % p == 0 )
            max_prime = p;
        while( remainder % p == 0 )
            remainder /= p;
    }
    if (remainder == 1)
        return max_prime;
    else
        return remainder;
}

long int e5(int limit){
    vector<long int> little_primes;
    Eratosthenes(&little_primes, limit);
    long int ret_val = 1;
    for(auto p: little_primes){
        long int prime_power = p;
        while( prime_power * p < limit ){
            prime_power *= p;
        }
        ret_val *= prime_power;
    }
    return ret_val;
}

int e7(vector<long int>* primes, int limit){
    return primes->at(limit-1);
}

long int e8(int substring_length){
    ifstream file("e8data.txt");
    string s, digit_str = ""; 
    long int this_product, max_product = 0;

    while (getline(file, s))
    {
        digit_str += s;
    }

    for( int i = 0; i < digit_str.length() - substring_length; i++ ){
        this_product = 1;
        for( int j = 0; j < substring_length; j++ )
            this_product *= int( digit_str[ i+j ] - '0' );
        if( this_product > max_product )
            max_product = this_product;
    }

    return max_product;
}

long int e9(long int limit){

    long int a = 1, b = 2;
    long double c = sqrt(a*a +b*b);

    while( a + b + c <= limit ){
        while( a + b + c <= limit ){
            if( c == int(c) && a + b + c == limit )
                return a*b*int(c);
            b += 1;
            c = sqrt(a*a +b*b);
        }
        a += 1;
        b = a + 1;
        c = sqrt(a*a +b*b);
    }
    
    return -1;
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

long int e12(vector<long int>* primes, int limit){

    auto triangle = [](long int n){
        return n * (n+1) / 2;
    };

    long int i = 1;
    while( numFactors(primes, triangle(i) ) <= limit ){
        i += 1;
    }

    return triangle(i);
}

long int e22(){
    ifstream file("e22data.txt");
    string s = ""; 
    vector<string> names;
    long int retTotal = 0;

    while (getline(file, s, ','))
    {
        s = s.substr(1, s.length() - 2);
        names.push_back(s);
    }

    std::sort(names.begin(), names.end());

    for( int i = 0; i < names.size(); i++ ){
       retTotal += (i+1) * wordScore( names[i] );
    }

    return retTotal;
}

long int e28( int gridSize ){

    long int numRings = gridSize / 2;
    int retTotal = 1, bottomRightCorner = 3, increment = 2;
    
    for( int _ = 0; _ < numRings; _++ ){
        retTotal += 4 * bottomRightCorner + 6 * increment;
        bottomRightCorner += 4*increment + 2;
        increment += 2;
    }

    return retTotal;
}

long int e39(long int limit){

    long int a = 1, b = 2;
    double c;
    map<long int, long int> integerRightTriangles;

    while( sqrt(a*a + b*b) <=  limit ){
        while( sqrt(a*a + b*b) <=  limit ){
            c = sqrt(a*a + b*b);
            if( c == int(c) and a+b+int(c) <= limit )
                integerRightTriangles[ a+b+int(c) ] += 1;
            b += 1;
        }
        a += 1;
        b = a + 1;
    }

    long int retIndex = integerRightTriangles.begin()->first;
    long int maxValue = integerRightTriangles.begin()->second;
    for (auto it = integerRightTriangles.begin(); it != integerRightTriangles.end(); it++){
        if( it->second > maxValue ){
            retIndex = it->first;
            maxValue = it->second;
        }
    } 

    return retIndex;
}

long int e42(){

    ifstream file("e42data.txt");
    string s; 
    vector<string> words;
    long int retCounter = 0, maxTriangle = 500;

    while (getline(file, s, ','))
    {
        s = s.substr(1, s.length() - 2);
        words.push_back(s);
    }

    set<long int> triangleNumbers;
    for(int i = 1; i <= maxTriangle; i++){
        triangleNumbers.insert( i*(i+1)/2 );
    }

    for( string word: words){
        if( triangleNumbers.find( wordScore(word) )  != triangleNumbers.end() )
            retCounter++;
    }
    return retCounter;
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
    cout << "e5:     " << e3(&primes, 600851475143) << endl;
    cout << "e5:     " << e5(20) << endl;
    cout << "e7:     " << e7(&primes, 10001) << endl;
    cout << "e8:     " << e8(13) << endl;
    cout << "e9:     " << e9(1000) << endl;
    cout << "e10:    " << e10(&primes, 2 * pow(10,6)) << endl;
    cout << "e12:    " << e12(&primes, 500) << endl;
    cout << "e22:    " << e22() << endl;
    cout << "e28:    " << e28(1001) << endl;
    cout << "e39:    " << e39(1000) << endl;
    cout << "e42:    " << e42() << endl;

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
