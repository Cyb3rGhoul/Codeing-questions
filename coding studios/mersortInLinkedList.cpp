node* findMid(node* head){
    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL && fast->next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

node* merge(node* left, node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;


    //merging two sorted linked list
    while(left!=NULL && right !=NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left!=NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while(right!=NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}
node* mergeSort(node *head) {
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //break linked list into two halves, after finding the mid
    node* mid = findMid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;


    // recursive call to sort both the halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge the two linked list
    node* ans = merge(left, right);

    return ans;
}