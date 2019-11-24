package b1ch03;

import java.util.Scanner;

public class uva1585 {

    private static int getScore(char[] array) {
        int score = 0, nextScore = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == 'O') {
                nextScore++;
                score += nextScore;
            } else {
                nextScore = 0;
            }
        }
        return score;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            System.out.println(getScore(sc.nextLine().toCharArray()));
            count--;
        }
    }

}
