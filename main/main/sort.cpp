#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int RandomizedPartition(vector<int>& arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return Partition(arr, low, high);
}

void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = RandomizedPartition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
