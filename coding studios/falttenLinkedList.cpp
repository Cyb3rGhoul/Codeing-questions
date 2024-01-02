Node *mergeTwoLinkedlist(Node *a, Node *b){
    Node *temp = new Node(0);

    Node *res = temp;

    while (a != NULL && b != NULL)

    {

        if (a->data < b->data)

        {

            temp->child = a;

            temp = temp->child;

            a = a->child;
        }

        else
        {

            temp->child = b;

            temp = temp->child;

            b = b->child;
        }
    }

    if (a)
    {
        temp->child = a;
    }
    else
    {
        temp->child = b;
    }
    return res->child;
}

Node *flattenLinkedList(Node *head)
{

    if (head == NULL || head->next == NULL)

        return head;

    head->next = flattenLinkedList(head->next);

    Node *b = head->next;

    head->next = NULL;

    head = mergeTwoLinkedlist(head, b);

    return head;
}