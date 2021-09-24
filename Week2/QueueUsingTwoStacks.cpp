#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> DequeueAction( stack<int> enqueue)
{
	stack<int> Dequeue;
	while(!enqueue.empty())
	{
		Dequeue.push(enqueue.top());
		enqueue.pop();
	}
	if(!Dequeue.empty())Dequeue.pop();
	return Dequeue;
}

stack<int> Reverse( stack<int> dequeue)
{
	stack<int> queue;
	while(!dequeue.empty())
	{
		queue.push(dequeue.top());
		dequeue.pop();
	}
	return queue;
}

int main() {
    // 6 5 4 3 2 1
    stack<int> dequeueAndPrint;
    stack<int> enqueue;
    int n,x;
    cin >> n;
    for(int i=0 ; i< n ; i++)
    {
    	cin >> x;
    	switch(x){
    		case 1:
    			int value;
    			cin >> value;
    			enqueue.push(value);
    			break;
    		case 2:
    			dequeueAndPrint = DequeueAction(enqueue);
    			enqueue = Reverse(dequeueAndPrint);
    			break;
    		case 3:
    			dequeueAndPrint = Reverse(enqueue);
    			cout << dequeueAndPrint.top() << endl;
    			break;
		}
	}
    return 0;
}

