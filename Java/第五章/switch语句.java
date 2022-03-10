import java.util.Scanner;

public class switch语句 {
	public static void main(String[] args) {
		System.out.println("请输入今天是星期几:");

		Scanner sc = new Scanner(System.in);
		int week = sc.nextInt();
		
		switch(week){
		case 1:
			System.out.println("今天是星期一！");break;
		case 2:
			System.out.println("今天是星期二！");break;
		case 3:
			System.out.println("今天是星期三！");break;
		case 4:
			System.out.println("今天周四！");break;
		case 5:
			System.out.println("事周五啊！");break;
		case 6:
			System.out.println("周六！");break;
		case 7:
			System.out.println("事周日呐！（意味深）");break;
		default:
			System.out.println("YBB？");break;

		}
	}
}
