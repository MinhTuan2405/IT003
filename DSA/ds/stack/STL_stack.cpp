/*
Nguyên lý: LIFO (Last In, First Out) – Vào sau ra trước.
Thao tác chính:
    push(): Thêm phần tử vào đỉnh stack.
    pop(): Xóa phần tử ở đỉnh stack.
    top(): Truy cập phần tử ở đỉnh stack.
    empty(): Kiểm tra stack có rỗng không.
    size(): Lấy số lượng phần tử trong stack.
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Thêm phần tử vào stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Các phần tử trong stack (LIFO):" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
