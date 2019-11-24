package b1ch03;

import java.util.Scanner;

public class uva1586 {

    private static int getScoreCore(char ch, int count) {
        switch (ch) {
            case 'C':
                return 12010 * count;
            case 'H':
                return 1008 * count;
            case 'O':
                return 16000 * count;
            case 'N':
                return 14010 * count;
        }
        return 0;
    }

    private static double getScore(char[] array) {
        int score = 0;

        int i = 0;
        while (i < array.length) {
            if (i + 1 == array.length || Character.isAlphabetic(array[i + 1])) {
                score += getScoreCore(array[i], 1);
                i++;
                continue;
            }

            char currCh = array[i];
            int count = 0;
            i++;
            while (i < array.length && Character.isDigit(array[i])) {
                count = count * 10 + (array[i] - '0');
                i++;
            }
            score += getScoreCore(currCh, count);
        }
        return score;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            System.out.println(String.format("%.3f", getScore(sc.nextLine().toCharArray()) / 1000));
            count--;
        }
    }

}
