import java.util.Scanner;

public class WeightedMean {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] X = new int[n];
        int[] W = new int[n];

        for (int i = 0; i < n; i++) {
            X[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            W[i] = scanner.nextInt();
        }

        weightedMean(X, W);
    }

    private static void weightedMean(int[] X, int[] W) {
        double wMean = 0;

        for (int i = 0; i < X.length; i++) {
            wMean += X[i] * W[i];
        }

        wMean /= sum(W);

        System.out.println(String.format("%.1f", wMean));
    }

    private static int sum(int[] arr) {
        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        return sum;
    }
}