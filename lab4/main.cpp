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


void combSort(vector<int>& array, size_t n)
{
	double factor = 1.25;
	int step = n - 1;
	while (step >= 1)
	{
		for (int i = 0; i + step < n; i++)
		{
			if (array[i] > array[i + step])
			{
				swap(array[i], array[i + step]);
			}
		}
		step /= factor;
	}
}

int main(){
    const int size = 1000000;
    vector<int> array = generateRandomArrayMassive(size, 100000000);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    // cout << endl;
    combSort(array, size);
    // for (size_t i = 0; i < 10; i++){
    //     cout << array[i] << ' ';
    // }
    cout << endl;
    return 0;
}
