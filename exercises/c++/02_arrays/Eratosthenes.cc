#include<iostream>
#include<cmath>

void Erathostenes_bool(const int N){  //using boolean
	
	const int size=N-2;
	
	bool* list{new bool[size]}; 
	
		
	for(int i{0};i<=size;i++){
		list[i]=true;  //initialisation of the list
	}


	

	

	double condition= std::sqrt(N); //evaluation in the second argument of the loop would be repeated every time in order to check the condition. Hence here using negligible memory we avoid sqrt(N) calls to std::sqrt.
	
	std::cout<<"Prime numbers:"<<std::endl;
	
	///elimination of multiples

	for(int i{0};i<=condition;i++){

		int num=i+2; //i is index of the array, num is the integer represented in [2,N]
		
		if(list[i]==true){
	
			for(int j{num*num};j<=N;j=j+num){
	
				list[j-2]=false;
			
			}
		
		}
	}
	

	for(int i{0};i<=size;i++){
		
		if(list[i]==true){std::cout<<i+2<<std::endl;}
		
	}
	
}




void Erathostenes(const int N){
	
	int size=N-2;
	
	int* list{new int[size]}; //0 and 1 not considered
	
	for(int i{0};i<=size;i++){
		list[i]=i+2;  //initialisation of the list [2,N]
	}
	
	double condition= std::sqrt(N);
	
	std::cout<<"Prime numbers:"<<std::endl;
	
	for(int i{0};i<=condition;i++){
		
		if(list[i]!=0){
	
			int con=list[i]; //i is index of the array, con is the integer content in [2,N]
	
			for(int j{con*con};j<=N;j=j+con){
	
				list[j-2]=0;
			
			}
		
		}
	}
	

	for(int i{0};i<=size;i++){
		
		if(list[i]!=0){
			std::cout<<list[i]<<std::endl;
		}
		
	}
	
}
	
	
	





int main(){
	
	int N;
	
	std::cout<<"Insert upper bound for prime numbers to find [INCLUDED]: "<<std::endl;
	
	std::cin>>N;	
	
	Erathostenes(N);
	
}
