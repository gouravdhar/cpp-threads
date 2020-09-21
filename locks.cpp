#include<bits/stdc++.h>
using namespace std;

vector<int> sharedVariable;
mutex mtx;

void table(int n)
{
	// lock_guard<mutex> guard(mtx);
	
	vector<int> temp ;
	for (int i = 1; i <= 20; i++) {
		temp.push_back(i*n);
	}

	
	lock_guard<mutex> guard(mtx);
	for (auto itr : temp ) {
		cout << itr << ", ";
	}
	cout<<endl;
}


int main()
{
	int max = 50;
	thread t1(table, 1);
	thread t2(table, 10);
	thread t3(table, 20);
	thread t4(table, 40);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	// thread t5(printList);
	// t5.join();

	return 0;
}


// lock_guard<mutex> guard(mtx);