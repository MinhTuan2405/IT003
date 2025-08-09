/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
LRN
###End banned keyword*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int info;
    node *left, *right;
};
typedef node* Tree;
node* getNode(int x)
{
    node* p =new node;
    p->info=x;
    p->left=p->right=NULL;
    return p;
}
void insertTree(Tree &T, int x)
{
    if(!T) T=getNode(x);
    else
    {
        if(T->info==x) return;
        if(x<T->info) insertTree(T->left,x);
        else insertTree(T->right, x);
    }

}
void inputTree(Tree &T)
{
    int n,x; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertTree(T, x);
    }
}
void LRN(Tree T)
{

//###INSERT CODE HERE -
    stack <Tree> bucketNode;
    stack <int> bucketData;

    bucketNode.push (T);

    while (!bucketNode.empty ()) {
        Tree current = bucketNode.top ();
        bucketNode.pop ();

        bucketData.push (current -> info);

        if (current -> left) bucketNode.push (current -> left);
        if (current -> right) bucketNode.push (current -> right);
    } 

    while (!bucketData.empty ()) {
        int data = bucketData.top ();
        bucketData.pop ();
        cout << data << " ";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
	Tree T = NULL;
	inputTree(T);
	cout<<"\nLRN: "; LRN(T);
	return 0;
}
