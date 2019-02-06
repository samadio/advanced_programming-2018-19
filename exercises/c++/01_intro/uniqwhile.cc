#include <iostream>
#include <string>


int main(){

	int i=1;
	
	std::string a{},b{};
		
	std::getline(std::cin,a);
			//getline(mezzo di input,variabile): leggi da mezzo e store in variabile
			
	while(std::getline(std::cin,b))
	{
		
		if(a==b){
				i=i+1;
		}
		
		if(a!=b){
			std::cout<< "           "<< i <<" "<< a <<std::endl;
			a=b;
			i=1;
		}
		
	}
	
}
