package b1ch04;

import java.util.Scanner;

public class uva133 {

    private static int[] array;

    private static void countOff(int n, int k, int m) {
        if (n <= 0) return;

        array = new int[n];
        for (int i = 0; i < n; i++) array[i] = i + 1;

        int left = n;

        int a = n - 1;
        int b = 0;

        while (left > 0) {
            a = go(a, 1, k);
            b = go(b, -1, m);

            System.out.print(String.format("%3d", array[a]));
            left--;

            if (a != b) {
                System.out.print(String.format("%3d", array[b]));
                left--;
            }

            array[a] = array[b] = 0;
            if (left > 0) {
                System.out.print(",");
            }
        }
        System.out.println();
    }

    private static int go(int i, int d, int t) {
        while (t-- > 0) {
            do {
                i = (i + d + array.length) % array.length;
            } while (array[i] == 0);
        }
        return i;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String input = sc.nextLine();
            String[] inputArray = input.split(" ");
            countOff(Integer.valueOf(inputArray[0]), Integer.valueOf(inputArray[1]), Integer.valueOf(inputArray[2]));
        }
    }

}
