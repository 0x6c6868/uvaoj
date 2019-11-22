package b1ch03;

import java.util.Scanner;

public class uva272 {

    private static boolean flag = true;

    private static void convert(char[] array) {
        int index = 0;
        while (index < array.length) {
            if (array[index] == '"') {
                System.out.print(flag ? "``" : "''");
                flag = !flag;
            } else {
                System.out.print(array[index]);
            }
            index++;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) convert(sc.nextLine().toCharArray());
    }

}
