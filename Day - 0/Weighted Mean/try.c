#include <stdio.h>

double calculateWeightedMean(int X[], int W[], int n) {
    double wMean = 0;

    for (int i = 0; i < n; i++) {
        wMean += X[i] * W[i];
    }

    return wMean;
}

int calculateSum(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int X[n];
    int W[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }

    double wMean = calculateWeightedMean(X, W, n);
    int sumW = calculateSum(W, n);

    wMean /= sumW;

    printf("%.1f\n", wMean);

    return 0;
}
