import java.util.Arrays;
import java.util.Scanner;

public class Statistics {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        Arrays.sort(a);

        double mean = Arrays.stream(a).average().orElse(0);
        int mid = n / 2;
        double median;

        if (n % 2 != 0) {
            median = a[mid];
        } else {
            median = (a[mid] + a[mid - 1]) / 2.0;
        }

        int count = 0;
        int mode = a[0];

        for (int ele : a) {
            int eleCount = countOccurrences(a, ele);

            if (eleCount > count || (eleCount == count && ele < mode)) {
                count = eleCount;
                mode = ele;
            }
        }

        System.out.println(String.format("%.1f", mean));
        System.out.println(String.format("%.1f", median));
        System.out.println(mode);
    }

    private static int countOccurrences(int[] arr, int target) {
        int count = 0;
        for (int ele : arr) {
            if (ele == target) {
                count++;
            }
        }
        return count;
    }
}