public class 三个和尚 {
	public static void main(String[] args) {
		int h1 = 150;
		int h2 = 210;
		int h3 = 165;
		
		int tmp=((h1>=h2)?h1:h2);
		System.out.println( (tmp>=h3)? tmp : h3);
	}
}
