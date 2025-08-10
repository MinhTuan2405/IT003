/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
bool checkBST(Node* root) {
//###INSERT CODE HERE -
        stack <Node*> bucket;
        vector <int> value;
        Node* current = root;
        while (!bucket.empty () || current) {
            while (current) {
                bucket.push (current);
                current = current -> left;
            }

            Node* top = bucket.top ();
            value.push_back (top -> data);
            bucket.pop ();
            current = top -> right;
        }

        if (value.size () <= 1) return true;

        for (int i = 1; i < value.size (); ++i) {
            if (value[i] <= value[i-1]) return false;
        }

        return true;
}


}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    std::cout<<myTree.checkBST(root);

    return 0;
}