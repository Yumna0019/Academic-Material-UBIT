package java_programs;
import java.util.Scanner;
public class factorial {

	public static void main(String[] args) {
		int num,fact=1;
		Scanner f1 = new Scanner(System.in);
		System.out.println("enter a number for factorial:");
		num=f1.nextInt();
		f1.close();
		for(int i=1;i<=num;i++)
		{
			fact=fact*i;
		}
		System.out.println("factorial of "+num+" is: "+fact);

	}

}
