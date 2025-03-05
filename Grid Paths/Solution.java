import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ;  
        sc.nextLine() ; 
        char[][] grid = new char[n][n] ; 
        for(int i=0 ; i<n ; ++i ){
            grid[i] = sc.nextLine().toCharArray() ; 
        }

        if( grid[0][0] == '*' || grid[n-1][n-1] == '*' ){
            System.out.println(0) ; 
        }else {
            int[][] dp = new int[n][n] ; 
            dp[0][0] = 1 ; 
            int mod = (int) ( 1e9 + 7 ) ; 
            int t=1 ; 
            while( t<n && grid[t][0] == '.' ){
                dp[t][0] = 1 ; 
                t++ ; 
            }
            t = 1 ;
            while( t<n && grid[0][t] == '.' ){
                dp[0][t] = 1 ; 
                t++ ; 
            } 
            for( int i=1 ; i<n ; ++i ){
                for( int j=1 ; j<n ; ++j ){
                    if( grid[i][j] == '.' ){
                        dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % mod ; 
                    }
                }
            }
            System.out.println( dp[n-1][n-1] ) ; 
        }

    }
}