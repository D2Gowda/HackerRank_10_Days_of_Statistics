import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Quartiles {

    static double getMedian(int[] arr) {
        Arrays.sort(arr);
        int mid = arr.length / 2;
        if (arr.length % 2 != 0) {
            return arr[mid];
        } else {
            return (arr[mid] + arr[mid - 1]) / 2.0;
        }
    }

    static int[] quartiles(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int mid = n / 2;

        int q1, q2, q3;
        if (n % 2 != 0) {
            q1 = (int) getMedian(Arrays.copyOfRange(arr, 0, mid));
            q2 = (int) getMedian(arr);
            q3 = (int) getMedian(Arrays.copyOfRange(arr, mid + 1, n));
        } else {
            q1 = (int) getMedian(Arrays.copyOfRange(arr, 0, mid));
            q2 = (int) getMedian(arr);
            q3 = (int) getMedian(Arrays.copyOfRange(arr, mid, n));
        }

        return new int[]{q1, q2, q3};
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] data = new int[n];

        for (int i = 0; i < n; i++) {
            data[i] = scanner.nextInt();
        }

        int[] res = quartiles(data);

        for (int i = 0; i < res.length; i++) {
            bufferedWriter.write(String.valueOf(res[i]));

            if (i != res.length - 1) {
                bufferedWriter.newLine();
            }
        }

        bufferedWriter.newLine();
        bufferedWriter.close();

        scanner.close();
    }
}
