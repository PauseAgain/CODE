public class OperatorDemo02 {
	public static void main(String[] args) {
		//1:‘+’可以吧遵循ASCII编码的char与int型变量相加，输出int类
		System.out.println('A' + 10);//->75

		//2:'+'可以用来粘接字符串
		System.out.println("黑马" + 666);//->黑马666

		System.out.println("黑马" + 6 + 666);//->黑马6666，说明先粘接成黑马6
		System.out.println(1 + 99 + "黑马");//->100黑马，说明先计算1+99
		
	}	
}