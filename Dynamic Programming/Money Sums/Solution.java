import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        boolean[] x = new boolean[100_001] ; 
        int count = 0 ; 
        x[0] = true ; 
        while( n-- > 0 ){ 
            int a = sc.nextInt() ; 
            for( int i=100_000; i>=a ; --i ){
                if( x[i] ) continue ; 
                if( x[ i - a ] ){
                    count++ ; 
                    x[i] = true ; 
                }
            }
        }

        System.out.println( count ) ; 

        for( int i=1 ; i < 100_001 ; ++i ){
            if( x[i] ){
                System.out.print( i + " " ) ; 
            }
        }

    }
}
