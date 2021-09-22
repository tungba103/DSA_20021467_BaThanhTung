SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* pre = llist;
    SinglyLinkedListNode* now =llist->next;
    SinglyLinkedListNode* temp = llist->next;
    pre->next = nullptr;
    while(now->next)
    {
        temp = temp->next;
        now->next = pre;
        pre = now;
        now = temp;
    }
    now->next = pre;
    return now;
}
