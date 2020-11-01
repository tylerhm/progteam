import java.util.*;

/*
3 6 12 8 1 2 4 100 3 1 2 3 6 3 1 3 2 3 3
*/

class change
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int n = in.nextInt();

      int c;
      int[] coins;
      for (int iter = 0; iter < n; iter++)
      {
        c = in.nextInt();
        coins = new int[c];
        for (int i = 0; i < c; i++)
          coins[i] = in.nextInt();

        // SUPER SIMPLE NAIVE ATTEMPT
        /*
        sort
        take first value
        if its less than (or equal) to our running sum
        continue
        otherwise we have a gap!
        */

        Arrays.sort(coins);

        int smallestVal = 0;
        for (int i = 0; i < c; i++)
        {
          if (coins[i] > smallestVal + 1)
            break;
          smallestVal += coins[i];
        }

        System.out.println("Set #" + (iter + 1) + ": " + (smallestVal + 1));
        System.out.println();
      }
  }
}
