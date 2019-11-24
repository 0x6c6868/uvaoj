package b1ch04;

import java.util.Arrays;
import java.util.Scanner;

public class uva1339 {

    private static void check(char[] originalArray, char[] array) {
        int[] originalCount = new int[26];
        int[] count = new int[26];

        for (int i = 0; i < originalArray.length; i++) originalCount[originalArray[i] - 'A']++;
        for (int i = 0; i < array.length; i++) count[array[i] - 'A']++;

        Arrays.sort(originalCount);
        Arrays.sort(count);

        for (int i = 0; i < 26; i++) {
            if (originalCount[i] != count[i]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) check(sc.nextLine().toCharArray(), sc.nextLine().toCharArray());
    }

}
