/*
Các nhà địa chất phát hiện một khu mỏ quặng dất hiếm, một thứ rất cần thiết cho công nghiệp chế tạo thiết bị điện tử. 
Khu mỏ có hình chữ nhật kích thước n×m ô. Trữ lượng quặng ở ô (i, j) được đánh giá là 
a(i,j) v (1≤i≤n,1≤j≤m). Cần xây dựng một xí nghiệp làm giàu quặng trước khi đưa ra thị trường. Do điều kiện địa hình, 
xí nghiệp phải xây dựng ngay trên khu mỏ. Xí nghiệp chiếm diện tích 3×3 ô. Dĩ nhiên không thể khai thác quặng dưới nền 
của xí nghiệp, vì vậy người ta muốn tìm vị trí đặt xí nghiệp sao cho tổng trữ lượng phải để lại là ít nhất.
Hãy xác định tổng trữ lượng nhỏ nhất phải để lại.

Dữ liệu vào :
Dòng đầu tiên chứa 2 số nguyên n và m Dòng thứ i trong n dòng sau chứa m số nguyên 
Kết quả: Đưa ra một số nguyên – tổng trữ lượng nhỏ nhất phải để lại.
*/

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//###INSERT CODE HERE -
