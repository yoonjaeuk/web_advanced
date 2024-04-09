import java.io.*;
import java.util.*;

public class Main {
	static long A, B;
	static int ans;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		A = Long.parseLong(st.nextToken());
		B = Long.parseLong(st.nextToken());
		
		func(0, A);
		System.out.println(ans == 0 ? -1 : ans);
	}
	private static void func(int cnt, long num) {
		if(ans != 0 || num > B) return;
		if(num == B) {
			ans = cnt + 1;
			return;
		}
		func(cnt+1, num*10+1);
		func(cnt+1, num*2);
	}

}