import java.util.*;
import java.io.*;

public class G {

    public static void main(String[] args) throws Exception {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(in.nextInt());
        }
        Collections.sort(list);
        ArrayDeque<Integer> pqStart = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            pqStart.add(list.get(i));
        }
        ArrayDeque<Integer> pqEnd = new ArrayDeque<>();
        long sum = 0;
        while (!pqStart.isEmpty()) {
            if (pqStart.size() <= 2) {
                int toAdd = 0;
                if (pqStart.size() == 1) {
                    toAdd = pqStart.poll();
                } else {
                    toAdd = Math.max(pqStart.poll(), pqStart.poll());
                }
                sum += toAdd;
                break;
            }
            // move small
            int x = pqStart.poll();
            int y = pqStart.poll();
            int temp = Math.max(x, y);
            x = Math.min(x, y);
            y = temp;
            sum += x + y;
            pqStart.addFirst(x);
            pqEnd.addFirst(y);

            // move big
            x = pqStart.pollLast();
            y = pqStart.pollLast();
            sum += Math.max(x, y);

            if (pqStart.size() == 0) {
                break;
            }
            // move second small back
            x = pqEnd.pollFirst();
            temp = pqStart.pollFirst();
            pqStart.addFirst(x);
            pqStart.addFirst(temp);
            sum += x;
        }
        out.println(sum);
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
