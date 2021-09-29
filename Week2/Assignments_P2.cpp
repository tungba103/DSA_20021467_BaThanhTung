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

Node* insertNode( Node* head, int position, int data)
{
	if( 0 == position)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->previous = NULL;
		if( head == NULL)
		{
			newNode->next = NULL;	
		}
		else
		{
			newNode->next = head;
			head->previous = newNode;
		}
		return newNode;
	}
	else
	{
		Node* temp = head; // 1 2 3 4 ( position = 3||4)
		for(int i=0 ; i< position -1 ; i++)
			{
				temp = temp->next;
			}
		
		if(!(temp->next))
		{
			Node* newNode = new Node;
			newNode->data = data;
			temp->next = newNode;
			newNode->previous = temp;
			newNode->next = NULL;	
		}
		else
		{
			Node* newNode = new Node;
			newNode->data = data;	
			newNode->next = temp->next;
			newNode->previous = temp;
			Node* secondTemp = temp->next;
			secondTemp->previous = newNode;
			temp->next = newNode;

		}
			return head;
	}
	
}
Node* deleteNode( Node*head, int position){
	if( 0 == position)
	{
		head->next->previous = NULL;
		return head->next;
	}
	else{
		Node* temp = head; // 1 2 3 4 ( position = 2||3||4)
		for(int i=0 ; i< position -1 ; i++)
			{
				temp = temp->next;
			}
		temp->next->next->previous = temp;
		temp->next= temp->next->next;
		
		return head;		
	}
}

int main()
{
	int n;
	cin >> n;
	int a,b;
	string instruction="";
	cin >> instruction;
	cin >> a >> b;
	Node* head = createdDoublyLinkedList(b);
	for(int i=0 ; i< n -1 ; i++ )
	{
		cin >> instruction;
		if( instruction == "insert")
		{
			cin  >> a >> b;
			head = insertNode(head,a,b);
		}
		else
		{
			cin >> a;
			head = deleteNode(head,a);
		}
	}

	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	return 0;
}
