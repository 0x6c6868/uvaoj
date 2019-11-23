package b1ch03;

import java.util.Scanner;

public class uva340 {

    private static String[] standard;

    private static void judge(String[] guess) {
        int A = 0;
        for (int i = 0; i < guess.length; i++) if (standard[i].equals(guess[i])) A++;

        int B = 0;
        for (int i = 0; i <= 9; i++) {
            int c1 = 0, c2 = 0;
            String val = String.valueOf(i);
            for (int j = 0; j < standard.length; j++) if (val.equals(standard[j])) c1++;
            for (int j = 0; j < guess.length; j++) if (val.equals(guess[j])) c2++;
            B += c1 > c2 ? c2 : c1;
        }
        System.out.println(String.format("    (%d,%d)", A, B - A));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int kase = 0;
        while (sc.hasNext()) {
            String str = sc.nextLine();
            if (str.charAt(0) == '0') break;

            System.out.println("Game " + ++kase + ":");
            standard = sc.nextLine().split(" ");

            while (sc.hasNext()) {
                String[] guess = sc.nextLine().split(" ");
                if (guess[0].equals("0")) break;
                judge(guess);
            }
        }
    }

}
