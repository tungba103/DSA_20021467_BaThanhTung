#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> SortQueue( queue<int> input)
{
	stack<int> temp;
	int size = input.size();
	for(int i=0 ; i< size ; i++)
	{
		temp.push(input.front());
		input.pop();
		for(int i=0 ; i< size-1 ; i++)
		{
			if( temp.top() < input.front() )
			{
				int x = input.front();
				input.push(temp.top());
				temp.pop();
				temp.push(x);
				input.pop();
			}
			else
			{
				temp.push(input.front());
				input.push(temp.top());
				temp.pop();
				input.pop();
				
			}
		}
		input.push(temp.top());
		temp.pop();	
		}
	return input;	
}

//int main()
//{
//	queue<int> q;
//	q.push(34);
//	q.push(3);
//	q.push(31);
//	q.push(98);
//	q.push(92);
//	q.push(23);
//	q = SortQueue(q);
//	while(!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	return 0;
//}
