#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *previous;
};

Node* createdDoublyLinkedList(int data){
	Node* res = new Node;
	res->data = data;
	res->next = NULL;
	return res;
}

Node* insertNodeLast( Node* head, int data)
{
	Node* temp = head; // 1 2 3 4
	while(temp->next)
	{
		temp = temp->next;
	}
	
		Node* newNode = new Node;
		newNode->data = data;	
		newNode->next = NULL;
		newNode->previous = temp;
		temp->next = newNode;
		return head;	
}

int main()
{
	int n,x;
	cin >> n;
	cin >> x;
	Node *head = createdDoublyLinkedList(x);
	for(int i=0 ; i< n-1 ; i++)
		{
			cin >> x;
			head = insertNodeLast(head,x);
		}
	
	int count=0;
	Node* temp = head->next;
	while(temp->next)	
		{
			if( (temp->previous->data + temp->data + temp->next->data) == 0) count++;
			temp = temp->next;
		}
	while(head)
	{
		cout << head->data << " ";
		head= head->next;
	}
	
	cout << count << endl;
	
	return 0;
}
