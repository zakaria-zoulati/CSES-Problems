import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        int[] arr = new int[n] ; 
        int[][] dp = new int[n][m+2] ; 
        for( int i=0 ; i<n ; ++i ){
            arr[i] = sc.nextInt() ; 
        }
        int mod = 1_000_000_007 ; 
        

        for( int i=0 ; i<n ; ++i ){
            if( i == 0 ){
                if( arr[i] == 0 ){
                    for( int j=1 ; j<=m ; ++j ){
                        dp[i][j] = 1  ;
                    }
                }
                else {
                    dp[0][ arr[0] ] = 1 ; 
                }
            }else {
                if( arr[i] == 0 ){
                   for( int j=1 ; j<=m ; ++j ){
                        dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]  ) % mod ; 
                        dp[i][j] = ( dp[i][j] + dp[i-1][j-1] ) % mod ; 
                   }
                }else {
                    dp[ i ][ arr[i] ] = (  dp[i-1][arr[i]] + dp[i-1][ arr[i] + 1 ]  ) % mod ; 
                    dp[ i ][ arr[i] ]  = ( dp[ i ][ arr[i] ] + dp[i-1][ arr[i]-1 ] ) % mod ;  
                }
            }
        }

        int rs = 0 ; 
        for( int i=1 ; i<=m ; ++i ){
            rs = ( rs + dp[n-1][i] ) % mod ; 
        }

        System.out.println( rs ) ;
    }
}