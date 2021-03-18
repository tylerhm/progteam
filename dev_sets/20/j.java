// Arup Guha
// 2/11/2017
// Solution to 2016 German Programming Contest Problem J: Selling CPUs

import java.util.*;

public class j {
	
	public static void main(String[] args) {
		
		// Read in all the input data.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int numM = stdin.nextInt();
		int[][] price = new int[numM][n+1];
		for (int i=0; i<numM; i++)
			for (int j=1; j<=n; j++)
				price[i][j] = stdin.nextInt();
				
		// DP array - res[i] = best answer for i CPUs.
		int[] res = new int[n+1];
		
		// Go through each merchant.
		for (int i=0; i<numM; i++) {
			
			// Store new answers here.
			int[] tmp = new int[n+1];
			
			// Get best answer for j CPUs incorporating this merchant.
			for (int j=0; j<=n; j++) {
				
				// k represents the number of CPUs we buy from this merchant. We simply want the
				// best possible result for the remaining j-k CPUs which are stored in res.
				for (int k=0; j-k>=0; k++)
					tmp[j] = Math.max(tmp[j], price[i][k]+res[j-k]);
				
			}
			
			// Update for next loop iteration.
			res = tmp;
		}

		for (int i : res) System.out.println(i);
		
		// We want the best answer of all of these.
		int ans = 0;
		for (int i=0; i<res.length; i++) ans = Math.max(ans, res[i]);
		System.out.println(ans);
	}
}