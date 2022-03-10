import java.util.Scanner;

public class 三个和尚 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h1 = sc.nextInt();
		int h2 = sc.nextInt();
		int h3 = sc.nextInt();

		int tmp = (h1 > h2) ? h1 : h2;

		System.out.println("MaxHeight:" + ((tmp > h3) ? tmp : h3));
	}
}
