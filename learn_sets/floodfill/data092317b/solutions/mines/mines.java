import java.io.*;
import java.util.*;

public class mines {
	
	static int count = 0;
	
	public static void main (String args[]) throws IOException {
		BufferedReader in = new BufferedReader (new FileReader ("mines.in"));
		
		boolean space[][][];
		boolean aux[][][];
		int size;
		int numsims;
		int sims[][];
		
		StringTokenizer st;
		String temp;
		
		size = Integer.parseInt (in.readLine ());
		st = new StringTokenizer (in.readLine ());
		
		space = new boolean[size][size][size];
		aux = new boolean[size][size][size];
		
		System.out.println (st.countTokens());
		
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				for (int z = 0; z < size; z++) {
					temp = st.nextToken ();
					if (Integer.parseInt (temp) == 1)
						space[x][y][z] = true;
					else
						space[x][y][z] = false;
						
					aux[x][y][z] = false;
						
					//System.out.print (temp);
				}
				//System.out.println ();
			}
			//System.out.println ();
		}
		
		numsims = Integer.parseInt (in.readLine ());
		sims = new int[numsims][3];

		System.out.println ("numsims:" + numsims);
		
		for (int i = 0; i < numsims; i++) {
			st = new StringTokenizer (in.readLine ());
			sims[i][0] = Integer.parseInt (st.nextToken ());
			sims[i][1] = Integer.parseInt (st.nextToken ());
			sims[i][2] = Integer.parseInt (st.nextToken ());
		}
		
		for (int i = 0; i < numsims; i++) {
			count = 0;
			resetaux (aux, size);
			traverse (sims[i][0], sims[i][1], sims[i][2], space, size, aux);
			System.out.println ("Simulation #" + (i + 1) + ", volume cleared is " + count + " cubic feet.");
			System.out.println ();
			//System.out.println ("Starting point was (" + sims[i][0] + ", " + sims[i][1] + ", " + sims[i][2] + ")");
			//System.out.println ("It's value was " + space[sims[i][0]][sims[i][1]][sims[i][2]]);
			//System.out.println ();
		}
	}
	
	public static void traverse (int x, int y, int z, boolean space[][][], int size, boolean aux[][][]) {
		if ((x >= size) || (y >= size) || (z >= size))
			return;
			
		if ((x < 0) || (y < 0) || (z < 0))
			return;

		if (aux[x][y][z])
			return;
		else
			aux[x][y][z] = true;	

		if (space[x][y][z])
			count++;
		else
			return;		
			
		//space[x][y][z] = false;
			
		traverse (x + 1, y, z, space, size, aux);
		traverse (x - 1, y, z, space, size, aux);
		traverse (x, y + 1, z, space, size, aux);
		traverse (x, y - 1, z, space, size, aux);
		traverse (x, y, z + 1, space, size, aux);
		traverse (x, y, z - 1, space, size, aux);
		
		return;
	}
	
	public static void resetaux (boolean aux[][][], int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					aux[i][j][k] = false;
				}
			}
		}
	}
}
