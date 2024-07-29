import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        long n = sc.nextLong() ; 
        StringBuilder rs = new StringBuilder() ; 
        rs.append(n+" ") ;
        while( n>1 ){
            if( n%2 == 0 ){
                n=n/2 ;
             }
             else {
                n = 3*n +1 ; 
             }
             rs.append( n+ " ") ; 
        }
        System.out.println(rs) ; 
    }
}