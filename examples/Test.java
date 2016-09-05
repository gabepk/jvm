class Test
{
	public static int fib(int n)
	{	
		int prev = 0, curr = 1;
		for (int i = 1; i < n; i++) {
			int tmp = curr;
			curr = prev + curr;
			prev = tmp;
		}
		return curr;
	}
	
	public static void main(String[] args)
	{
		System.out.println(fib(42));
	}
}