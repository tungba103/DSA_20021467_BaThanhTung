#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createdStack(int data)
{
	Node* head = new Node;
	head->data =data;
	head->next = NULL;
}

Node* pushStack(Node* head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	
	Node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* popStack(Node* head)
{
	Node* temp = head;
	while(temp->next->next)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}

int main()
{
	string instruction;
	int n,x;
	cin >> n;
	cin >> instruction >> x;
	Node* stack = new Node;
	stack->data = x;
	stack->next = NULL;
	for(int i=0 ; i < n-1; i++)
	{
		cin >> instruction;
		if( instruction == "push")
		{
			cin >> x;
			stack = pushStack(stack,x);
		}
		else 
		{
			stack = popStack(stack);
		}
	}
	while(stack)
	{
		cout << stack->data << " ";
		stack = stack->next;
	}
	return 0;
}
