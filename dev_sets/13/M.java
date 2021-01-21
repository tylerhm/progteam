import java.util.*;
import java.io.*;

public class M {

    public static void main(String[] args) throws Exception {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int l = in.nextInt();
        VecL[] lPoints = new VecL[l];
        for (int i = 0; i < l; i++)
            lPoints[i] = new VecL(in.nextLong(), in.nextLong());

        ConvexHull hull = new ConvexHull();
        hull.getHull(lPoints);
        int s = in.nextInt();
        int ans = 0;
        for (int i = 0; i < s; i++) {
            VecL temp = new VecL(in.nextLong(), in.nextLong());
            if (PointInConvexHull.pointInConvexHull(hull.upperHull, hull.lowerHull, temp) >= 0) {
                ans++;
            }
        }
        out.println(ans);

        out.close();
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

class ConvexHull {

    public static VecL[] upperHull, lowerHull;

    public static VecL[] removeDupes(VecL[] points) {
        HashSet<VecL> set = new HashSet<>();
        for (VecL v : points)
            set.add(v);
        int counter = 0;
        points = new VecL[set.size()];
        for (VecL v : set)
            points[counter++] = v;
        return points;
    }

    // returns the hull in CCW order
    public static VecL[] getHull(VecL[] points) {
        points = points.clone();
        Arrays.sort(points);
        if (points.length < 3)
            return upperHull = lowerHull = points;
        int n = points.length, j = 2, k = 2;
        VecL[] lo = new VecL[n], up = new VecL[n];
        lo[0] = points[0];
        lo[1] = points[1];
        for (int i = 2; i < n; i++) {
            VecL p = points[i];
            while (j > 1 && !right(lo[j - 2], lo[j - 1], p))
                j--;
            lo[j++] = p;
        }
        up[0] = points[n - 1];
        up[1] = points[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            VecL p = points[i];
            while (k > 1 && !right(up[k - 2], up[k - 1], p))
                k--;
            up[k++] = p;
        }

        VecL[] res = new VecL[j + k - 2];
        for (int i = 0; i < k; i++)
            res[i] = up[i];
        for (int i = 1; i < j - 1; i++)
            res[k + i - 1] = lo[i];

        // if you need upper and lower hulls
        upperHull = new VecL[k];
        for (int i = 0; i < k; i++)
            upperHull[i] = up[k - i - 1];
        lowerHull = new VecL[j];
        for (int i = 0; i < j; i++)
            lowerHull[i] = lo[i];

        return res;
    }

    // check if a->b->c are in the right order
    static boolean right(VecL a, VecL b, VecL c) {
        return b.sub(a).cross(c.sub(a)) > 0;
    }

}

class PointInConvexHull {

    // returns 1 if in the polygon, 0 if on, -1 if outside;
    public static int pointInConvexHull(VecL[] upperHull, VecL[] lowerHull, VecL p) {
        int uSide = side(upperHull, p), lSide = side(lowerHull, p);
        if (uSide == 1 || uSide == -2)
            return -1;
        if (lSide == -1 || lSide == -2)
            return -1;
        if (uSide == 0 || lSide == 0)
            return 0;
        return 1;
    }

    // returns:
    // 1 if above hull
    // 0 if on hull
    // -1 if below hull
    // -2 if to left or right
    // does not allow three collinear vertical points in the hull
    public static int side(VecL[] hull, VecL p) {
        int n = hull.length;
        if (p.x < hull[0].x || p.x > hull[n - 1].x)
            return -2;
        int min = 0, max = n - 2, mid;
        while (min <= max) {
            mid = (min + max) / 2;
            VecL l = hull[mid], r = hull[mid + 1];
            if (p.x < l.x)
                max = mid - 1;
            else if (p.x > r.x)
                min = mid + 1;
            else if (l.x == r.x) {
                if (l.x == p.x) {
                    if (Math.min(l.y, r.y) <= p.y)
                        if (Math.max(l.y, r.y) >= p.y)
                            return 0;
                        else
                            return 1;
                    else
                        return -1;
                }
                // vertical line, move closer to the middle of the hull and check later
                if (l.x == hull[0].x)
                    min = mid + 1;
                else
                    max = mid - 1;
            } else {
                if (p.y < Math.min(l.y, r.y))
                    return -1;
                if (p.y > Math.max(l.y, r.y))
                    return 1;
                return Long.signum(r.sub(l).cross(p.sub(l)));
            }
        }
        return -2;
    }
}

class VecL implements Comparable<VecL> {
    long x, y;

    public VecL(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public VecL add(VecL o) {
        return new VecL(x + o.x, y + o.y);
    }

    public VecL sub(VecL o) {
        return new VecL(x - o.x, y - o.y);
    }

    public VecL scale(long s) {
        return new VecL(x * s, y * s);
    }

    public long dot(VecL o) {
        return x * o.x + y * o.y;
    }

    public long cross(VecL o) {
        return x * o.y - y * o.x;
    }

    public long mag2() {
        return dot(this);
    }

    public VecL rot90() {
        return new VecL(-y, x);
    }

    public VecL rot270() {
        return new VecL(y, -x);
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public int hashCode() {
        return Long.hashCode(x << 13 ^ (y * 57));
    }

    public boolean equals(Object oo) {
        VecL o = (VecL) oo;
        return x == o.x && y == o.y;
    }

    public int compareTo(VecL o) {
        if (x != o.x)
            return Long.compare(x, o.x);
        return Long.compare(y, o.y);
    }

    // origin->q1, axes-> quadrant in ccw direction
    public int quadrant() {
        if (x == 0 || y == 0)
            if (y == 0)
                return x >= 0 ? 1 : 3;
            else
                return y >= 0 ? 2 : 4;
        if (x > 0)
            return y > 0 ? 1 : 4;
        else
            return y > 0 ? 2 : 3;
    }

    public int radialCompare(VecL o) {
        if (quadrant() == o.quadrant())
            return -Long.signum(cross(o));
        return Integer.compare(quadrant(), o.quadrant());
    }
}
