package b1ch03;

import java.util.Scanner;

public class uva455 {

    private static void check(char[] array) {
        int i = 0;
        for (; i < array.length; i++) {
            if (array.length % (i + 1) > 0) continue;

            boolean flag = true;
            for (int j = 0; j < array.length; j++) {
                if (array[j] != array[j % (i + 1)]) {
                    flag = false;
                    break;
                }
            }
            if (flag) break;

        }
        System.out.println(i + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            sc.nextLine();
            check(sc.nextLine().toCharArray());
            count--;
            if (count > 0) System.out.println();
        }
    }

}
