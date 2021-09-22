void reversePrint(SinglyLinkedListNode* llist) {
    stack<int> s;
    SinglyLinkedListNode* temp = llist;
    while(temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return;
}
