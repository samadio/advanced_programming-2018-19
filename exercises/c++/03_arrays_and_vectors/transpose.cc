#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<array>


template<typename T,unsigned int N>

void printmat(std::array<T,N>& A, unsigned int nrow, unsigned int ncol){

	for(int i{0};i<nrow;i++){
		for(int j{0};j<ncol;j++){
			std::cout<<A[i*ncol+j]<<"  ";
			if(j==ncol-1){std::cout<<""<<std::endl;}
		}
	}

}




template<typename T,unsigned int N>

void transpose(std::array<T,N>& A, unsigned int const& nrow, unsigned int const& ncol){

	//I want N const but not nrow and ncol:I want to swap them in transpose

	//way to modify const nrow and ncol

	unsigned int* pointrow= const_cast<unsigned int*>(&nrow); 
	unsigned int* pointcol= const_cast<unsigned int*>(&ncol);


	
	unsigned int temp; //swap dimensions
	
	
	std::cout<<"Printing the transpose"<<std::endl;
	
	std::array<T,N> B;
		
	
	
	for(int j{0};j<nrow;j++){		//writing in correct order is faster than reading
	
		for(int i{0};i<ncol;i=i+3){	

		B[j*nrow+i]=A[i*ncol+j];				//unrolled loop: 3 pipelines
		B[j*nrow+i+1]=A[(i+1)*ncol+j];
		B[j*nrow+i+2]=A[(i+2)*ncol+j];				
		}
		 
	}
	
	A=B;
	
	
	temp=nrow;
	*pointrow=ncol;
	*pointcol=temp;
	
	printmat<int,N>(A,nrow,ncol);	

	std::cout<<"This function (at least for now) cannot swap the value of nrow and ncol out of itself"<<std::endl;
}


int main(){
	
	mutable unsigned int const nrow{4}, ncol{2};

	unsigned int const N{nrow*ncol};

	std::array<int,N> A;

		//initialisation
			
	for(int i{0};i<nrow;i++){
		for(int j{0};j<ncol;j++){
			A[i*ncol+j]= i*ncol+j+1;
		}
	}
	
	
	printmat<int,N>(A,nrow,ncol);	

	transpose<int, N>(A,nrow,ncol);
		
}
