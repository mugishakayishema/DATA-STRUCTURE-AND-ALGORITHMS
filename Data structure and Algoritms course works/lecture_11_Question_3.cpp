//reg number:224003729
//Names: Mugisha kayishema
#include<iostream>
using namespace std;
class Stack{
	public:
	int top;
	int capacity;
	int *arr;
	Stack(int c){
		capacity=c;
		top=-1;
		arr=new int[capacity];
	}
	void push(int x){
		if(top==capacity-1){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		arr[++top]=x;
	}
	int pop(){
		if(top==-1){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}
		return arr[top--];
	}
	int peek(){
		if(top==-1){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		return arr[top];
	}
	bool isEmpty(){
		return top==-1;
	}
};
int main(){
	int n;
	cout<<"Enter number of days: ";
	cin>>n;
	int *prices=new int[n];
	cout<<"Enter stock prices: ";
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	Stack s(n);
	int *span=new int[n];
	for(int i=0;i<n;i++){
		while(!s.isEmpty() && prices[s.peek()]<=prices[i]){
			s.pop();
		}
		span[i]=(s.isEmpty())?(i+1):(i-s.peek());
		s.push(i);
	}
	cout<<"Stock spans are: ";
	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	delete[] prices;
	delete[] span;
	return 0;
}
