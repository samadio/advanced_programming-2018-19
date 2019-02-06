#include<iostream>
#include<string>

int get_int1(){

double a;
	
	while(!(std::cin >>a)){			//you enter here if you type something which is not a double
	
		std::cout<< "please insert an integer NUMBER"<<std::endl;	
		
		std::cin.clear();
	
		std::cin.ignore();
	}

	if(a==(int)a){return a;}   //if the number entered is an integer, exit

	std::cin.clear();
	
	std::cin.ignore();
	
	std::cout<<"please insert an INTEGER number"<<std::endl; //if the number entered is not an integer, forget it and try again
	
	get_int1();
	
}



int get_int2(){

	double a;
	
	while((std::cin >>a)){
	
		if(a==(int)a){return a;}
		
			std::cout<<"you must enter an INTEGER number"<<std::endl;
		
			std::cin.clear();
	
			std::cin.ignore();
	}

	std::cout<<"you must enter an integer NUMBER"<<std::endl;
		
	std::cin.clear();

	std::cin.ignore();
		
	get_int2();


}


//C++ count 123.0 as an integer?



double get_double(){

double d,conv{1.0};

	while(!(std::cin >>d)){			//if entry is not a number, try again
	
			std::cin.clear();
	
			std::cin.ignore();
	}
	return d*conv;  //if entry is a number, this makes it double
}

int main(){

int n;
double d;

//n=get_int1();

d=get_double();
//std::cout<<"integer "<< n<<std::endl;
std::cout<<"double "<<d<<std::endl;

}
