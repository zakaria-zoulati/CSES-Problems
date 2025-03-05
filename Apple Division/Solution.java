import java.util.* ; 

public class Solution {
    static long rs = Long.MAX_VALUE ; 
    public static void main( String[] args ){
        rs = Long.MAX_VALUE ; 
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        long[] p = new long[n] ; 
        long sum = 0L ; 
        for( int i=0 ; i<n ; ++i ){ 
            p[i] = sc.nextLong() ; 
            sum += p[i] ; 
        }
        // Do a simple backtrack 
        backtrack( p , 0 ,  0L , sum ) ;

        System.out.println( rs ) ; 
    }
    public static void backtrack( long[] p , int in ,long curr , long sum  ){
        if( in == p.length ){
            rs = Math.min( rs , Math.abs( sum - 2*curr  ) ) ; 
            return ; 
        }
        backtrack(  p , in+1 , curr , sum ) ; 
        backtrack(p, in+1, curr + p[in], sum);
    } 
}
