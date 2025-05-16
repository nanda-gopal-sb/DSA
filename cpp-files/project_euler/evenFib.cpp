#include <iostream>
// Problem 2 of Project Euler - returns the sum of even fib numbers till 4 Million
unsigned int limit = 4000000;

int fib(int n) {

	// If n is 1 or 0, then return n, works for 0th
  	// and 1st terms
    if (n <= 1)
        return n;

    // Recurrence relation to find the rest of the
  	// terms
    return fib(n - 1) + fib(n - 2);
}
bool isEven(int n){
	if(n%2==0) return true;
	else return false; 
}


int main(){
	int sum = 0 ;
	int curr = 0 ;
	for(int i = 0 ; curr<limit ; i++){
		curr = fib(i);
		if(isEven(curr)) sum = sum + curr;
	}
	std::cout<<sum;
}

