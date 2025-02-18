import java.util.* ;
public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int max = ( 1 << n ) - 1 ; 
        char[] chars = new char[n] ; 
        for( int i=0 ; i<=max ; ++i ){
            int in = n-1 ; 
            int gray_code = i ^ ( i >> 1 ) ; 
            while( gray_code > 0 ){
                chars[in--] = gray_code % 2 == 0 ? '0' : '1' ; 
                gray_code >>= 1 ; 
            } 
            while( in >= 0 ) chars[in--] = '0' ; 
            System.out.println( new String(chars)) ; 
        }
    }
}