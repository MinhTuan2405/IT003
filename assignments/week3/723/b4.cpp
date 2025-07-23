
#include <iostream>
#include <stack>

using namespace std;

void DecimaltoBinary(int n)
{
    stack<int> S;
    if (n == 0) {
        S.push (0);
    }

    while (n) {
        int a = n % 2;
        S.push (a);
        n /= 2;
    }

    while (!S.empty ()) {
        cout << S.top ();
        S.pop ();
    }

}


int main()
{

    int n;
    cin>>n;
    DecimaltoBinary(n);
    return 0;
}



