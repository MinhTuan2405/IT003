#include <iostream>
using namespace std;

struct point {
    float x;
    float y;
    float z;

    // Overload operator ==
    bool operator==(const point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    // Overload operator <
    bool operator<(const point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }

    // Overload operator >
    bool operator>(const point& other) const {
        if (x != other.x) return x > other.x;
        if (y != other.y) return y > other.y;
        return z > other.z;
    }

    // Overload >> for input
    friend istream& operator>>(istream& in, point& p) {
        in >> p.x >> p.y >> p.z;
        return in;
    }

    // Optional: Overload << for output
    friend ostream& operator<<(ostream& out, const point& p) {
        out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return out;
    }
};

template <typename T>
int iterativeBinarySearch(T target, T* array, int size, int& count) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        count++;
        if (array[mid] == target)
            return mid;
        else if (target < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    point* array = new point[n];

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int rep;
    cin >> rep;

    for (int i = 0; i < rep; i++) {
        point target;
        cin >> target;
        int count = 0;
        int pos = iterativeBinarySearch<point>(target, array, n, count);
        if (pos == -1)
            cout << "KHONG" << '\n';
        else
            cout << count << '\n';
    }

    return 0;
}