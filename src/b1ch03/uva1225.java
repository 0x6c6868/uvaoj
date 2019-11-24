package b1ch03;

import java.util.Scanner;

public class uva1225 {

    private static void count(int n) {
        int[] count = new int[10];
        while (n > 0) {
            int t = n;
            while (t > 0) {
                count[t % 10]++;
                t /= 10;
            }
            n--;
        }

        for (int i = 0; i < count.length - 1; i++) {
            System.out.print(String.format("%d ", count[i]));
        }
        System.out.println(count[9]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            count(Integer.valueOf(sc.nextLine()));
            count--;
        }
    }

}
