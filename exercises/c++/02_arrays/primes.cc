#include<iostream>


//writing & reallocating memory is a slow task. So I'd prefer wasting some memory than wasting time for multiple reallocations (as long as this choice doesn't fill the memory, but it's unlikely to happen with choices of N of this kind).

void prime_upto(int size, int N){
	
	int* primes_t{new int[size]};  //creating temporary pointer to fill
	
	primes_t[0]=2;	
	
	int count{1};

	std::cout<<primes_t[0]<<std::endl;	
	
	for(int j{3};j<=N;j=j+2){  //2 set as first, all the even numbers are not checked.
	
		int remainder;

		for(int i{2}; i<=j/2;i++){
		  remainder=j%i;
		  if(remainder==0){break;}  //if you find a divisor, stop searching for one
		}		
		
		if(remainder==0){continue;}//if you have found a divisor, it's not a prime-> next number
		
		count=count+1;
		primes_t[count]=j;
		std::cout<<primes_t[count]<<std::endl;
	}

	delete[]primes_t;	
}




int main(){
	
	int N{100};
	int size{N/4}; //for every 10 numbers except [0-10) there are 5 even numbers & a multiple of 5, so there are at least 6/10 not prime numbers. For N with order of magnitude 10^2, using refine upper bounds using a complicated function like log N seems unnecessary
	
	prime_upto(size,N);
	
}
