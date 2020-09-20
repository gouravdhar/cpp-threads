#include<bits/stdc++.h>
using namespace std;

void func(){
	for(int i=0; i<10; i++){
		cout<<"Thread "<<i<<endl;
	}	
}
int main(){
	thread t(&func);
	// t.detach(); 
	if(t.joinable()){
		t.join();
	}
	cout<<"Main Thread\n";
	return 0;
}

