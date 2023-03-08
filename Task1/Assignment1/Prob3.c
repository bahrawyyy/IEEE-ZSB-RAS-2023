// Write C code that defines a function taking array as input argument and
// count the frequency of each element of an array.


#include <stdio.h>

void countFrequency(int arr[], int size) {
    int freq[size];
    int visited[size]; // To keep track of visited elements
    int i, j, count;

    // Initialize frequency and visited arrays to zero
    for (i = 0; i < size; i++) {
        freq[i] = 0;
        visited[i] = 0;
    }

    for (i = 0; i < size; i++) {
        // If the element is already visited, skip it
        if (visited[i] == 1) {
            continue;
        }

        // Count the frequency of the element
        count = 1;
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // mark the element as visited
            }
        }
        freq[i] = count;
    }


    printf("Frequency of each element:\n");
    for (i = 0; i < size; i++) {
        if (visited[i] == 0) { // print only if element is not visited
            printf("%d: %d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, size);
    return 0;
}
