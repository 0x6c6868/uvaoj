package b1ch03;

import java.util.Scanner;

public class uva401 {

    private static char[] rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ".toCharArray();
    private static String[] description = {
            "not a palindrome", "a regular palindrome",
            "a mirrored string", "a mirrored palindrome"
    };

    private static char r(char ch) {
        if (ch >= 'A' && ch <= 'Z') return rev[ch - 'A'];
        return rev[ch - '0' + 25];
    }

    private static int judge(char[] array) {
        int p = 1, m = 1;
        for (int i = 0; i < array.length; i++) {
            if (array[i] != array[array.length - 1 - i]) p = 0;
            if (r(array[i]) != array[array.length - 1 - i]) m = 0;
        }
        return m * 2 + p;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String str = sc.nextLine();
            System.out.print(
                    String.format("%s -- is %s.\n\n", str,
                            description[judge(str.toCharArray())])
            );
        }
    }

}
