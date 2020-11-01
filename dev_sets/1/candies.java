import java.util.*;

/*
23 24 1 1 1 12 2 32 4 54 110 6 5 5 5 4 6 5 5 5 44 1 2 3 45 2 2 2 3 36 7 7 1 1 3 3*/

class candies
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int n = in.nextInt();
      int b, k;

      int[] candies;
      while (n --> 0)
      {
        b = in.nextInt();
        candies = new int[b];
        for (int i = 0; i < b; i++)
          candies[i] = in.nextInt();


      }
  }
}
