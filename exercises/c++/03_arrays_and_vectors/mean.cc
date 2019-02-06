#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	
	std::vector<double> data;
	double temp;
	double count{}, mean,sum{},median;

	while(std::cin>>temp){
		data.push_back(temp);  //importing data
		count+=1;
		sum+=temp;
	}
	
	mean=sum/count;
		
	std::sort(data.begin(),data.end());	

	median=data[count/2];
	
	std::cout<<"mean: "<<mean<<std::endl;
	std::cout<<"median: "<<median<<std::endl;
	
}
