SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;
	SinglyLinkedListNode* temp1 = head1;
	SinglyLinkedListNode* temp2 = head2;
	SinglyLinkedListNode* res = temp1;

	if( temp1->data > temp2->data)
	{
		res = temp2;
		temp2 = temp2->next;
	}
	else temp1 = temp1->next;
	SinglyLinkedListNode* resFinal = res;
	while(temp1 && temp2)
	{
		if(temp1->data > temp2->data)
		{
			res->next = temp2;
			temp2 = temp2->next;

		}
		else
		{
			res->next = temp1;
			temp1 = temp1->next;
		}
			res = res->next;
	}

	while(temp1)
	{
		res->next = temp1;
		temp1 = temp1->next;
		res = res->next;
	}
	while(temp2)
	{
		res->next = temp2;
		temp2 = temp2->next;
		res = res->next;
	}
	return resFinal;
}