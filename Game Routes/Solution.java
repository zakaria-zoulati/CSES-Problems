import java.util.* ; 

public class Solution {
    static int mod = 1_000_000_007 ; 
    static int rs = 0 ; 
    static int n ; 
    public static void dfs( int i , ArrayList<Integer>[] edges ){
        if( i == n ){
            rs = ( rs + 1 ) % mod ; 
            return ; 
        }
        for( int j : edges[i] ){
            dfs( j , edges ) ;
        }
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        ArrayList<Integer>[] edges = new ArrayList[n+1] ; 
        for( int i=0 ; i<=n ; ++i ){
            edges[i] = new ArrayList<>() ; 
        }
        while( m-- > 0 ){
            int a = sc.nextInt() ;
            int b = sc.nextInt() ;
            edges[a].add(b) ; 
        }
        int[] dp = new int[n+1] ; 
        Queue<Integer> q = new LinkedList<>() ; 
        q.add(1) ; 
        for( int i= )

        System.out.println( dp[n] ) ; 
        
    }
}