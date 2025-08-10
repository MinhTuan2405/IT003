
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
struct hash_table {
    int* table;
    int bucket_size;

    hash_table(int size) {
        bucket_size = size;
        table = new int[bucket_size];
        for (int i = 0; i < bucket_size; i++) table[i] = -1;
    }

    int hashkey(int value) {
        return value; // ở đây key chính là value
    }

    bool exists(int value) {
        int idx = hashkey(value);
        return (table[idx] == value);
    }

    void insert(int value) {
        int idx = hashkey(value);
        table[idx] = value;
    }

    ~hash_table() { // Giải phóng bộ nhớ động
        delete[] table;
    }
};

void inputArray (int a[], int& n) { 
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
}

void printArray (int a[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
}

void removeDups(int a[], int n) {
    // Tìm giá trị lớn nhất trong mảng
    int maxVal = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxVal) maxVal = a[i];
    }

    // Tạo bảng băm với kích thước = maxVal + 1
    hash_table tab(maxVal + 1);

    for (int i = 0; i < n; ++i) {
        if (!tab.exists(a[i])) {
            tab.insert(a[i]);
        }
    }

    // In các phần tử xuất hiện lần đầu (theo thứ tự giá trị tăng dần)
    for (int i = 0; i <= maxVal; ++i) {
        if (tab.table[i] != -1) std::cout << tab.table[i] << " ";
    }
    std::cout << '\n';
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
