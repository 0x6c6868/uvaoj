package b1ch03;

import java.util.Scanner;

public class uva1584 {

    private static boolean less(char[] array, int minIndex, int currIndex) {
        for (int i = 0; i < array.length; i++) {
            if (array[(currIndex + i) % array.length] != array[(minIndex + i) % array.length])
                return array[(currIndex + i) % array.length] < array[(minIndex + i) % array.length];
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = Integer.valueOf(sc.nextLine());
        while (count > 0) {
            int minIndex = 0;
            char[] array = sc.nextLine().toCharArray();

            for (int i = 0; i < array.length; i++) {
                if (less(array, minIndex, i)) minIndex = i;
            }

            for (int i = minIndex; i < array.length; i++) System.out.print(array[i]);
            for (int i = 0; i < minIndex; i++) System.out.print(array[i]);
            System.out.println();

            count--;
        }
    }

}
