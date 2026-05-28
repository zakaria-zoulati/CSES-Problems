import java.util.Scanner ; 
public class solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int n = sc.nextInt() ; 
        long rs = 0 ; 
        long[] arr = new long[n] ; 
        for(int i=0 ; i<n ; i++){
            arr[i] = sc.nextLong() ; 
        }
        for(int i=1 ; i<n ; i++){
            if( arr[i] <arr[i-1] ){
                rs += arr[i-1] - arr[i] ; 
                arr[i] = arr[i-1] ; 
            }
        }
        System.out.println(rs) ; 
        
    }
}