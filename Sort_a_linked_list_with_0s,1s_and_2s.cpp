/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
Node* segregate(Node* head) {
    Node* one_h = new Node(-1);
    Node* two_h = new Node(-1);
    Node* zero_h = new Node(-1);
    Node* one_t = one_h, *two_t = two_h, *zero_t = zero_h;
    
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            zero_t->next = temp;
            temp = temp->next;
            zero_t = zero_t->next;
            zero_t->next = NULL;
        }
        else if(temp->data == 1){
            one_t->next = temp;
            temp = temp->next;
            one_t = one_t->next;
            one_t->next = NULL;
        }
        else{
            two_t->next = temp;
            temp = temp->next;
            two_t = two_t->next;
            two_t->next = NULL;
        }
    }
    
    head = new Node(-2);
    temp = head;
    if(zero_h->next){
        temp->next = zero_h->next;
        temp = zero_t;
    }
    if(one_h->next){
        temp->next = one_h->next;
        temp = one_t;
    }
    if(two_h->next){
        temp->next = two_h->next;
        temp = two_t;
    }
    
    return head->next;
}