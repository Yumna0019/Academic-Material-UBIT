package java_programs;

public class Str_new_str {
//	public static void main(String args[])
//	  {
//	    //creating string using string literal
//	    String s1 = "BeginnersBook";
//	    String s2 = "BeginnersBook";
//
//	    //creating strings using new keyword
//	    String s3 = new String("BeginnersBook");
//	    String s4 = new String("BeginnersBook");
//
//	    if(s1 == s2){
//	      System.out.println("String s1 and s2 are equal");
//	    }else{
//	      System.out.println("String s1 and s2 are NOT equal");
//	    }
//
//	    if(s3 == s4){
//	      System.out.println("String s3 and s4 are equal");
//	    }else{
//	      System.out.println("String s3 and s4 are NOT equal");
//	    }
//
//	  } 







//public static void main(String args[]){
//    String str = "Beginnersbook";
//
//    //declaring a char array
//    char arrCh[]={'h','e','l','l','o'};
//
//    //converting char array arrCh[] to string str2
//    String str2 = new String(arrCh);
//
//    //creating another java string str3 by using new keyword
//    String str3 = new String("Java String Example");
//
//    //Displaying all the three strings
//    System.out.println(str);
//    System.out.println(str2);
//    System.out.println(str3);
//  }
//}
	
	
	
//	public static void main(String[] args) {
//	    String str = "Welcome to BeginnersBook.com";
//
//	    //finding length of the string using length() method.
//	    int len = str.length();
//
//	    // First character of the string
//	    System.out.println("First character: "+ str.charAt(0));
//
//	    // Last character
//	    System.out.println("Last character: "+ str.charAt(len-1));
//	  }
//}

	
	
	public static void main(String[] args) {
	    String str = "Hello"; //creating using literal
	    String str2 = new String("Hello"); //using new keyword

	    if(str.equals(str2)){
	      System.out.println("Strings str and str2 are equal");
	    }else{
	      System.out.println("Strings str and str2 are NOT equal");
	    }
	}
}

	
	

//		  public static void main(String[] args) {
//		    String str = "Welcome";
//		    String str2 = "Home";
//		    System.out.println(str.concat(" ").concat(str2));
//		  }
//		}
