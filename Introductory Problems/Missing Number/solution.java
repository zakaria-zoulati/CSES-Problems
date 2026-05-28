import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        long n = sc.nextLong() ; 
        long inter = 0 ; 
        long rs = 0 ; 
        for(int i=0 ; i<n-1 ; i++){
            inter += sc.nextLong() ; 
        }
        rs = n*(n+1)/2 - inter ; 
        System.out.println(rs) ; 
    }
}