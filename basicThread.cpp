#include<iostream>
#include<thread>
using namespace std;

void func(){
	for(int i=0;i<20;i++){cout<<i<<endl;}
	cout<<"Thread is running\n";

}

int main(){
	thread t(&func);
	cout<<"Main Thread\n";
	// t.detach();  //uncomment for detaching the thread
	if(t.joinable()){
		t.join();
	}	
	return 0;
}