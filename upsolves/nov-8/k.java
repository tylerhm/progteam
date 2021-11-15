import java.util.*;

class k {
	public static void main(String[] args) {
		Scanner hackpackop = new Scanner(System.in);
		int n = hackpackop.nextInt();
		double a = hackpackop.nextDouble();
		ArrayList<Blot> blots = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			blots.add(new Blot(
				hackpackop.nextDouble(),
				hackpackop.nextDouble(),
				hackpackop.nextDouble()
				));
		}

		double lo = 0,
	}

	static class Blot {
		double x, y, t;
		Blot(double x, double y, double t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}
	}

	static double areaOfUnion(long[] xs, long[] ys, long[] rs) {
		double area = 0;
		double PI2 = Math.PI * 2;
		int n = xs.length;
		outer: for (int i = 0; i < n; i++) {
			long x = xs[i], y = ys[i], r = rs[i];
			for (int j = 0; j < i; j++)
				if (x == xs[j] && y == ys[j] && r == rs[j])
					continue outer;
			ArrayList<Event> es = new ArrayList<>();
			es.add(new Event(0, 0));
			es.add(new Event(PI2, 0));

			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				long x1 = xs[j], y1 = ys[j], r1 = rs[j];
				long d2 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
				double d = Math.sqrt(d2);
				long add = (r1 + r) * (r1 + r), sub = (r1 - r) * (r1 - r);

				if (d2 >= add || (d2 <= sub && r >= r1))
					continue;
				if (r1 >= r && d2 <= sub)
					continue outer;

				double ang = Math.atan2(y1 - y, x1 - x);
				double dif = Math.acos((r * r + d2 - r1 * r1) / (2 * r * d));
				double a0 = ang - dif, a1 = ang + dif;
				while (a0 < PI2)
					a0 += PI2;
				while (a0 >= PI2)
					a0 -= PI2;

				while (a1 < PI2)
					a1 += PI2;
				while (a1 >= PI2)
					a1 -= PI2;
				es.add(new Event(a0, 1));
				es.add(new Event(a1, -1));
				if (a0 > a1)
					es.add(new Event(0, 1));
			}

			Collections.sort(es);
			double p = 0;
			int d = 0;
			for (Event e : es) {
				double a = e.ang;
				if (d == 0) {
					area += (a - p) * r * r / 2;
					double x0 = r * Math.cos(p), y0 = r * Math.sin(p) + y + y;
					double x1 = r * Math.cos(a), y1 = r * Math.sin(a) + y + y;
					area += (x0 * y0 - x1 * y1) / 2;
				}
				p = a;
				d += e.type;
			}
		}
		return area;

	}

	static class Event implements Comparable<Event> {
		double ang;
		int type;

		public Event(double angg, int typee) {
			ang = angg;
			type = typee;
		}

		public int compareTo(Event e) {
			int res = Double.compare(ang, e.ang);
			if (res == 0)
				res = Integer.compare(type, e.type);
			return res;
		}
	}

}
