import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.ThreadLocalRandom;
public class Main 
{

 static long N = 100;
 static long CNT = 62;
 static long  INF = 1 << 62;




	
	 static long p[] = new long[50005];
	 static long si[] = new  long[50005];
    static void merge(long u, long v) 
    {
    	u = get(u);
    	v = get(v);
    	if (si[(int)v] > si[(int)u])
    	{
    		long k = v;
    		v = u;
    		u = k;
    	}
    	p[(int)v] = u;
    	si[(int)u] += si[(int)v];
    }
	  static long get(long u) {
	      	if(p[(int)u] == u) return  u;
	      	else return p[(int)u] = get(p[(int)u]);
	      }
	 static void init()
	 {
		 
	 int n = 5;
	      	for (int i = 0; i <= n; i++)
	      	{
	      		p[i] = i;
	      		si[i] = 1;
	      	}
	 }
	
	 static long clc(long c ,long m ,long n , long k)
	 {
		 return k - c * m * (2 * n - 2);
	 }
	 static long call(long n2, long m2 ,long n ,long m ,long k)
	 {
	 	if (n == 1 && true)
	 	{
	 		long r = k / m;
	 		if (m2 <= k - r * m) r = r + 1;
	 		return r;
	 	}
	 	 long r = k / m;
	 	 long c = r / (2 * n - 2); 
	 	 long res =  - 1;
	 	if (n2 != n && n2 != 1)
	 		res =res + 2 * c + 1;
	 else
	 		res = res + c + 1;	
	 	 long l = clc(c , m , n , k);
	 	for (int i = 1; l > 0 && i <= n; i++)
	 	{
	 		for (int j = 1; k > 0 && j <= m; j++,  l = l - 1)
	 		{
	 			if (i == n2 && j == m2)
	 				res = res + 1;
	 		}
	 	}
	 	for (int i =(int) n - 1; l > 0 && i > 0; i++)
	 	{
	 		for (int j = 1; l > 0 && j < m + 1; j++, l = l - 1)
	 		{
 				if (i == n2 && j == m2)
	 				res = res + 1;
	 		}
	 	}
	 	return res;
	 }

	// static String k;


	 static long parsenum(long j, long l)
	 {
		 String k = "";
	 	 long cur = 0;
	 	for (int i = (int) j; i <= l; ++i)
	 	{
	 		cur *= 10;
	 		cur += k.charAt(i) - '0';
	 	}
	 	return cur;
	 }

	 static long gcd(long a, long b) 
		{
			if (b == 0)
			{	
				return a;
			}
			
			else
			{
				 return gcd(b, a % b);
			}
		}
	static boolean pri( int k)
	 { 
		if( k == 1) return false;
	     for(int i = 2; i * i <= k; i++)
	     {

	         if( k % i == 0) return false;
	     }
	     return true;
	 }
	static long m , n , k;
	 static long ll;
	static long rr;
	static boolean check(long x)
	 {
	 	 long lt = summall(x - 1, ll);
	 	 long rt = summall(x - 1, rr);
	 	if (lt + rt + x <= m)
	 		return true;
	 	return false;
	 }
	static long summall(long  s,  long u)
	 {
	 	if (u == 0)
	 		return 0;
	 	if (u > s)
	 		return summall(s, s);
	 	return (2 * s - u + 1) * u / 2;
	 }
     static long bsearch()
     {
    	 long l = 0, r = m + 1;
			while (l < r - 1)
			{
				 long md = (l + r) / 2;
				if (check(md))
					l = md;
				else
					r = md;
			}
			
    	 return l + 1;
     }
	public static void main(String[] args) throws Exception
	{
		int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		 n = in.nextLong();  
		 m = in.nextLong();
		 k = in.nextLong();
		 long p = m - n;
		    m = p;
			ll = k - 1;
			rr = n - k;
		
			out.println(bsearch());
		
		out.close();
		return;
	}
 

}