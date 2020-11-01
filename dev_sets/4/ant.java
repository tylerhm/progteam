import java.util.*;

/*
3 2 1 1 2 5 3 1 1 2 2 4 4 1 2 2 2 3 3 3 4 1 1 4 4
*/

class ant
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int n = in.nextInt();

      int h, t;
      for (int iter = 0; iter < n; iter++)
      {
        h = in.nextInt();
        t = in.nextInt();
        int[][] graph = new int[h][h];
        for (int i = 0; i < h; i++)
          for (int j = 0; j < h; j++)
            graph[i][j] = Integer.MAX_VALUE;
        while (t --> 0)
        {
          int a = in.nextInt() - 1;
          int b = in.nextInt() - 1;
          int w = in.nextInt();

          graph[a][b] = w;
        }

        int cost = 0;

        int[] parent = new int[h];
        for (int i = 0; i < h; i++)
          parent[i] = i;

        int edges = 0;
        boolean valid = true;

        while (edges < h - 1)
        {
          int min = Integer.MAX_VALUE, a = -1, b = -1;
          for (int i = 0; i < h; i++)
          {
            for (int j = 0; j < h; j++)
            {
              int iHome = i, jHome = j;
              while (parent[iHome] != iHome)
                iHome = parent[iHome];
              while (parent[jHome] != jHome)
                jHome = parent[jHome];
              if (iHome != jHome && graph[i][j] < min)
              {
                min = graph[i][j];
                a = i;
                b = j;
              }
            }
          }
          if (a == -1 || b == -1)
          {
            valid = false;
            break;
          }
          else  {
            int aHome = a, bHome = b;
            while (parent[aHome] != aHome)
              aHome = parent[aHome];
            while (parent[bHome] != bHome)
              bHome = parent[bHome];
            parent[aHome] = bHome;
            edges++;
            cost += min;
          }
        }

        System.out.print("Campus #" + (iter + 1) + ": ");
        if (!valid)
          System.out.println("I'm a programmer, not a miracle worker!");
        else
          System.out.println(cost);
      }
  }
}
