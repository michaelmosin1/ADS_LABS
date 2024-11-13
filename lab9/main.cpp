#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> generateRandomArrayMassive(size_t size, size_t maxValue)
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    srand(now.tv_nsec);
    vector<int> arr(size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand()%maxValue;
    }
    return arr;
}


void heapify(vector<int>& arr, size_t n, size_t i) {
    size_t root = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && arr[left] > arr[root]) {
        root = left;
    }
    if (right < n && arr[right] > arr[root]) {
        root = right;
    }
    if (root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}


void heapSort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (size_t i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    const int size = 10;
    vector<int> array = generateRandomArrayMassive(size, 100000000);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    // cout << endl;
    heapSort(array);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    cout << endl;
    return 0;
}
