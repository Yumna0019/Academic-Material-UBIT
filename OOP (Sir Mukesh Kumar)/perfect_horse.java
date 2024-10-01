package java_programs;
import java.util.Scanner;

class Animal{
	private double energy;
	private String name;
	void set_Energy(double e) {
		this.energy=e;
	}
	void set_Name(String n) {
		this.name=n;
	} 
	void can_go_for_race() {
		if (energy>50) {
			System.out.println(name+ " can go for a race. ");
		}
		else {
			System.out.println(name+ " cannot go for a race as its energy is very low. ");
		}
	}
	
}


class Horse extends Animal{
	private String color;
	private double pasterns;
	private double height;
	private double neck;
	private double weight;
	private double shoulders;
	private String feet;
	
	void set_color(String c) {
		this.color=c;
	}
	void set_feet(String f) {
		this.feet=f;
	}
	void set_pasterns(double p) {
		this.pasterns=p;
	}
	void set_height(double h) {
		this.height=h;
	}
	void set_neck(double n) {
		this.neck=n;
	}
	void set_weight(double w) {
		this.weight=w;
	}
	void set_shoulders(double s) {
		this.shoulders=s;
	}
	
	void properties() {
		System.out.println("The color of the horse is: "+color);
		System.out.println("The height of the horse is: "+height);
		System.out.println("The neck of the horse is: "+neck);
		System.out.println("The weight of the horse is: "+weight);
		System.out.println("The pasterns of the horse is: "+pasterns);
		System.out.println("The shoulders of the horse is: "+shoulders);
		System.out.println("The feet of the horse is: "+feet);
	}
	void check_for_shoulders() {
		if(shoulders==pasterns) {
			System.out.println("Pasterns and shoulders are perfect.  ");
		}
		else {
			System.out.println("Not a great choice as shoulders and pasterns size is not same. ");
		}
	}	
	void check_for_neck() {
		if (neck>=32) {
		System.out.println("It has an ideal neck size. ");
		}
		else {
			System.out.println("Neck is too short. ");
		}
	}	
	void check_for_pasterns() {
		if (pasterns>=neck*0.3) {
		System.out.println("Perfect size of pasterns. ");
		}
		else {
			System.out.println("Too short pasterns. ");
		}
	}	
	void check_for_height() {
		if (height>14 || height<=16.5) {
		System.out.println("Perfect height. ");
		}
		else {
			System.out.println("Height is not approriate. ");
		}
	}	
	void check_for_feet() {
		if (feet=="U SHAPE") {
		System.out.println("The feet shape is perfect. ");
		}
		else {
			System.out.println("Not a perfect shape. ");
		}
	}	
}

public class perfect_horse {

	public static void main(String[] args) {
		Animal a=new Animal();
		Horse h=new Horse();
		Scanner scan=new Scanner(System.in);
		String n,f,c;
		double p,h1,n1,e,s,w;
		System.out.println("Enter the name: ");
		n=scan.next();
		System.out.println("Enter the height: ");
		h1=scan.nextDouble();
		System.out.println("Enter the pasterns size: ");
		p=scan.nextDouble();
		System.out.println("Enter the size of shoulders: ");
		s=scan.nextDouble();
		System.out.println("Enter the weight of the horse: ");
		w=scan.nextDouble();
		System.out.println("Enter the  energy: ");
		e=scan.nextDouble();
		System.out.println("Enter the neck size: ");
		n1=scan.nextDouble();
		System.out.println("Enter the shape of the feet: ");
		f=scan.next().toUpperCase();
		System.out.println("Enter the color of the horse: ");
		c=scan.next();
		h.set_color(c);
		h.set_Energy(e);
		h.set_feet(f);
		h.set_height(h1);
		h.set_Name(n);
		h.set_neck(n1);
		h.set_pasterns(p);
		h.set_shoulders(s);
		h.set_weight(w);
		h.can_go_for_race();
		h.properties();
		h.check_for_height();
		h.check_for_shoulders();
		h.check_for_neck();
		h.check_for_pasterns();
		h.check_for_feet();
	}

}
