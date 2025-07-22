---

## ✅ 1. `vector` là gì?

* `vector` là một **mảng động** (dynamic array) trong C++, thuộc thư viện STL (`#include <vector>`).
* Nó có khả năng **tự động thay đổi kích thước** khi thêm/xóa phần tử.
* Truy cập phần tử qua chỉ số như mảng (`v[i]`) nhưng hỗ trợ nhiều **hàm tiện ích** hơn.

---

## 📚 2. Cách khai báo và khởi tạo

```cpp
#include <vector>

std::vector<int> v1;                    // vector rỗng
std::vector<int> v2(5);                 // vector 5 phần tử, giá trị mặc định 0
std::vector<int> v3(5, 100);            // vector 5 phần tử, mỗi phần tử là 100
std::vector<int> v4 = {1, 2, 3, 4};     // khởi tạo danh sách
```

---

## 🔧 3. Một số phương thức quan trọng

| Phương thức        | Mô tả                         |
| ------------------ | ----------------------------- |
| `push_back(val)`   | Thêm phần tử vào cuối vector  |
| `pop_back()`       | Xóa phần tử cuối              |
| `size()`           | Trả về số phần tử             |
| `empty()`          | Trả về true nếu vector rỗng   |
| `clear()`          | Xóa toàn bộ phần tử           |
| `resize(n)`        | Thay đổi kích thước vector    |
| `front()`          | Phần tử đầu tiên              |
| `back()`           | Phần tử cuối cùng             |
| `insert(pos, val)` | Chèn giá trị tại vị trí `pos` |
| `erase(pos)`       | Xóa phần tử tại vị trí `pos`  |
| `begin(), end()`   | Trả iterator tới đầu/cuối     |
| `[]` hoặc `at(i)`  | Truy cập phần tử theo chỉ số  |

---

## 🧪 4. Ví dụ minh họa

```cpp
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
```

---

## 💡 5. Một số lưu ý khi dùng `vector`

* **Truy cập an toàn**: Dùng `at(i)` thay vì `v[i]` nếu bạn muốn bắt lỗi truy cập ngoài phạm vi.
* **Hiệu suất**: Tránh `insert()` và `erase()` ở giữa vector nếu thao tác nhiều, vì phải dịch phần tử.
* **Dọn bộ nhớ**:

  * `v.clear()` chỉ xóa phần tử nhưng không giảm dung lượng bộ nhớ.
  * Dùng `vector<int>().swap(v)` để giải phóng hoàn toàn.

---

## ⚙️ 6. Duyệt vector

```cpp
// Cách 1: dùng chỉ số
for (int i = 0; i < v.size(); i++) {
    cout << v[i];
}

// Cách 2: for-each
for (int x : v) {
    cout << x;
}

// Cách 3: iterator
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it;
}
```

---
