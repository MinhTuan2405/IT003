/*
Nguyên lý: FIFO (First In, First Out) – Vào trước ra trước.
Thao tác chính:
    push(): Thêm phần tử vào cuối queue.
    pop(): Xóa phần tử ở đầu queue.
    front(): Truy cập phần tử ở đầu queue.
    back(): Truy cập phần tử ở cuối queue.
    empty(): Kiểm tra queue có rỗng không.
    size(): Lấy số lượng phần tử trong queue.
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myQueue;

    // Thêm phần tử vào queue
    myQueue.push(5);
    myQueue.push(10);
    myQueue.push(15);

    cout << "Các phần tử trong queue (FIFO):" << endl;
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}
