package java_programs;
//Example 1: Modify static variable in main method and other methods of the class
//class stat 
//{
//// static variables a and b
//static int a = 10;
//static int b;
//static void printStatic()
//{
//a = a /2;
//b = a;
//System.out.println("printStatic::Value of a : "+a + " Value of b : "+b);
//}
//public static void main(String[] args)
//{
//printStatic();
//b = a*5;
//a++;
//System.out.println("main::Value of a : "+a + " Value of b : "+b);
//}
//}



//Example: Overriding not possible with static methods

//class stat {
//// Static method in base class which will be hidden in substatic_displayclass
//public static void static_display() {
//System.out.println("Base_Class::static_display");
//}
//}
//class Derived_Class extends stat {
//
//public static void static_display() {
//System.out.println("Derived_Class::static_display");
//}
//
//public class Main {
//public static void main(String args[]) {
//stat obj1 = new stat();
//stat obj2 = new Derived_Class();
//Derived_Class obj3 = new Derived_Class();
//
//obj1.static_display();
//obj2.static_display();
//obj3.static_display();
//}
//}
//}



//Example: Static Binding
class Human{
   public static void walk()
   {
       System.out.println("Human walks");
   }
}
class Boy extends Human{
   public static void walk(){
       System.out.println("Boy walks");
   }
}
public class stat {
	

   public static void main(String args[]) {
       /* Reference is of Human type and object is
        * Boy type
        */
	   Human obj = new Boy();
       /* Reference is of HUman type and object is
        * of Human type.
        */
	   Human obj2 = new Human();
       obj.walk();
       obj2.walk();
   }
}
