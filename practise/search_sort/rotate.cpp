/*
Trong một buổi sinh hoạt ngoại khóa, có N sinh viên, mỗi sinh viên có mã số sinh viên là a[i]
,  và được xếp thành vòng tròn theo để chơi trò chơi. Ban đầu, sinh viên có mã số a[i]
 sẽ đứng ở vị trí thứ i , các vị trí này được sắp xếp từ 1 đến N theo chiều kim đồng hồ. Người quản trò sẽ hô 
 một số nguyên K bất kì, thì vòng tròn sẽ xoay K lần theo chiều kim đồng hồ.  

Ví dụ: Có 5 bạn có mssv lần lượt là  [122, 123, 124, 125, 126] và K = 2.
Ban đầu, các bạn [122, 123, 124, 125, 126] đứng tương ứng với các vị trị từ 1 đến N.
Sau lần xoay đầu tiên, thì các bạn có sự thay đổi về vị trí như sau:
 Bạn 122 sẽ từ vị trí 1 sang vị trí 2.
 Bạn 123 sẽ từ vị trí 2 sang vị trí 3.

….

Bạn 126 sẽ từ vị trí 5 sang vị trí 1.
Tương tự, với lần xoay thứ 2 thì các bạn lần lượt là [125, 126, 122, 123, 124].
*/


/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//###INSERT CODE HERE -
vector<int> rotate(vector<int> a, int repeat) {
    int n = a.size();
    vector<int> transform;

    repeat %= n; 

    for (int i = 0; i < n; ++i) {
        int new_el = a.at((i - repeat + n) % n);
        transform.push_back(new_el);
    }

    return transform;
}


int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n, repeat;
    cin >> n >> repeat;

    vector <int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back (x);
    }

    vector <int> res = rotate (a, repeat);

    for (int el : res) cout << el << " ";
    return 0;
}