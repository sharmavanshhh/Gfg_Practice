/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    
    Node* reverseList(Node* head) {
        if(!head || !head->next){
            return head;
        }

        Node* Prev = nullptr;
        Node* current = head;

        while(current){
            Node* Next = current->next;
            current->next = Prev;
            Prev = current;
            current = Next;
        }
        return Prev;
    }
    
    Node* addTwoLists(Node* l1, Node* l2) {
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        Node* dummy = new Node(0);
        Node* cur = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->data; l1 = l1->next; }
            if (l2) { sum += l2->data; l2 = l2->next; }

            carry = sum / 10;
            cur->next = new Node(sum % 10);
            cur = cur->next;
        }

        dummy->next = reverseList(dummy->next);
        Node* temp = dummy->next;
        while(temp->data == 0){
            temp = temp->next;
        }
        
        return temp;
    }
};