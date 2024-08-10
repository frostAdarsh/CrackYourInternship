
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}




struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; 
    }
};

class Solution {
public:
    
    Node* flatten(Node* root) {
        if (root == nullptr) return nullptr;

        
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        
        Node* temp = root;
        while (temp != nullptr) {
            minHeap.push(temp);
            temp = temp->next;
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

     
        while (!minHeap.empty()) {
            Node* node = minHeap.top();
            minHeap.pop();

            tail->bottom = node;
            tail = tail->bottom;

            if (node->bottom != nullptr) {
                minHeap.push(node->bottom);
            }
        }

        
        Node* flattenedList = dummy->bottom;
        delete dummy; 
        return flattenedList;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); 
        getline(cin, input); 
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

