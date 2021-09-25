SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode* temp = llist;   
    if( 0 == position) return llist->next;
    else
    {
        for(int i=0 ; i< position-1 ; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        return llist;
    }
}
