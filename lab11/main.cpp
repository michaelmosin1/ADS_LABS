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


void quickSort(vector<int> arr, size_t start = 0, size_t end = 0)
{
    if (end == 0) end = arr.size();
	if (start >= end) return;
	int pivot = arr[(start+end)/2];
	size_t i = start;
	size_t j = end;
	while (i <= j)
    {
        while (arr[i] < pivot && i < end) i++;
        while (arr[j] > pivot && j > start) j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            if (i != end) i++;
            if (j != start) j--;
        }
	}
	quickSort(arr, start, j);
	quickSort(arr, i, end);
}


int main(){
    const int size = 10;
    vector<int> array = generateRandomArrayMassive(size, 100000000);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    // cout << endl;
    quickSort(array);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    cout << endl;
    return 0;
}