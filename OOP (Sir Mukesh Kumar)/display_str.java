package java_programs;

import java.util.Arrays;
import java.util.Scanner;

public class display_str {
    private String[] strings;

    public void readStringsFromUser() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of strings: ");
        int numStrings = scanner.nextInt();

        strings = new String[numStrings];

        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < numStrings; i++) {
            System.out.print("Enter string #" + (i + 1) + ": ");
            strings[i] = scanner.nextLine();
        }

        scanner.close();
    }

    public void displaySortedStrings() {
        Arrays.sort(strings);

        System.out.println("Sorted strings:");

        for (String str : strings) {
            System.out.println(str);
        }
    }

    public static void main(String[] args) {
        display_str sorter = new display_str();
        sorter.readStringsFromUser();
        sorter.displaySortedStrings();
    }
}



