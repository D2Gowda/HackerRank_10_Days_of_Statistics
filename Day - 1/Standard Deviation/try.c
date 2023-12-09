#include <stdio.h>
#include <math.h>

void stdDev(int arr[], int n) {
    // Print your answers to 1 decimal place within this function
    double mean = 0;

    for (int i = 0; i < n; i++) {
        mean += arr[i];
    }
    mean /= n;

    double sumSquares = 0;
    for (int i = 0; i < n; i++) {
        sumSquares += pow(arr[i] - mean, 2);
    }

    double result = sqrt(sumSquares / n);

    printf("%.1f\n", result);
}

int main() {
    int n;
    scanf("%d", &n);

    int vals[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }

    stdDev(vals, n);

    return 0;
}
