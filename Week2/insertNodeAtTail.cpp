SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    } 
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    temp->next = newNode;
    return head;
}
