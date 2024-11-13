#include <climits>
#include <iostream>
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


void selectionSort(vector<int>& arr, size_t left = 0, size_t right = 0){
    if (right == 0) right = arr.size();
    if (left == right) return;
    int min_elem_index = left;
    for (size_t i = left+1; i < right; i++){
        if (arr[min_elem_index] > arr[i]){
            min_elem_index = i;
        }
    }
    if (min_elem_index == left) return;
    swap(arr[min_elem_index], arr[left]);
    selectionSort(arr, left+1, right);
}


int main(){
    const int size = 1000000;
    vector<int> array = generateRandomArrayMassive(size, 100000000);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    // cout << endl;
    selectionSort(array);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    cout << endl;
    return 0;
}
