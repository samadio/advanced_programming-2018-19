#include <iostream>
#include <string>


int main(){
	
	int i=1;
	
	std::string a{};
	
	std::getline(std::cin,a);
			//getline(input source,storing variable)
	for(std::string b; std::getline(std::cin,b);){
		if(a==b){
			i=i+1;
		}	
	
		if(a!=b){
			std::cout<<i<<"      "<<a<<std::endl;
			a=b;			
			i=1;
		}
	
	}

}

//The two programs (using for or while) are exactly the same. The only difference consists in b being defined and initialised into the for-loop, so that the variable should not exist after the execution of the for loop. This means using the for loop allows to save memory, losing the information stored in the last assignment of string "b". The condition for both for and while loops to happen is that the command/function "std::getline(std::cin,b)" returns no error (so it returns 0). 
