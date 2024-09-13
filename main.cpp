#include<bits/stdc++.h> 
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <chrono>   // For measuring time

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(vector<int>arr, int size) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 1000000;
    vector<int> arr(SIZE);

    // Initialize random seed
    srand(time(0));

    // Generate random numbers between 1 and 100000
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000000 + 1;
    }

    // Print unsorted array
    cout << "Unsorted array:" << endl;
    // Uncomment if you want to print the unsorted array
    printArray(arr, SIZE);

    // Measure the time taken for Quick Sort
    auto start = high_resolution_clock::now(); // Start time

    // Perform Quick Sort
    quickSort(arr, 0, SIZE - 1);

    auto stop = high_resolution_clock::now();  // End time
    auto duration = duration_cast<milliseconds>(stop - start); // Calculate duration

    // Print sorted array
    cout << "\nSorted array:" << endl;
    // Uncomment if you want to print the sorted array
    printArray(arr, SIZE);

    // Print the total time taken by the Quick Sort
    cout << "\nTime taken by Quick Sort: " << duration.count() << " milliseconds" << endl;

    return 0;
}
