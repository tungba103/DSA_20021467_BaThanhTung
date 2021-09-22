#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createdQueue(int data)
{
	Node* queue = new Node;
	queue->next = NULL;
	queue->data = data;
	return queue;	
}

Node* enqueue( Node* queue, int data)
{
	Node* temp = queue;
	while(temp->next) temp = temp->next;
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	temp->next = newNode;
	return queue;
}

Node* dequeue( Node* queue)
{
	return queue->next;
}

int main()
{
	string instruction;
	int n,x;
	cin >> n;
	cin >> instruction >> x;
	Node* queue = new Node;
	queue->data = x;
	queue->next = NULL;
	for(int i=0 ; i < n-1; i++)
	{
		cin >> instruction;
		if( instruction == "enqueue")
		{
			cin >> x;
			queue = enqueue(queue,x);
		}
		else 
		{
			queue = dequeue(queue);
		}
	}
	while(queue)
	{
		cout << queue->data << " ";
		queue = queue->next;
	}
	return 0;
}
