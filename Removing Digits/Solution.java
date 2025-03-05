import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt( ) ; 
        int[] dp = new int[n+1] ; 
        Arrays.fill( dp , n) ; 
        dp[0] = 0 ; 
        for( int i=1; i<=n ; ++i ){
            int m = i ; 
            while( m > 0 ){
                int curr = m % 10 ; 
                dp[i] = Math.min( dp[i] , dp[ i - curr ] + 1) ; 
                m /= 10; 
            }
        }

        System.out.println( dp[n] ) ; 

    }
}
