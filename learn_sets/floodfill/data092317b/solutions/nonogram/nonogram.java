// Arup Guha
// 11/12/2012
// Solution to 2012 South East Regional (D2) Problem G: Reverse Nonogram

import java.util.*;

public class nonogram {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int n = stdin.nextInt();

		while (n != 0) {

			// Read in the board.
			char[][] grid = new char[n][];
			for (int i=0; i<n; i++) {
				String s = stdin.next();
				grid[i] = s.toCharArray();
			}

			// Output Rows.
			for (int i=0; i<n; i++) {
				solve(grid[i]);
			}

			// Output Cols.
			for (int i=0; i<n; i++) {
				char[] temp = new char[n];
				for (int j=0; j<n; j++)
					temp[j] = grid[j][i];
				solve(temp);
			}

			n = stdin.nextInt();
		}
	}

	public static void solve(char[] array) {

		// Will store answer.
		ArrayList<Integer> list = new ArrayList<Integer>();

		boolean on = false;
		int cnt = 0;

		// Go through the list.
		for (int i=0; i<array.length; i++) {

			// We are on, add to count.
			if (array[i] == 'X') {
				on = true;
				cnt++;
			}

			// Just got turned off.
			else if (on) {
				list.add(cnt);
				cnt = 0;
				on = false;
			}

		}

		// Add in the last block, if the last character was in.
		if (on)
			list.add(cnt);

		// Print out the list w/o extra spaces.
		if (list.size() > 0) {
			for (int i=0; i<list.size()-1; i++)
				System.out.print(list.get(i)+" ");
			System.out.println(list.get(list.size()-1));
		}

		// Empty Row output.
		else
			System.out.println("0");
	}
}