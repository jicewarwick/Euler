#ifndef PRIME_97KMIIND
#define PRIME_97KMIIND
 
#include <cmath>
#include <iostream>
#include <fstream>
 

bool isOdd(const int);
bool isEven(const int);

bool isPrime(const unsigned long long );

bool isPantagon(const int);

bool databaseExists();

int largestPrimeUpTo(const int);
int nthPrime(const unsigned int);

bool isDivisable(int a, int b);

int sumOfProperDivisors(int);

// A number is perfect if it is a sum of all its proper divisors
bool isPerfect(int);

// A number is deficient if the sum of all its proper divisors is less than this number
bool isDeficient(int);

// A number is abundant if the sum of all its proper divisors is grater than this number
bool isAbundant(int);

#endif /* end of include guard: PRIME_97KMIIND */
