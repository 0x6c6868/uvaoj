package b1ch04;

import java.util.Scanner;

public class uva489 {

    private static void judge(char[] originalArray, char[] array) {
        int chance = 7;
        int left = originalArray.length;

        for (int i = 0; i < array.length; i++) {

            boolean match = false;
            for (int j = 0; j < originalArray.length; j++) {
                if (array[i] == originalArray[j]) {
                    left--;
                    originalArray[j] = ' ';
                    match = true;
                }
            }

            if (left <= 0) {
                System.out.println("You win.");
                return;
            }

            if (!match) chance--;
            if (chance <= 0) {
                System.out.println("You lose.");
                return;
            }
        }
        System.out.println("You chickened out.");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int round = Integer.valueOf(sc.nextLine());
            if (round < 0) break;
            System.out.println("Round " + round);

            judge(sc.nextLine().toCharArray(), sc.nextLine().toCharArray());
        }
    }

}
