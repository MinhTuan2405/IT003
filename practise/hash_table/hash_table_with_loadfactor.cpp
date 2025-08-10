/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node *head, *tail;

};
struct Hash
{
    int m;
    int n;
    float load;
    List *pL; //con tro quan ly 1 mang chua cac List
};

//###INSERT CODE HERE -
void initList(List &L) {
    L.head = L.tail = NULL;
}

node* createNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addTail(List &L, int x) {
    node* p = createNode(x);
    if (L.head == NULL) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void initHash(Hash &H) {
    H.pL = new List[H.m];
    for (int i = 0; i < H.m; i++) {
        initList(H.pL[i]);
    }
    H.n = 0;
}

int hashFunction(Hash &H, int key) {
    return key % H.m;
}

void insertHash(Hash &H, int key) {
    if ( (float)(H.n + 1) / H.m > H.load ) {
        return;
    }
    int idx = hashFunction(H, key);
    addTail(H.pL[idx], key);
    H.n++;
}

void inputHash(Hash &H, int n) {
    initHash(H);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertHash(H, x);
    }
}

void printHash(Hash &H) {
    for (int i = 0; i < H.m; i++) {
        cout << "List " << i << ":";
        node* p = H.pL[i].head;
        bool first = true;
        while (p != NULL) {
            if (first) {
                cout << " " << p->info;
                first = false;
            } else {
                cout << " " << p->info;
            }
            p = p->next;
        }
        cout << "\n";
    }
}

void searchHash(Hash &H, int key) {
    int idx = hashFunction(H, key);
    node* p = H.pL[idx].head;
    int count = 1;
    while (p != NULL) {
        if (p->info == key) {
            cout << count << "\n";
            return;
        }
        p = p->next;
        count++;
    }
    cout << "KHONG\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    Hash H;  cin>>H.m>>H.load;
    int n;cin>>n;
    inputHash(H,n);
    printHash(H);
    int nkey,key;cin>>nkey;

    for(int i=0;i<nkey;i++)
    {
        cin>>key;
        searchHash(H,key);
    }
    return 0;
}
