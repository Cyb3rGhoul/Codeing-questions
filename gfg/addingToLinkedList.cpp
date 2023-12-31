class Solution
{
public:
    // Function to add two numbers represented by linked list.

    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *curr = NULL;
        Node *prev = NULL;
        Node *temp = head;

        while (temp != NULL)
        {
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }

    Node *add(Node *first, Node *second)
    {
        int carry = 0;
        Node *ans = NULL;
        Node *temp = NULL;
        while (first != NULL || second != NULL || carry)
        {
            int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

            carry = sum / 10;

            Node *newNode = new Node(sum % 10);
            if (!ans)
            {
                ans = newNode;
                temp = ans;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }

            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }

        return ans;
    }

    Node *addTwoLists(Node *first, Node *second)
    {
        first = reverse(first);
        second = reverse(second);

        return reverse(add(first, second));
    }
};
