#include <iostream>

// Function to remove duplicates from an integer array
int removeDuplicates(int arr[], int n) {
    if (n <= 1)
        return n; // If the array has 0 or 1 element, it's already unique

    int newSize = 1; // Initialize the size of the new array

    // Compare current element with the next element
    for (int i = 1; i < n; i++) {
        bool isDuplicate = false;

        // Check if the current element is a duplicate of any previous element
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If the current element is not a duplicate, add it to the new array
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize; // Return the size of the new array with duplicates removed
}

int main() {
    int data[] = {5, 2, 9, 1, 5, 6, 2, 8, 1, 6};
    int n = sizeof(data) / sizeof(data[0]);

    std::cout << "Original data: ";
    for (int i = 0; i < n; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    int newSize = removeDuplicates(data, n);

    std::cout << "Data after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
