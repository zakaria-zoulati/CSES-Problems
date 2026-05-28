import java.util.Scanner ; 

public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        String in = sc.nextLine() ; 
        int n = in.length() ; 
        int rs = 0 ;
        int max = 0 ; 
        for(int i=0 ; i<n ; i++){
            max++ ; 
            while( i+1<n && in.charAt(i) == in.charAt(i+1) ){
                max++ ; 
                i++ ; 
            }
            rs= Math.max(rs,max) ; 
            max= 0 ; 
        } 
        System.out.println(rs) ; 
    }
}