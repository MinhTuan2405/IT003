#include <iostream>
using namespace std;

int count = 0;

void quicksort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    int left = low;
    int right = high;

    while (left <= right) {
        while (arr[left] > pivot) left++;
        while (arr[right] < pivot) right--;


        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
            count++;
        }
    }

    if (low < right)
        quicksort(arr, low, right);
    if (left < high)
        quicksort(arr, left, high);
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    quicksort(a, 0, n - 1); 

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';

    cout << "Number of times to swap 2 numbers: " << count << '\n';

    return 0;
}

// 6
// 5 1 2 0 9 4