#include <stdio.h>
#include <stdlib.h>

double getMedian(int arr[], int length) {
    // Sort the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int mid = length / 2;
    if (length % 2 != 0) {
        return arr[mid];
    } else {
        return (arr[mid] + arr[mid - 1]) / 2.0;
    }
}

void quartiles(int arr[], int length, int result[]) {
    // Sort the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int mid = length / 2;
    int q1, q2, q3;

    if (length % 2 != 0) {
        q1 = (int)getMedian(arr, mid);
        q2 = (int)getMedian(arr, length);
        q3 = (int)getMedian(arr + mid + 1, length - mid - 1);
    } else {
        q1 = (int)getMedian(arr, mid);
        q2 = (int)getMedian(arr, length);
        q3 = (int)getMedian(arr + mid, length - mid);
    }

    result[0] = q1;
    result[1] = q2;
    result[2] = q3;
}

int main() {
    int n;
    scanf("%d", &n);

    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int result[3];
    quartiles(data, n, result);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", result[i]);
    }

    free(data);

    return 0;
}
