import java.util.*;

class most {

	static Scanner bob;
	public static void main(String[] args) {
		bob = new Scanner(System.in);
		int t = bob.nextInt();
		for (int tt = 0; tt < t; tt++)
			System.out.println(solve(tt));
	}

	static long solve(int t) {
		int n = bob.nextInt(), m = bob.nextInt();

		Edge[] edges = new Edge[m];
		for (int e = 0; e < m; e++)
			edges[e] = new Edge(
				bob.nextInt() - 1,
				bob.nextInt() - 1,
				bob.nextInt()
			);

		Arrays.sort(edges);
		DisjointSet dsu = new DisjointSet(n);
		long total = 0;
		for (Edge e : edges)
			if (dsu.union(e.a, e.b))
				total += e.w;
		
		if (total % 2 == 1)
			return total;
		return -1;
	}

	static class Edge implements Comparable<Edge> {
		int a, b;
		int w;
		public Edge(int _a, int _b, int _w) {
			a = _a;
			b = _b;
			w = _w;
		}

		public int compareTo(Edge o) {
			if (w < o.w) return -1;
			if (w == o.w) return 0;
			return 1;
		}
	}	

	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
		}
	}
}
