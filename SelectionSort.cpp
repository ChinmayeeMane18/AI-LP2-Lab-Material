#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        // Find the minimum element in the remaining unsorted part of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr;

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
