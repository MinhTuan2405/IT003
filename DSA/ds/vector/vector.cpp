#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);       // thêm 40
    v.insert(v.begin() + 1, 15); // chèn 15 tại vị trí thứ 1

    cout << "Các phần tử trong vector: ";
    for (int val : v) {
        cout << val << " ";
    }
    cout << "\n";

    v.pop_back();          // xóa phần tử cuối
    v.erase(v.begin() + 2); // xóa phần tử ở vị trí thứ 2

    cout << "Sau khi xóa: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    cout << "Kích thước vector: " << v.size() << endl;
    cout << "Phần tử đầu tiên: " << v.front() << ", cuối: " << v.back() << endl;

    return 0;
}
