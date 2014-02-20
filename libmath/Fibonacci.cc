#include "Fibonacci.h"

#define GOLDPLUS ((1 + sqrt(5))/2)
#define GOLDMINUS ((1 - sqrt(5))/2)

//constructor
Fibonacci::Fibonacci(){}

unsigned long long Fibonacci::val(long n){
	unsigned long long ret = (pow(GOLDPLUS, n) - pow(GOLDMINUS, n))/(sqrt(5));

	return ret;
}

unsigned long long Fibonacci::smallest(long n){
	double tmp = n * sqrt(5) + 0.5;
	double index = (floor( log(tmp) / log(GOLDPLUS) ) );
	return Fibonacci::val(index);

}
