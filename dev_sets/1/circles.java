import java.util.*;

/*
3 6 12 8 1 2 4 100 3 1 2 3 6 3 1 3 2 3 3
*/

class Circle
{
  int r;
  List<Integer> connections = new ArrayList<Integer>();

  public Circle(int r)
  {
    this.r = r;
  }
}

class change
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);

      int t = in.nextInt();

      int c, r, d, a;
      Circle[] circles;
      int[]
      while (t --> 0)
      {
        c = in.nextInt();
        r = in.nextInt();

        circles = new Circle[c];
        for (int i = 0; i < c; i++)
          circles[i] = new Circle(in.nextInt());

        for (int i = 0; i < r; i++)
        {
          d = in.nextInt();
          a = in.nextInt();

          circles[d - 1].connections.add(a);
        }
      }
  }
}
