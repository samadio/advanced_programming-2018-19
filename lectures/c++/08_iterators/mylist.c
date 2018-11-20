#include<iostream>
#include<memory>
#include<stdexcept>

enum class method{push_back, push_front};


template <class T>

class List{
	struct Node{  //simbols of struct Node is public from inside the class List, the Node class instead is private for the user of the List class (in main)
	
	T val;
	std::unique_ptr<Node> next;
	Node(const T& v, Node* n): val{v}, next{n}{}
	~Node()=default;
	};
	
//private:
	std::unique_ptr<Node> head;
	void push_front(const T& t){
//		auto old= head.release();
//		auto tmp= new Node{t,old};
//		head.reset(tmp);
//in one line:		
		head.reset(new Node{t,head.release()});		
	}

	void push_back(const T& t);	//outside

public:
	template <class ot> //compiler wants friend to be both templated
	friend std::ostream& operator <<(std::ostream&, const List<ot>& ); //he can see privates
	List()=default;
	void push(const T& t, method m= method::push_back ){
		if (head==nullptr){
			Node* tmp=new Node{t,nullptr};
			head.reset(tmp);
//do it in 1 line			head.reset(T* t=nullptr);
			return ;
		}
	
		switch(m){
			case method::push_back:
				push_back(t);
				break;
			case method::push_front:
				push_front(t);
				break;
			default:
				throw std::runtime_error{"Error: Unknown method"};
		}
	}	
	
	class Iterator;
	class ConstIterator; //Iterator which * gives a const&
	Iterator begin(){return Iterator{head.get()};}
	Iterator end(){return Iterator{nullptr}}
	
	ConstIterator begin() const;
	ConstIterator end() const;
};

template<class T>
class List<T>::ConstIterator : public List<T>::Iterator{
using parent= List<T>::Iterator;

}



template<class T>
class List<T>::Iterator{
	using Node= List<T>::Node;
	Node* current;
public:
	Iterator(Node* n): current{n}{}
	
	T& operator *()const{return current->val;}
	
	Iterator& operator ++(){
		current= current->next.get();
		return *this;
	}
	
/*	Iterator operator++(int){ //creates a new object
		Iterator it{*this};	 //so slower than pre
		++(*this);
		return it;
	}*/
	
	bool operator ==(const Iterator& other){
		return current== other.current;
		}
		
	bool operator !=(const Iterator& other){
		return !(*this==other);
	}		
	
	
};



template <typename T>
void List<T>::push_back(const T& t){
	auto tmp=head.get();
	while (tmp->next != nullptr){
		tmp=tmp->next.get(); //next is free
	}
	tmp->next.reset(new Node{t,nullptr});
}


template <class T>
std::ostream& operator <<(std::ostream& os, const List<T>& l ){
	auto tmp= l.head.get();
	while(tmp != nullptr){
		os << tmp->val << " ";
		tmp= tmp->next.get();
	}
		return os;
		
/*		auto it=l.begin();
		auto stop=l.end();
		for(;it!=stop;++it)
		  os << *it << " ";
		  
		for(const auto& x: l)
		os << x << " ";
		return os;*/
		
}





int main(){
	List<int> list;
	list.push(4);
	list.push(3,method::push_back);
	list.push(5,method::push_front);
	
//	for (auto& x: list)
	
	return 0;
}
