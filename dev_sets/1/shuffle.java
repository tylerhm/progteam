import java.util.*;

/*
2 4 AHAH HAHA HHAAAAHH 3 CDE CDE EEDDCC
*/

class shuffle
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int n = in.nextInt();
      char[] s1, s2, s3, temp, firstShuffle;
      for (int iter = 0; iter < n; iter++)
      {
        int c = in.nextInt();
        s1 = in.next().toCharArray();
        s2 = in.next().toCharArray();
        s3 = in.next().toCharArray();
        temp = new char[c * 2];
        firstShuffle = new char[c * 2];

        for (int i = 0; i < c; i++)
        {
          firstShuffle[i * 2 + 1] = s1[i];
          firstShuffle[i * 2] = s2[i];
        }

        boolean solved = false;
        boolean validSolution = true;
        boolean firstIter = true;
        int count = 0;
        while(!solved)
        {
          count++;
          for (int i = 0; i < c; i++)
          {
            temp[i * 2 + 1] = s1[i];
            temp[i * 2] = s2[i];
          }

          int correctTo;
          if (!firstIter)
          {
            for (correctTo = 0; correctTo < c * 2; correctTo++)
              if (temp[correctTo] != firstShuffle[correctTo])
                break;
            if (correctTo == c * 2)
            {
              solved = true;
              validSolution = false;
            }
          }

          for (correctTo = 0; correctTo < c * 2; correctTo++)
            if (temp[correctTo] != s3[correctTo])
              break;
          if (correctTo == c * 2)
            solved = true;

          for (int i = 0; i < c; i++)
          {
            s1[i] = temp[i];
            s2[i] = temp[c + i];
          }
          firstIter = false;
        }
        System.out.print((iter + 1) + " ");
        if (validSolution)
          System.out.println(count);
        else
          System.out.println(-1);
      }
  }
}
