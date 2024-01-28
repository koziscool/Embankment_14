
#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

void printVector(vector<long int> a);
void printMap(map<long int, int> a);
void Eratosthenes(vector<long int>* primes, long int limit);
map<long int, int> primeFactors(vector<long int> *primes, long int n);
long int numFactors( vector<long int> *primes, long int n );
long int wordScore(string s);

