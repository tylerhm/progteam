import java.util.*;
import java.io.*;
public class knapsack {
    static int[][] dp;
    static int[] vals, weights;
    static int n;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int raids = scan.nextInt();
        while(raids-->0){
            n = scan.nextInt();
            int w = scan.nextInt();
            vals = new int[n];
            weights = new int[n];
            int C = 0;
            int takeAllVal = 0;
            for(int i = 0;i<n;i++){
                vals[i] = scan.nextInt();
                weights[i] = scan.nextInt();
                C+=weights[i];
                takeAllVal+=vals[i];
            }
            int over = C-w;
            if(over<=0){
                System.out.println(takeAllVal);
                continue;
            }
            dp = new int[n+1][over+1];
            //dp will keep track of our losses
            for(int i = 0;i<n;i++){
                Arrays.fill(dp[i],-1);
            }

            go(0,over);
            System.out.println(takeAllVal-dp[0][over]);
        }
    }
    //go returns the minimum value lost from this index
    static int go(int index, int over){
        if(index==n || over<=0){
            return 0;
        }
        if(dp[index][over]!=-1)return dp[index][over];
        //MINIMIZE LOSSES
        int min = Integer.MAX_VALUE;
        min = Math.min(min,go(index+1,over-weights[index])+vals[index]);
        min = Math.min(min,go(index+1,over));
        return dp[index][over]  =min;
    }
}