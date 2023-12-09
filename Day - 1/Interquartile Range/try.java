import java.util.Arrays;
import java.util.Scanner;

public class InterQuartileRange {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }

        int[] freqs = new int[n];
        for (int i = 0; i < n; i++) {
            freqs[i] = scanner.nextInt();
        }

        interQuartile(values, freqs);
    }

    static void interQuartile(int[] values, int[] freqs) {
        int totalElements = Arrays.stream(freqs).sum();
        int[] arr = new int[totalElements];

        int index = 0;
        for (int i = 0; i < values.length; i++) {
            for (int j = 0; j < freqs[i]; j++) {
                arr[index++] = values[i];
            }
        }

        Arrays.sort(arr);

        int mid = arr.length / 2;

        double q1 = getMedian(Arrays.copyOfRange(arr, 0, mid));

        double q2;
        if (arr.length % 2 == 0) {
            q2 = getMedian(Arrays.copyOfRange(arr, mid, arr.length));
        } else {
            q2 = getMedian(Arrays.copyOfRange(arr, mid + 1, arr.length));
        }

        double result = q2 - q1;
        System.out.println(String.format("%.1f", result));
    }

    static double getMedian(int[] arr) {
        Arrays.sort(arr);
        int mid = arr.length / 2;
        return (arr.length % 2 != 0) ? arr[mid] : (arr[mid - 1] + arr[mid]) / 2.0;
    }
}
