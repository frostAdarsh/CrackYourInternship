/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        while (current != nullptr) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node* newHead = head->next;
        current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            current = current->next;
            if (temp->next != nullptr) {
                temp->next = temp->next->next;
            }
        }

        return newHead;
    }
};