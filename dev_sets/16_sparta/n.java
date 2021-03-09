import java.util.*;
import java.io.*;

class n {

  static ArrayList<Integer> nums = new ArrayList<Integer>();

  public static void printFactors(int number, int curSum, int parentVal) {
    int newVal = parentVal;
    for (int i = number - 1; i >= 2; i--) {

      if (number % i == 0) {
        if (newVal > i) {
          newVal = i;
        }

        if (number / i <= parentVal && i <= parentVal && number / i <= i) {

          nums.add(curSum + (i-1) + ((number / i)-1));
          newVal = number / i;

        }

        if (i <= parentVal)
          printFactors(number / i, curSum + (i-1), newVal);

      }
    }
  }

  public static void main(String[] args) {
    FastScanner in = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();

    printFactors(n, 0, n);

    TreeSet<Integer> noDups = new TreeSet<Integer>();
    Collections.sort(nums);
    for (Integer nu : nums) noDups.add(nu);

    out.println(noDups.size() + 1);
    for (int val : noDups) out.print(val + " ");
    out.println(n-1);

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