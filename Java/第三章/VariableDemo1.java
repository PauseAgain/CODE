
public class VariableDemo1 {
	public static void main(String[ ] args){
		//自动类型转换
		double d = 10;
		System.out.println(d);

		//定义byte类型的变量
		byte b = 10;
		short s = b;
		int i = b;
		//👆这些都不报错，byte到char报错
		char c = b;//报错

		int k = (int) 80.88;
	}
}
