import java.util.*;
import java.math.BigInteger;

public class d {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    BigInteger[][] m = new BigInteger[2][2];
    m[0][0] = new BigInteger(in.next());
    m[0][1] = new BigInteger(in.next());
    m[1][0] = new BigInteger(in.next());
    m[1][1] = new BigInteger(in.next());

    String ans = "";
    while (!isIdent(m)) {
      if (m[0][0].compareTo(m[1][0]) >= 0 && m[0][1].compareTo(m[1][1]) >= 0) {
        ans = ans + "1";
        m[0][0] = m[0][0].subtract(m[1][0]);
        m[0][1] = m[0][1].subtract(m[1][1]);
      }
      else {
        ans = ans + "0";
        m[1][0] = m[1][0].subtract(m[0][0]);
        m[1][1] = m[1][1].subtract(m[0][1]);
      }
    }

    System.out.println(ans);
  }

  static boolean isIdent(BigInteger[][] m) {
    return (m[0][0].compareTo(BigInteger.ONE) == 0 && m[0][1].compareTo(BigInteger.ZERO) == 0 &&
    m[1][0].compareTo(BigInteger.ZERO) == 0 && m[1][1].compareTo(BigInteger.ONE) == 0);
  }
}