// Q5: Implement Heap Sort (Increasing / Decreasing order).

#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i; // For increasing: largest element, for decreasing: smallest element
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing) {
        // Build max heap for increasing order
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        // Build min heap for decreasing order
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // If root is not the extreme element, swap and continue heapifying
    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, increasing);
    }
}

// Main Heap Sort function
void heapSort(int arr[], int n, bool increasing = true) {
    // Step 1: Build the heap (max heap for increasing, min heap for decreasing)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "Enter 1 for Increasing order or 2 for Decreasing order: ";
    cin >> choice;

    bool increasing = (choice == 1);

    // Perform heap sort based on user's choice
    heapSort(arr, n, increasing);

    // Display the sorted array
    cout << "\nArray after Heap Sort (" 
         << (increasing ? "Increasing" : "Decreasing") << " order): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
