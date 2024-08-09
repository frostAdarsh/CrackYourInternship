/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return nullptr;

        Node* current = head;

        while (current) {
            if (current->child) {
                Node* child = current->child;
                Node* next = current->next;

                Node* flattenedChild = flatten(child);

                current->next = flattenedChild;
                flattenedChild->prev = current;
                current->child = nullptr;

                Node* tail = flattenedChild;
                while (tail->next) {
                    tail = tail->next;
                }

                if (next) {
                    tail->next = next;
                    next->prev = tail;
                }
            }
            current = current->next;
        }

        return head;
    }
};