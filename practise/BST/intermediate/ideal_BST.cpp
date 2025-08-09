/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct tree {
    int data;
    tree* left;
    tree* right;
};

void init (tree* &tr) {
    tr = NULL;
    return;
}

tree* makenode(int data) {
    tree* tr = new tree;
    tr -> data = data;
    tr -> left = NULL;
    tr -> right = NULL;
    return tr;
}

void insert (tree* &tr, int newdata) {
    if (tr == NULL) {
        tr = makenode (newdata);
        return;
    }

    if (newdata < tr -> data) insert (tr -> left, newdata);
    else if (newdata > tr -> data) insert (tr -> right, newdata);

    return;
}

bool checkPerfect(tree* tr, int depth, int &leafDepth) {
    if (tr == NULL) return true;

    // Nếu là lá
    if (tr->left == NULL && tr->right == NULL) {
        if (leafDepth == -1) {
            leafDepth = depth; // lưu mức lá đầu tiên
        }
        return leafDepth == depth;
    }

    // Nếu thiếu con → không lý tưởng
    if (tr->left == NULL || tr->right == NULL) return false;

    // Kiểm tra tiếp cả 2 nhánh
    return checkPerfect(tr->left, depth + 1, leafDepth) &&
           checkPerfect(tr->right, depth + 1, leafDepth);
}

bool check(tree* tr) {
    int leafDepth = -1;
    return checkPerfect(tr, 0, leafDepth);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tree* T;
    init(T);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(T, x);
    }

    if (check(T)) cout << "YES";
    else cout << "NO";

    return 0;
}