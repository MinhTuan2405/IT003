/*
Bài toán:
Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh. Tuy nhiên, đa phần các hướng dẫn và khóa học 
trên mạng đều hướng dẫn người học cài đặt trên mảng số nguyên trong khi trong thực tế chỉ cần mảng có thể sắp xếp được thì ra có thể áp dụng thuật toán tìm kiếm nhị phân.

Yêu cầu: Hãy cài đặt thuật toán tìm kiếm nhị phân trên mảng chuỗi có N phần tử.

Input :
Dòng đầu tiên là số nguyên N dương (0 < N < 2000)
N dòng tiếp theo chứa các phần tử Ai trong mảng, mỗi phần tử là một chuỗi với độ dài không quá 10. Các phần tử này đã được sắp xếp theo thứ tự bảng chữ cái
Dòng cuối cùng là chuỗi x cần tìm

Output:
Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1
Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này
*/

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
do
for
while
goto
:
###End banned keyword*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//###INSERT CODE HERE -
int bin_search (string a[], int left, int right, string target, int &step) {
    if (left > right) return -1;

    int mid = (left + right) / 2;
    step += 1;
    if (a[mid] == target) {
        return mid;
    }
    else if (a[mid] < target) return bin_search (a, mid + 1, right, target, step);
    else return bin_search (a, left, mid -1, target, step);
}

void instr(string a[], int i, int n) {
    if (i >= n) return;
    getline(cin, a[i]);
    instr(a, i + 1, n);
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n; cin >> n;
    string *a = new string[n];
    cin.ignore ();
    instr(a, 0, n);
    int step = 0;
    string target; getline (cin, target);
    int pos = bin_search (a, 0, n-1, target, step);

    if (pos == -1) cout << -1;
    else {
        cout << pos << '\n' << step;
    }
}