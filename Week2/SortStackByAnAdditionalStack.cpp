#include <stack>
stack<int> SortStack( stack<int> s)
{
	// Using a temporary stack and a variable to sort a stack 
	// 34 98 92 31 23 3
	// implementation
	stack<int> temp;
	while(!s.empty())
	{
		// push first variable in stack temp and
		// pop this variable in stack s
		int x = s.top();
		s.pop();
		while( !temp.empty()  && temp.top() > x )
		{
			// Push variables into s until the variable less than x
			s.push(temp.top());
			temp.pop();
		}
		// push into temp
		temp.push(x);
	}
	return temp;
}

