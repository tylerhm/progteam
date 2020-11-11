import java.util.*;

public class tacobell {
	
	public static void main(String[] args) {
		
		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();
		
		// Go through each case.
		for (int loop=0; loop<numCases; loop++) {
			
			// Read the input.
			int n = stdin.nextInt();
			int k = stdin.nextInt();
			String[] items = new String[n];
			for (int i=0; i<n; i++)
				items[i] = stdin.next();
				
			// Helps for lexicographical ordering.
			Arrays.sort(items);
			
			printCombos(items, k);
			System.out.println();
		}
	}
	
	// Pre-condition: items is sorted in alpha order and 0 < k <= items.length.
	public static void printCombos(String[] items, int k) {
		
		int n = items.length;
		boolean[] used = new boolean[n];
		printCombosRec(items, used, 0, 0, k);
	}
	
	public static void printCombosRec(String[] items, boolean[] used, int curItem, int curTotal, int total) {
		
		// We have a solution.
		if (curTotal == total) {
			print(items, used);
			return;
		}
		
		// Too many items or we're at the end of our list - no possible solution builds off this one.
		if (curTotal > total || curItem == items.length) return;
		
		// Try adding this item. Must do this option first to get lexicographical ordering.
		used[curItem] = true;
		printCombosRec(items, used, curItem+1, curTotal+1, total);
		
		// Try NOT adding this item.
		used[curItem] = false;
		printCombosRec(items, used, curItem+1, curTotal, total);
	}
	
	// Prints in order specified.
	public static void print(String[] items, boolean[] used) {
		for (int i=0; i<used.length; i++)
			if (used[i])
				System.out.print(items[i]+" ");
		System.out.println();
	}
}