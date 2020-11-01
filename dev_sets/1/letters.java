import java.util.*;

class letters
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int[] l1 = new int[26];
      int[] l2 = new int[26];

      String a = in.next();
      String b = in.next();

      int trial = 1;
      while (!(a.equals("END") && b.equals("END")))
      {
        Arrays.fill(l1, 0);
        Arrays.fill(l2, 0);

        for (char c : a.toCharArray())
          l1[c - 'a']++;

        for (char c : b.toCharArray())
          l2[c - 'a']++;

        System.out.print("Case " + trial + ": ");
        boolean safe = true;
        for (int i = 0; i < 26; i++)
        {
          if (l1[i] != l2[i])
          {
            System.out.println("different");
            safe = false;
            break;
          }
        }
        if (safe)
        {
          System.out.println("same");
        }

        a = in.next();
        b = in.next();
        trial++;
      }
  }
}
