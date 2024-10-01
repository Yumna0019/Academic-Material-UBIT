package java_programs;

interface MyCamera{
	void takesnap();
	void recordvideo();
	default void greet() {
		System.out.println("Morning");
	}
	default void record4kvideo() {
		greet();
		System.out.println("Recording in 4k");
	}
}
interface MyWifi{
	String[]getnetworks();
	void ConnectToNetworks(String network);
	
}
class MyCellPhone{
	void callNumber(int phonenumber) {
		System.out.println("calling..."+phonenumber);
		
	}
	void PickCall() {
		System.out.println("Connecting.....");
	}
}
class MySmartPhone extends MyCellPhone implements MyWifi,MyCamera{

	@Override
	public void takesnap() {
		System.out.println("Taking snap");
		// TODO Auto-generated method stub
		
	}

	@Override
	public void recordvideo() {
		System.out.println("Recording..");
		// TODO Auto-generated method stub
		
	}

	@Override
	public String[] getnetworks() {
		System.out.println("Getting List Of Networks");
		String[]networklist= {"zong","ufone","jazz"};
		// TODO Auto-generated method stub
		return networklist;
	}

	@Override
	public void ConnectToNetworks(String network) {
		System.out.println("connecting.."+network);
		// TODO Auto-generated method stub
		
	}
	
}

public class poly {

	public poly() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		MyCamera cam1=new MySmartPhone();
		cam1.record4kvideo();
		MySmartPhone s=new MySmartPhone();
	    s.recordvideo();
	    s.getnetworks();
	    s.callNumber(4567);// TODO Auto-generated method stub

	}

}
