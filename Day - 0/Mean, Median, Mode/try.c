#include <stdio.h>
#include <stdlib.h>

int countOccurrences(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // swap
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += a[i];
    }
    mean /= n;

    int mid = n / 2;
    double median;

    if (n % 2 != 0) {
        median = a[mid];
    } else {
        median = (a[mid] + a[mid - 1]) / 2.0;
    }

    int count = 0;
    int mode = a[0];

    for (int i = 0; i < n; i++) {
        int eleCount = countOccurrences(a, n, a[i]);

        if (eleCount > count || (eleCount == count && a[i] < mode)) {
            count = eleCount;
            mode = a[i];
        }
    }

    printf("%.1f\n", mean);
    printf("%.1f\n", median);
    printf("%d\n", mode);

    free(a);

    return 0;
}