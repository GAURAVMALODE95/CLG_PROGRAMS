#include<iostream>
#include<queue>
using namespace std;

queue<int> p;

void accept_order(){

	int x;
	cout<<"\nenter the order id : "<<endl;
	cin>>x;
    	p.push(x);
}

void serve_order(){
	if(p.empty()){
	cout<<"\nall orders are already served !"<<endl;
	}

	else{
	cout<<"\n\norder served!!\n\norder number : "<<p.front()<<endl;
	p.pop();
	
	}
	
	
}

void display(queue<int> p){
	cout<<"\nthe orders remaning to serve are : "<<endl<<endl;

	while(!p.empty()){
	
	cout<<p.front()<<" ";
	p.pop();
	
	}



}

int main(){
int ch;
cout<<"\nwelcome to pizza parlor !"<<endl;
	do{
	
	cout<<"\n1.accept order.\n2.serve the order.\n3.display all orders.\n4.exit"<<endl;
	cout<<"\n\nenter your choice : "<<endl;
	cin>>ch;
		switch(ch){
		case 1:
			accept_order();
			break;
			
		case 2:
			serve_order();
			break;
			
		case 3: 
			display(p);
			break;
			
		case 4:
			break;
		
		
		
		}
	
	
	}while(ch!=4);











return 0;
}
