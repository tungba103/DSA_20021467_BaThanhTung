SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    // 1 2 3 4 5 6   :: data = 10; pos = 3
    SinglyLinkedListNode* temp = llist;
    for(int i=0 ; i < position-1 ; i++)
    {
        temp = temp->next;
    }
    
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return llist;
    
}