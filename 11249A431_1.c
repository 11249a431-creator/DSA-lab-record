#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i; // Declare variable i here
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Return index if element found
    }
    return -1; // Return -1 if element not found
}

int main() {
    int arr[] = {11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

