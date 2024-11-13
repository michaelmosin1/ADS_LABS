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


void shellSort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; i++) {
            int temp = arr[i];
            size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}


int main(){
    const int size = 10;
    vector<int> array = generateRandomArrayMassive(size, 100000000);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    // cout << endl;
    shellSort(array);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    cout << endl;
    return 0;
}
