#include <bits\stdc++.h>

using namespace std;

template <typename T>
int recursiveBinarySearch (T target, T* array, int left, int right) {
    int mid = (right + left) / 2;
    if (left > right) return -1;
    if (array[mid] == target) return mid;
    if (target < array[mid]) return recursiveBinarySearch (target, array, left, mid -1);
    else if (target > array[mid]) return recursiveBinarySearch (target, array, mid + 1, right);
}

template <typename T>
int iterativeBinarySearch (T target, T* array, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == target) return mid;
        if (target < array[mid]) right = mid -1;
        else if (target > array[mid]) left = mid + 1;
    }

    return -1; // if not find
}

int main () {
    int n;
    cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> *(array + i);
    }

    int target;
    cin >> target;

    cout << recursiveBinarySearch <int> (target, array, 0, n-1) << '\n';
    cout << iterativeBinarySearch <int> (target, array, n);

    return 0;
}

