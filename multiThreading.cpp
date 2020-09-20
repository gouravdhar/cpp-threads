#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace::std;

int main()
{
    // vector of threads
    vector<thread> workers;
    int numThreads = thread::hardware_concurrency();

    cout<<"Hardware Concurrency : "<<numThreads<<"\n";
	int num = 3; 

    for (int i = 0; i < numThreads; i++) {
        workers.push_back(thread([i](int sum) 
        {
        	//Task you want the ith thread to perform
        	sum = sum + i;
            std::cout << "Thread : "<<i<<" Sum = "<<sum<<"\n";
        },num));
    }

    for_each(workers.begin(), workers.end(), [](thread &t) 
    {
        t.join();
    });

    return 0;
}