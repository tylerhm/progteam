import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class prob9 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		for (int i = 0; i < n; i++) {
			String[] a = scan.next().split(",");
			String[] b = scan.next().split(",");
		//	System.out.println(Arrays.toString(a));
		//	System.out.println(Arrays.toString(b));

			a[0] = a[0].substring(1);
			a[a.length - 1] = a[a.length - 1].substring(0, a[a.length - 1].length() - 1);
			b[0] = b[0].substring(1);
			b[b.length - 1] = b[b.length - 1].substring(0, b[b.length - 1].length() - 1);
			
		//	System.out.println(Arrays.toString(a));
		//	System.out.println(Arrays.toString(b));

			boolean containsAll = false;
			
			if (b.length == 1 && b[0].equals("")) {
				containsAll = true;
			} else if (b.length != a.length) {
				HashSet<String> aHash = new HashSet<String>();
				HashSet<String> bHash = new HashSet<String>();
				
				for (String s: a) {
					aHash.add(s.toLowerCase());
				}
				for (String s: b) {
					bHash.add(s.toLowerCase());
				}
				
			//	System.out.println(aHash);
			//	System.out.println(bHash);
				
				if (aHash.containsAll(bHash)) {
					containsAll = true;
				}
			}
			if (containsAll) {
				System.out.println((i + 1) + ": YES");
			} else {
				System.out.println((i + 1) + ": NO");

			}
		}

	}

}

/*
 * containsAll = true; for (int j = 0; j < b.length; j++) { for (int w = 0; w <
 * a.length; w++) { if (b[j].toLowerCase().equals(a[w].toLowerCase())) {
 * contains[j] = true; break; } } if (!contains[j]) { containsAll = false;
 * break; } }
 */

/*
 * for (int j = 0; j < a.length; j++) { aHash.add(a[i].toLowerCase()); } for
 * (int j = 0; j < b.length; j++) { bHash.add(b[i].toLowerCase()); }
 */