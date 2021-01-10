import java.util.*;
import java.math.*;

class num_spiral {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigInteger x, y, ans;
        for (int i = 0; i < n; i++) {
            String ys = in.next(), xs = in.next();
            y = new BigInteger(ys);
            x = new BigInteger(xs);
            if (x.compareTo(y) >= 0) {
                if (x.testBit(0)) {
                    ans = x;
                    ans.pow(2);
                    ans.subtract(y);
                    ans.add(BigInteger.ONE);
                } 
                else {
                    ans = x;
                    ans.add(y);
                    ans.subtract(BigInteger.ONE);
                }
            }
            else {
                if (y.testBit(0)) {
                    ans = y;
                    ans.pow(2);
                    ans.subtract(x);
                    ans.add(BigInteger.ONE);
                } 
                else {
                    ans = y;
                    ans.add(x);
                    ans.subtract(BigInteger.ONE);
                }
            }

            System.out.println(ans);
        }
        in.close();
    }
}