#include <stack>
stack<int> SortStack( stack<int> input)
{
	// Using a temporary stack and a variable to sort a stack 
	// 34 98 92 31 23 3
	// implementation
	stack<int> temp;
	while(!input.empty())
	{
		// push first variable in stack temp and
		// pop this variable in stack input
		int x = input.top();
		input.pop();
		while( !temp.empty()  && temp.top() > x )
		{
			// Push variables into stack input until the variable less than x
			input.push(temp.top());
			temp.pop();
		}
		// push into temp
		temp.push(x);
	}
	return temp;
}

