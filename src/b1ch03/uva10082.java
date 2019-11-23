package b1ch03;

import java.util.Scanner;

public class uva10082 {

    private static char[] s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./".toCharArray();

    private static void convert(char[] array) {

        for (char ch : array) {
            int i = 1;
            while (i < s.length && s[i] != ch) i++;

            if (i == s.length) System.out.print(ch);
            else System.out.print(s[i - 1]);
        }
        System.out.println();

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) convert(sc.nextLine().toCharArray());
    }

}
