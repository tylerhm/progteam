import java.util.*;

class Node
{
	int val, buttonsPressed;

	public Node(int val, int buttonsPressed)
	{
		this.val = val;
		this.buttonsPressed = buttonsPressed;
	}
}

class calc
{
	static HashSet<Integer> pressed = new HashSet<Integer>();
	static LinkedList<Node> q = new LinkedList<Node>();

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();

		int k, add, mul, div;

		Node node;
		while (n-->0)
		{
			k = in.nextInt();

			pressed.clear(); q.clear();
			node = new Node(k, 0);

			q.offer(node);

			while (!q.isEmpty())
			{
				Node t = q.poll();
				pressed.add(t.val);

				if (complete())
				{
					System.out.println(t.buttonsPressed);
					break;
				}

				// generate possible new nodes
				add = t.val + 1;
				mul = t.val * 3;
				div = t.val / 2;

				if (add > 0 && add < 1_000_000_000)
				{
					Node addN = new Node(add, t.buttonsPressed + 1);
					q.offer(addN);
				}
				if (mul > 0 && mul < 1_000_000_000)
				{
					Node mulN = new Node(mul, t.buttonsPressed + 1);
					q.offer(mulN);
				}
				if (div > 0 && div < 1_000_000_000)
				{
					Node divN = new Node(div, t.buttonsPressed + 1);
					q.offer(divN);
				}
			}
		}
	}

	public static boolean complete()
	{
		for (int i = 1; i < 100; i++)
			if (!pressed.contains(i))
				return false;
		return true;
	}
}
