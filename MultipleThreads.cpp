#include<bits/stdc++.h>
using namespace std;

void func(int n){
	for(int i=0; i<n; i++){
		cout<<"Thread is running\n";
	}	
}

int main(){

	//for calculating the execution time
	clock_t start, end; 
	start = clock();

	vector<thread> workers;
	int numThreads;
	int numberOfPrints = 200;
	cout<<"Enter Number of Threads(divisor of 200) : ";
	cin>>numThreads;

	for (int i = 0; i < numThreads; i++) {
        workers.push_back(thread(&func, (numberOfPrints/numThreads)));
    }
    
    for_each(workers.begin(), workers.end(), [](thread &t) 
    {
        t.join();
    });

	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Execution time : " << time_taken <<" sec"<<endl;
	return 0;
}