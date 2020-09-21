#include<bits/stdc++.h>
using namespace std;

mutex mtx;

void table(int n)
{
	vector<int> temp ;
	for (int i = 1; i <= 10; i++) {
		temp.push_back(i*n);
	}
	
	lock_guard<mutex> guard(mtx);
	
	// mtx.lock() // comment/uncomment to use lock
	for (int i=0; i<temp.size(); i++) {
		cout << n << 'X' << (i+1) << " = "<< temp[i] << endl;
	}
	cout<<endl;
	// mtx.unlock() // comment/uncomment to use lock
}


int main()
{
	thread t1(&table, 1);
	thread t2(&table, 10);
	thread t3(&table, 20);
	thread t4(&table, 40);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}