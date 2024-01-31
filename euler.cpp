
#include <iostream>
// cout 

#include <chrono>
// duration, clock functions

#include <cmath>
// sqrt, pow

#include <vector>
// vectors, obv

#include <fstream>
// file i/o

#include <string>
// strings, obv

#include <algorithm>
// sort, find

#include <tuple>
// tuple, tie

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
    long int total = 0, first, second;
    tie(first, second) = make_tuple(1,2);

    while (second <= limit){
        if(second % 2 == 0)
            total += second;
        tie(first, second) = make_tuple(second, first + second);
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

    vector<long int> triangleNumbers;
    for(int i = 1; i <= maxTriangle; i++){
        triangleNumbers.push_back( i*(i+1)/2 );
    }

    for( string word: words){
        if( find( triangleNumbers.begin(), triangleNumbers.end(), wordScore(word) )
                      != triangleNumbers.end() )
            retCounter++;
    }
    return retCounter;
}

long int e46(vector<long int>* primes){
    long int oddCounter = 3;
    double maybeSquare;

    while(true){
        for( auto p: *primes){
            if(p > oddCounter)
                return oddCounter;

            maybeSquare =  ( oddCounter - p ) / 2; 

            if( sqrt(maybeSquare) == int( sqrt(maybeSquare) ) )
                break;
        }
        oddCounter += 2;
    }
}

long int e47(){
    long int consecutiveFourPrimeDivisors = 0;

    for(long int i = 2*3*5*7;; ++i) {
    // 2*3*5*7 is the smallest number with four prime factors
    // smaller natural numbers can be ignored


        long int remainder = i;

        int numPrimeFactors = 1 + !(remainder & 1);
        // remainder & 1 is a bitwise bool fn that evaluates to true
        // if remainder is odd

        // so that line of code says that the number of prime factors
        // initializes to 1 if remainder is odd, and 2 if remainder is even
        // ie, 2 and at least one odd prime in remainder / 2


        for(; !(remainder & 1); remainder >>= 1);

        //  divide out all factors of 2 from remainder until what's left is odd
        //  semicolon at the end means inside for loop is no-op
        
        for(long int j = 3; j*j < remainder; j += 2) {

            // j*j must be less than remainder in order to enter the loop
            // therefore if i is any number other than a 
            // power of 2, remainder is never allowed to divide all the way to 1.
            // therefore there will always be a "final" remainder when 
            // the loop exits and that remainder is necessarily prime

            numPrimeFactors += (remainder % j == 0);

            // if j is the smallest odd number dividing remainder
            // then j is prime

            for(; remainder % j == 0; remainder /= j);
            // divide out all factors of j from remainder
        }

        consecutiveFourPrimeDivisors = (consecutiveFourPrimeDivisors + 1) 
            * (numPrimeFactors == 4);

        // numPrimeFactors == 4 is a bool which is cast to 1 in the multiplication
        // otherwise consecutiveFourPrimeDivisors is reset to 0
        
        if(consecutiveFourPrimeDivisors == 4) {
            return i - 3;
        }
    }
}

long int e50(vector<long int>* primes, long int  limit){
   
    long int maxLength = 0, maxLengthSum;
    for( long int primesIndex = 0; primesIndex < primes->size(); primesIndex++ ){

        long int p = primes->at(primesIndex);
        if( p > limit )
            break;
            
        long int primeSum = p, primeSumIndex = primesIndex, primeSumLength = 1;

        while( primeSum < limit ){
            primeSumIndex += 1;
            primeSum += primes->at(primeSumIndex);
            primeSumLength += 1;
            if( isPrime(primeSum) && primeSumLength > maxLength ){
                maxLength = primeSumLength;
                maxLengthSum = primeSum;
            }
        }
    } 
    return  maxLengthSum;
}

long int e71(long int limit){

    long int retNumerator = 2, retDenominator = 5;
    for( long int newDenominator = 9; newDenominator <= limit; newDenominator++ ){
        long int newNumerator =  newDenominator * 3 / 7;
        if( newNumerator / double(newDenominator) > retNumerator / double(retDenominator) )
            if( gcd( newDenominator, newNumerator ) == 1 )
                tie(retNumerator, retDenominator) = make_tuple(newNumerator, newDenominator);
    }

    return retNumerator;
}

long int e73(long int limit){
    long int retTotal = 0;
    for (long int d = 3; d <= limit; d++){
        for( long int n  =  d/3 + 1; n <= d/2; n++ ){
            if( gcd( n, d ) == 1 )
                retTotal += 1;
        }
    }

    return retTotal;
}

long int e91(long int limit){

    long int numtriangles = 0;
    for( int x1 = 1; x1 <= limit; x1++ ){
        for(int y1 = 1; y1 <= limit; y1++ ){
            double m1 = y1 / double(x1);
            for(int x2 = 0; x2 <= limit; x2++ ){
                for(int  y2 = 0; y2 <= limit; y2++ ){
                    if( x2 != x1 ){
                        double m2 = (y2 - y1) / double(x2 - x1);
                        if( abs(m1 * m2 + 1) < 0.0001 )
                            numtriangles += 1;
                    }
                
                }
            }
        }
    }

    return 3 * limit * limit + numtriangles ;

    // ### the 3 limit^2 are as follows:
    
    // ### p is any point on the x axis (!=0) and q is any point on the y axis
    // ### also != 0.  This creats a right triangle w a right angle at the origin
    // ### limit^2
    
    // ### p is any point on the x axis and q is any point directly above p,
    // ### a right triangle with a right angle on the x axis
    // ### similarly if p is a point on the y-axis
    
    // ### num triangles counts the other triangles where this is a right angle
    // ### in the interior of the grid.  It's verified by m1 * m2 == -1
    // ### for perpendicular lines.
}


long int e99(){
    ifstream file("e99data.txt");
    string s;
    int idx = 0, argmax, base, exp;
    double max = 0;

    while (getline(file, s))
    {
        idx += 1;
        int pos = s.find(',');
        base = stoi(s.substr(0,pos));
        exp = stoi(s.substr(pos + 1));
        if ( exp * log(base) > max ){
            max = exp * log(base);
            argmax = idx;
        }
    }

    return argmax;
}


int main(){

    auto start = chrono::steady_clock::now();

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
    cout << "e3:     " << e3(&primes, 600851475143) << endl;
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
    cout << "e46:    " << e46(&primes) << endl;
    cout << "e47:    " << e47() << endl;
    cout << "e50:    " << e50( &primes, pow(10,6) ) << endl;
    cout << "e71:    " << e71(pow(10,6)) << endl;
    cout << "e73:    " << e73(12000) << endl;
    cout << "e91:    " << e91(50) << endl;
    cout << "e99:    " << e99() << endl;

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
