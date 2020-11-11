// Patrick Fenelon
// 7/14/2011
// Solution for BHCSI 2011 Practice Contest #1 Problem: Bunnies

import java.io.*;
import java.util.*;

public class bunnies {
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File("bunnies.in"));
		new bunnies(sc);		
	}
	
	// This constructor does all the work, reading in each case, 
	// solving and outputting the results.
	public bunnies(Scanner sc){
		
		// Go through each test case.
		int t = sc.nextInt();		
		while(t-->0){
			
			// Get the grid size for this case.
			int r = sc.nextInt(), c = sc.nextInt();
			
			char[][] grid = new char[r][c];
			int locR = -1, locC= -1;
			
			// Read in the grid for this case.
			for(int i = 0; i < r; i++){
				String s = sc.next();
				for(int j = 0; j < c; j++){
					grid[i][j] = s.charAt(j);
					if(grid[i][j] == 'C'){
						locR = i;
						locC = j;
						grid[i][j] = '_';
					}
				}
			}
					
			// Bunny location.
			LinkedList<Coord> toDo = new LinkedList<Coord>();
			toDo.offer(new Coord(locR,locC));
			
			// Execute the flood fill, in a breadth first order.
			while(!toDo.isEmpty()){
				Coord curr = toDo.poll();
				if(isValid(curr,grid) && grid[curr.r][curr.c] != 'C' && grid[curr.r][curr.c] != '#'){
					grid[curr.r][curr.c] = 'C';
					toDo.offer(new Coord(curr.r,curr.c+1));
					toDo.offer(new Coord(curr.r,curr.c-1));
					toDo.offer(new Coord(curr.r+1,curr.c));
					toDo.offer(new Coord(curr.r-1,curr.c));
				}				
			}
			
			// Check to see if the other bunny is in there.
			boolean hasPeter = false;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					
					if(grid[i][j] == 'P'){
						hasPeter = true;
					}
				}
				
			}
			
			// Output the result.
			if (hasPeter)
				System.out.println("no");
			else
				System.out.println("yes");
			
		}
	}
	
	// Returns true iff c is a valid coordinate in grid.
	public boolean isValid(Coord c, char[][] grid){
		if(c.r >= 0 && c.r < grid.length){
			if(c.c >= 0 && c.c < grid[0].length){
				return true;
			}
		}
		return false;
	}
	
	// Stores a grid coordinate.
	public class Coord{
		public int r,c;
		public Coord(int R, int C){
			r = R;
			c = C;
		}
	}
}
