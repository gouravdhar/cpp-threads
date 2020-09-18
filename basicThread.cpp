#include<iostream>
#include<thread>
using namespace std;

void func(){
	cout<<"Thread is running\n";
}

int main(){
	thread t(&func);
	// t.detach();
	t.join();
	cout<<"Main Thread\n";
	// t.detach();
	// t.join();
	return 0;
}