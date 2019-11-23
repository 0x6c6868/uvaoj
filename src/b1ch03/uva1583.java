package b1ch03;

import java.util.Scanner;

public class uva1583 {

    private static int[] ans = new int[100005];

    private static void init() {
        for (int i = 0; i < ans.length; i++) {

            int sum = i, curr = i;
            while (curr != 0) {
                sum += curr % 10;
                curr = curr / 10;
            }

            if (sum < ans.length && ans[sum] == 0) ans[sum] = i;
        }
    }

    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            int num = Integer.valueOf(sc.nextLine());
            System.out.println(ans[num]);
            count--;
        }
    }

}
