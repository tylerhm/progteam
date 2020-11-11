// Arup Guha
// 9/16/2014
// Solution to 2012 Pacific NW Regional Problem B: Magic Multiple

import java.util.*;

public class magic {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		// Go through all cases.
		while (stdin.hasNext()) {

			long n = stdin.nextLong();

			// Initialize variables.
			int cnt = 0;
			boolean[] used = new boolean[10];

			// Go till all marked.
			while (!done(used)) {

				// Do next multiple.
				cnt++;
				mark(cnt*n, used);
			}

			// Print result.
			System.out.println(cnt);
		}
	}

	// Marks each digit in n as true in used.
	public static void mark(long n, boolean[] used) {
		while (n > 0) {
			used[(int)(n%10L)] = true;
			n /= 10L;
		}
	}

	// Returns true iff used is all true.
	public static boolean done(boolean[] used) {
		for (int i=0; i<used.length; i++)
			if (!used[i])
				return false;
		return true;
	}
}