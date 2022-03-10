import java.util.Scanner;
public class 奇偶数 {
	public static void main(String[] args) {
		System.out.println("请输入要判断奇偶的数据：");

		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();

		if(x%2==0)
		{
			System.out.println(x+"是偶数！");
		}
		else {
			System.out.println(x+"是奇数！");
		}
	}
}
