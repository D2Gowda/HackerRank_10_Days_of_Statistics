import java.util.Scanner;

public class StandardDeviation {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] vals = new int[n];

        for (int i = 0; i < n; i++) {
            vals[i] = scanner.nextInt();
        }

        stdDev(vals);
    }

    public static void stdDev(int[] arr) {
        // Print your answers to 1 decimal place within this function
        double mean = 0;
        for (int value : arr) {
            mean += value;
        }
        mean /= arr.length;

        double sumSquares = 0;
        for (int value : arr) {
            sumSquares += Math.pow(value - mean, 2);
        }

        double result = Math.sqrt(sumSquares / arr.length);

        System.out.printf("%.1f%n", result);
    }
}
