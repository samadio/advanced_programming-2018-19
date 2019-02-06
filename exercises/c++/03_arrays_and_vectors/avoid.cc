#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

template <typename T>
void print_vector(std::vector<T> vec){
	
	for(int i{};i<vec.size();i++){
		std::cout<< vec[i]<<std::endl;
	}
	
}


int main(){
	
	std::vector<std::string> data;
	std::string temp;
	int count;
	
	std::cout<< "Insert words. Write end to finish."<<std::endl;
	
	
	while(std::cin>>temp){
		if(temp=="end"){break;}
		data.push_back(temp);  //importing data
	}

	std::sort(data.begin(),data.end());
	std::cout<< " "<<std::endl;
	std::cout<< "Sorted"<<std::endl;

	print_vector<std::string>(data);
	
	for(int i{}; i<data.size();i++){
		if(data[i]==data[i+1]){		//if 2 matches
			data.erase(data.begin()+i);		//erase the 1st and repeat on the same vector element
			i=i-1;
		}
	}
	
	std::cout<< " "<<std::endl;
	std::cout<< "Repetitions avoided"<<std::endl;
	
	print_vector<std::string>(data);
	
}
