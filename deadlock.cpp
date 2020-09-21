#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx1;
mutex mtx2;

int res;

void fun1()
{
    lock_guard<mutex> guard(mtx1);
    cout<<"Thread 1"<<endl;
    fun2();  
    cout<<res<<endl;
}

void fun2()
{
    lock_guard<mutex> guard(mtx2);
    cout<<"Thread 2";
    res++;    
}

int main()
{
    res = 1;
    thread t1(&fun1);
    thread t2(&fun2);

    cout<<"Main Thread\n";

    t1.join();
    t2.join();
    
    return 0;
}