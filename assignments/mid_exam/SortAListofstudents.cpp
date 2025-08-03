/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct DATE
{
    int day, month, year;
};
typedef struct STUDENT
{
    string id,name;
    DATE dob;
    float math, phy, chem, aver;

} SV;


void outputStudent(SV x)
{
    cout << x.id << "\t|" << x.name << "\t|";
    cout << x.dob.day << "/" << x.dob.month << "/" << x.dob.year << "\t|";
    cout << x.math << "\t|" << x.phy << "\t|" << x.chem << "\t|" << x.aver;
    cout << endl;

}
void inputStudent(SV &b);

//###INSERT CODE HERE -
struct node {
    SV data;
    node* next;
};

struct List {
    node* head, * tail;
};

void init(List& L) {
    L.head = L.tail = NULL;
}

node* createNode(SV sv) {
    node* p = new node;
    if (p) {
        p->data = sv;
        p->next = NULL;
    }
    return p;
}

void inputStudent(SV& b) {
    cin.ignore();
    getline(cin, b.id);
    getline(cin, b.name);
    cin >> b.dob.day >> b.dob.month >> b.dob.year;
    cin >> b.math >> b.phy >> b.chem;
    b.aver = (b.math + b.phy + b.chem) / 3.0;
}

void addLast(List& L, SV sv) {
    node* p = createNode(sv);
    if (!L.head) L.head = L.tail = p;
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputListStudents(List& L, int n) {
    for (int i = 0; i < n; ++i) {
        SV x;
        inputStudent(x);
        addLast(L, x);
    }
}

void outputListStudents(List L) {
    for (node* p = L.head; p != NULL; p = p->next) {
        outputStudent(p->data);
    }
}


void sortbyName(List& L) {
    for (node* p = L.head; p != NULL; p = p->next) {
        for (node* q = p->next; q != NULL; q = q->next) {
            if (p->data.name > q->data.name) {
                SV tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

int main()
{
    int n; cin>>n;
    List L;init (L);
    inputListStudents(L,n);
    sortbyName(L);
    cout<<"\nList of students sorted: ";
    cout<<"\nID\t|Fullname\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    outputListStudents(L);

    return 0;
}

