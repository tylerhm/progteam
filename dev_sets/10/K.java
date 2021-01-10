import java.util.*;

import java.io.*;

public class K {
    static int xLim = 200;
    static int yLim = 300;
    static ArrayList<Point> list;
    static int[] memo;
    static DisjointSet set;

    public static void main(String[] args) throws Exception {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        list = new ArrayList<>(n);
        memo = new int[n];
        set = new DisjointSet(n);
        Arrays.fill(memo, -1);
        for (int i = 0; i < n; i++) {
            list.add(new Point(in.nextInt(), in.nextInt(), in.nextInt(), i));
        }
        int low = 0, high = n - 1;
        int mid = (high - low) / 2;
        while (true) {
            if (checkGraph(mid) && !checkGraph(mid + 1))
                break;
            if (checkGraph(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        System.out.println(mid);
        out.close();
    }

    static boolean checkGraph(int k) {
        set = new DisjointSet(k);
        if (memo[k] != -1) {
            return memo[k] == 1;
        }
        ArrayList<Point> ends = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            if (list.get(i).x - list.get(i).r < 0) {
                list.get(i).left = true;
                ends.add(list.get(i));
            }
            if (list.get(i).x + list.get(i).r > xLim) {
                list.get(i).right = true;
                ends.add(list.get(i));
            }
        }
        for (Point p : ends) {
            for (int i = 0; i < k; i++) {
                if (p.id == i)
                    continue;
                if (circle(p, list.get(i))) {
                    set.union(p.id, i);
                }
            }
        }
        boolean[] left = new boolean[k];
        boolean[] right = new boolean[k];
        for (int i = 0; i < k; i++) {
            if (list.get(i).left) {
                left[set.find(list.get(i).id)] = true;
            }
        }
        for (int i = 0; i < k; i++) {
            if (list.get(i).right) {
                right[set.find(list.get(i).id)] = true;
            }
        }
        boolean ok = true;
        for (int i = 0; i < k; i++) {
            if (left[i] && right[i]) {
                ok = false;
            }
        }
        if (ok)
            memo[k] = 1;
        else
            memo[k] = 0;
        return memo[k] == 1;
    }

    static boolean circle(Point p1, Point p2) {
        int x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y, r1 = p1.r, r2 = p2.r;
        return Math.hypot(x1 - x2, y1 - y2) <= (r1 + r2);
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
            if ((a = find(a)) == (b = find(b)))
                return false;
            if (s[a] == s[b])
                s[a]--;
            if (s[a] <= s[b])
                s[b] = a;
            else
                s[a] = b;
            return true;
        }
    }

    public static class Point {
        int x, y, r, id;
        boolean left, right;

        public Point(int x, int y, int r, int id) {
            this.x = x;
            this.y = y;
            this.r = r;
            this.id = id;
            left = false;
            right = false;
        }

        double dist(Point p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}
