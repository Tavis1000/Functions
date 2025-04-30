/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        int ans = 1;
        Node* one = head;
        Node* two = head;
        do{
            if(two==NULL || two->next==NULL)    return 0;
            one = one->next;
            two = two->next->next;
        }while(two != one);
        one = one->next;
        two = two->next->next;
        while(one != two){
            one = one->next;
            two = two->next->next;
            ans++;
        }
        return ans;
    }
};