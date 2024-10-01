package java_programs;
import java.util.Scanner;
public class num2_sum {

	public static void main(String[] args) {
		int a,b,sum;
		Scanner num=new Scanner(System.in);
		System.out.println("enter 2 numbers:");
		a=num.nextInt();
		b=num.nextInt();
		num.close();
		sum=a+b;
		System.out.println("Sum of "+a+  " and "  +b+  " is: "  +sum);

	}

}
