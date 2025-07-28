#include <iostream>
#include <cmath>
using namespace std;


bool checkPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= n/2; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


struct Node {
    int data;
    Node* l;
    Node* r;
};

typedef Node* Tree;

Tree makeNode (int x) {
    Tree n = new Node;
    n -> data = x;
    n -> l = NULL;
    n -> r = NULL;
    return n;
}

void insert(Tree &t, int x, bool &out) {
    if (t == NULL) {
        t = makeNode (x); 
        return;
    }

    if (t->data == x) out = true; 
    else if (x < t->data) insert(t->l, x, out);
    else insert(t->r, x, out);
}

void inputTree(Tree &t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        bool out = false;
        insert(t, x, out);
        if (out) {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            return;
        }
    }
}

void LNR(Tree t) {
    if (t == NULL) return;
    LNR(t->l);
    cout << t->data << " ";
    LNR(t->r);
}

int countNodes (Tree t) {
    if (t == NULL) return 0;
    return 1 + countNodes (t -> l) + countNodes (t -> r);
}


int depthOfTree (Tree t) {
    if (t == NULL) return -1;
    int leftHeight = depthOfTree (t -> l);
    int rightHeight = depthOfTree (t -> r);
    return 1 + max (leftHeight, rightHeight);
}

void countEven (Tree t, int &cnt) {
    if (t == NULL) return;
    if (t -> data % 2 == 0) cnt +=1;
    countEven (t -> l, cnt);
    countEven (t -> r, cnt);
}

void countOdd (Tree t, int &cnt) {
    int evn_cnt = 0;
    countEven (t, evn_cnt);
    cnt = countNodes (t) - evn_cnt;
}

int countZero (Tree t) {
    if (t == NULL) return 0;
    int cnt = 0;
    if (t -> data == 0) cnt += 1;
    return cnt + countZero (t -> l) + countZero (t -> r);
}

int countPositive (Tree t) {
    if (t == NULL) return 0;
    int cnt = 0;
    if (t -> data > 0) cnt += 1;
    return cnt + countPositive (t -> l) + countPositive (t -> r);
}

int countNegative (Tree t) {
    return countNodes (t) - countZero (t) - countPositive (t);
}

int countPrime (Tree t) {
    if (t == NULL) return 0;
    int cnt = 0;
    if (checkPrime (t -> data)) cnt += 1;
    return countPrime (t -> l) + countPrime (t -> r) + cnt;
}

void listPrime (Tree t) {
    if (t == NULL) return;
    if (checkPrime (t -> data)) cout << t -> data << " ";
    listPrime (t -> l);
    listPrime (t -> r);
}




int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
