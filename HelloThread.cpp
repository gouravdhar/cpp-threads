#include<bits/stdc++.h>
using namespace std;

void func(){
	//work to be done by thread
	for(int i=0; i<10; i++){
		cout<<"Thread "<<i<<endl;
	}	
}
int main(){
	//creating thread
	thread t(&func);

	// t.detach(); //comment/uncomment to detach thread

	//check if thread is joinable
	if(t.joinable()){
		t.join();
	}

	cout<<"Main Thread\n";
	return 0;
}

