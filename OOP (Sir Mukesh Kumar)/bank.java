package java_programs;
import java.util.Scanner;


public class ApnaBank {
    Scanner sc = new Scanner(System.in);
    String names[] = { "ali", "hassan", "usman" };
    String nin;
    int amount = 1000000;

    ApnaBank(String n) {
        this.nin = n;
        for (int i = 0; i < names.length; i++) {
            if (names[i].equals(nin)) {
                System.out.println("Your name is verified.");
                System.out.println("Enter '1' if you want to deposit\n" + "Enter '2' if you want to withdraw cash\n"
                        + "Enter '3' if you want to know your account balance");
                int action = sc.nextInt();
                switch (action) {
                    case 1:
                        System.out.println("Enter the amount you want to deposit: ");
                        int n1 = sc.nextInt();
                        System.out.println("Your current balance is now: " + (amount + n1));
                        break;
                    case 2:
                        System.out.println("Enter the amount you want to withdraw: ");
                        int n2 = sc.nextInt();
                        if (n2 <= amount) {
                            System.out.println("Your remaining amount is: " + (amount - n2));
                        } else {
                            System.out.println("You don't have this much amount in your account");
                        }
                        break;
                    case 3:
                        System.out.println("Your account balance is: " + amount);
                        break;
                    default:
                        System.out.println("Thanks for visiting.");
                }
            } else {
                continue;
            }
        }
    }

    public static void main(String[] args) {
        ApnaBank bank = new ApnaBank("ali");
    }
}
