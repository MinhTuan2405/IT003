void remove (node* &root, int data) {
    if (root == NULL) return;

    if (root -> data < data) remove (root -> right, data);
    else if (root -> data > data) remove (root -> left, data);

    else if (root -> data == data) {
        if (!root -> left && !root -> right) {
            delete root;
            root = NULL;
        }

        else if (root -> left == NULL) {
            node* tmp = root;
            root = root -> right;
            delete tmp;
            tmp = NULL;
        }

        else if (root -> right == NULL) {
            node* tmp = root;
            root = root -> left;
            delete tmp;
            tmp = NULL;
        }
        // root -> left && root -> right
        else {
            node* minnode = findmin (root -> right);
            root -> data = minnode -> data;
            remove (root -> right, minnode -> data);
        }
    }
}