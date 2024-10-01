package java_programs;
//
//class f_key{
//	final int MAX_VALUE=99;
//	void myMethod(){
//		int MAX_VALUE=101;
//} 9
//public static void main(String args[]){
//	f_key obj=new f_key();
//	obj.myMethod();
//	
//	}
//
//}
class f_key{
final void demo(){
System.out.println("XYZ Class Method");
}
}
class ABC extends f_key{
//void demo(){
//System.out.println("ABC Class Method");
//}
public static void main(String args[]){
ABC obj= new ABC();
obj.demo();
}
}