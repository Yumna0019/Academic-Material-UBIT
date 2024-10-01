package java_programs;

//
//	 class OuterClass {
//	    private int outerData;
//	    
//	    public void outerMethod() {
//	        System.out.println("Outer method");
//	    }
//	    
//	    // Inner Class
//	    public class InnerClass {
//	        private int innerData;
//	        
//	        public void innerMethod() {
//	            outerData = 5; // Accessing outer class member
//	            System.out.println("Inner method");
//	        }
//	    }
//	}
//public class inner_class{
//		public static void main(String args[]) {
//	        OuterClass outerObj = new OuterClass();
//	        outerObj.outerMethod();
//	        // Creating an instance of the inner class	        
//	        OuterClass.InnerClass innerObj = outerObj.new InnerClass();
//	        innerObj.innerMethod();
//			
//}
//}





 class OuterClass {
    private static int outerData;
    
    public void outerMethod() {
        System.out.println("Outer method");
    }
    
    // Static Inner Class
    public static class StaticInnerClass {
        private int innerData;
        
        public void innerMethod() {
            outerData = 5; // Accessing static member of outer class
            System.out.println("Static Inner method");
        }
    }
 }    
 public class inner_class{   
    public static void main(String[] args) {
    	  OuterClass outerObj = new OuterClass();
    	  outerObj.outerMethod();
    	// Creating an instance of the static inner class
        OuterClass.StaticInnerClass staticInnerObj = new OuterClass.StaticInnerClass();
        staticInnerObj.innerMethod();
    }
 }


