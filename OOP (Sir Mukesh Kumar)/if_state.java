package java_programs;
import java.util.Scanner;
public class if_state {

	public static void main(String[] args) {
		float marks;
		Scanner num=new Scanner(System.in);
		System.out.println("enter your marks:");
		marks=num.nextFloat();
		num.close();
		if(marks<50)
			System.out.println("Grade=F");
		else if(marks<70)
			System.out.println("Grade=C");
		else if(marks<80)
			System.out.println("Grade=B");
		else
			System.out.println("Grade=A");
	}

}
