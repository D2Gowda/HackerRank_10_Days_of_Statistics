#include <stdio.h>
#include <stdlib.h>

double getMedian(int arr[], int length) {
    // Sort the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculate median
    int mid = length / 2;
    return (length % 2 != 0) ? arr[mid] : (arr[mid - 1] + arr[mid]) / 2.0;
}

void interQuartile(int values[], int freqs[], int n) {
    // Calculate the total number of elements
    int totalElements = 0;
    for (int i = 0; i < n; i++) {
        totalElements += freqs[i];
    }

    // Create an array to store all the elements
    int* arr = (int*)malloc(totalElements * sizeof(int));

    // Populate the array with values according to frequencies
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < freqs[i]; j++) {
            arr[index++] = values[i];
        }
    }

    // Calculate quartiles
    int mid = totalElements / 2;
    double q1 = getMedian(arr, mid);

    double q2;
    if (totalElements % 2 == 0) {
        q2 = getMedian(arr + mid, mid);
    } else {
        q2 = getMedian(arr + mid + 1, mid);
    }

    // Calculate and print the interquartile range
    double result = q2 - q1;
    printf("%.1f\n", result);

    // Free the dynamically allocated memory
    free(arr);
}

int main() {
    int n;
    scanf("%d", &n);

    int values[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int freqs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &freqs[i]);
    }

    interQuartile(values, freqs, n);

    return 0;
}
