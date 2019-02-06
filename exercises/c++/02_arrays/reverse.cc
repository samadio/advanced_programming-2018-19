#include<iostream>

template <typename T>


T* allocate(std::size_t N){

		T* point{new T[N]};

		for(std::size_t i{0};i<N;i++){
			std::cin>>point[i];
		}
		return point;
} 


template <typename T>

void reverse(T* point, int N){

	for(int i{N-1};i>=0;i=i-1){   //using size_t here causes problem because after 0 an unsigned int goes to his maximum
			std::cout<<point[i]<<std::endl;
	}

}

int main(){

std::size_t N;
int* point;

	std::cout<<"Please insert the number of elements"<<std::endl;

	std::cin>>N;
	
	point=allocate<int>(N);	

	reverse(point,N);
	
	delete[]point;
}


