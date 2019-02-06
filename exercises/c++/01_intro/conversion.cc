#include<iostream>
#include<string>


double get_double(){

double d;
double conv{1.0};

	while(!(std::cin >>d)){
	
			std::cin.clear();
	
			std::cin.ignore();
			
			std::cout<<"please type a number"<<std::endl;
	}
	return d*conv; //if it's not a double, make it
}



std::string final_unit(){ 				//function to get the text for final unit of measure
	
	std::string unit,text;
	
	std::cout<<"Please type m for meters or i for inches"<<std::endl;
	
	std::cin>>unit;
		
	if(unit=="i"){			//if input is in inches, result is in meter
		text="meters";
		return text;
	}
		
	if(unit=="m"){			//if input is in meters, result is in inches
		text="inches";
	return text;
	}

	std::cin.clear();				//if the input is not as requested, forget it and try again
	
	std::cin.ignore();

std::cout<<"Please type m or i"<<std::endl;   
final_unit();
}



double conversion(double n,std::string s){
	
	double const fact{0.0254}; //1 inch= 0.0254 m
	
	double result;

	if(s=="inches"){
	result=n/fact;
	return result;
	}
	if(s=="meters"){
	result=n*fact;
	return result;
	}

}




int main(){

double number,result;
std::string text;


	number=get_double();

	text=final_unit();	
	
	result=conversion(number,text);

	std::cout<<"the converted result is "<< result <<" "<< text <<std::endl;

}
