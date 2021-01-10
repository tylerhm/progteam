import java.util.*;
 
public class b {
	public static double fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800L, 87178291200L, 1307674368000L, 20922789888000L, 355687428096000L, 6402373705728000L, 121645100408832000L, 2432902008176640000L};
	public static void main(String[] args) {
		Scanner scanny = new Scanner(System.in);
		int tt = scanny.nextInt();
		for(int t = 0; t < tt; t++) {
			int r = scanny.nextInt();
			int s = scanny.nextInt();
			int n = scanny.nextInt();
			int m = scanny.nextInt();
			int w = scanny.nextInt();
			int pNumerator = (s-r+1);
			int pDenominator = s;
			double p = (double)pNumerator/pDenominator;
			double probofwinning = 0;
			for(int k = n; k <= m; k++) {
				probofwinning+=(choose(m, k))*Math.pow(p, k)*Math.pow(1.0-p, m-k);
			}
			//System.out.println(probofwinning);
			double proboflosing = 1-probofwinning;
			// (w*b* probofwinning) - (b*proboflosing) > b
			// (w*probofwinning) - (proboflosing) > 1
			double expectedreturn = w*probofwinning;
			//System.out.println(expectedreturn);
			if(expectedreturn > 1) System.out.println("yes");
			else System.out.println("no");
		}
	}
	public static double choose(int M, int k) {
		return (double)fact[M]/(fact[M-k]*fact[k]);
	}
}
/*
2
5 6 2 3 3
5 6 2 3 4

3
2 2 9 10 100
1 2 10 10 1
1 2 10 10 2

1
3 4 1 1 5

1
3 3 1 1 6
*/