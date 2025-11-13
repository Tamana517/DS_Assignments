// Q6: Implement priority queues using heaps.

#include <iostream>
#include <vector>
#include <climits>   // for INT_MIN
using namespace std;

class MaxHeap {
    vector<int> A;  // 1-based indexing: A[0] unused
    int heap_size;

public:
    MaxHeap() {
        A.push_back(-1); // dummy element at index 0
        heap_size = 0;
    }

    // Return index of parent and children
    int PARENT(int i) { return i / 2; }
    int LEFT(int i) { return 2 * i; }
    int RIGHT(int i) { return 2 * i + 1; }

    // Restore max-heap property at index i
    void MAX_HEAPIFY(int i) {
        int l = LEFT(i);
        int r = RIGHT(i);
        int largest = i;

        // Find the largest among parent and children
        if (l <= heap_size && A[l] > A[i])
            largest = l;
        if (r <= heap_size && A[r] > A[largest])
            largest = r;

        // If parent is not largest, swap and continue heapifying
        if (largest != i) {
            int temp = A[i];   // manual swap
            A[i] = A[largest];
            A[largest] = temp;
            MAX_HEAPIFY(largest);
        }
    }

    // Return the maximum element
    int HEAP_MAXIMUM() {
        if (heap_size < 1) {
            cout << "Heap is empty\n";
            return -1;
        }
        return A[1];
    }

    // Remove and return the maximum element
    int HEAP_EXTRACT_MAX() {
        if (heap_size < 1) {
            cout << "Heap underflow\n";
            return -1;
        }
        int max = A[1];          // store current max
        A[1] = A[heap_size];     // move last element to root
        heap_size--;
        A.pop_back();             // remove last element
        MAX_HEAPIFY(1);           // fix heap property
        return max;
    }

    // Increase the key at index i to 'key'
    void HEAP_INCREASE_KEY(int i, int key) {
        if (i < 1 || i > heap_size) {
            cout << "Invalid index\n";
            return;
        }
        if (key < A[i]) {
            cout << "New key is smaller than current key\n";
            return;
        }
        A[i] = key;
        // Bubble up the element until heap property is restored
        while (i > 1 && A[PARENT(i)] < A[i]) {
            int temp = A[i];           // manual swap with parent
            A[i] = A[PARENT(i)];
            A[PARENT(i)] = temp;
            i = PARENT(i);
        }
    }

    // Insert a new key into the heap
    void MAX_HEAP_INSERT(int key) {
        heap_size++;
        A.push_back(INT_MIN);      // placeholder for new key
        HEAP_INCREASE_KEY(heap_size, key);
    }

    // Display heap elements
    void DISPLAY_HEAP() {
        if (heap_size == 0) {
            cout << "Heap is empty\n";
            return;
        }
        cout << "Heap elements: ";
        for (int i = 1; i <= heap_size; i++)
            cout << A[i] << " ";
        cout << "\n";
    }
};

int main() {
    // Priority Queue Implementation using Max Heap
    MaxHeap PQ;  // heap object
    int choice, key, index;

    cout << "***** Priority Queue Implementation using Max Heap *****\n";

    // Menu-driven interface to perform priority queue operations using Max Heap
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Extract maximum\n";
        cout << "3. Increase key\n";
        cout << "4. Display heap\n";
        cout << "5. Show maximum element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> key;
                PQ.MAX_HEAP_INSERT(key);
                break;
            case 2:
                key = PQ.HEAP_EXTRACT_MAX();
                if(key != -1)
                    cout << "Extracted Max: " << key << "\n";
                break;
            case 3:
                cout << "Enter index of element to increase: ";
                cin >> index;
                cout << "Enter new key: ";
                cin >> key;
                PQ.HEAP_INCREASE_KEY(index, key);
                break;
            case 4:
                PQ.DISPLAY_HEAP();
                break;
            case 5:
                key = PQ.HEAP_MAXIMUM();
                if(key != -1)
                    cout << "Maximum element: " << key << "\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 0);

    return 0;
}
