import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        Stack<int[]> stack = new Stack<>() ;
        for( int i=0 ; i<n ; ++i ){
            int a = sc.nextInt() ; 
            while( !stack.isEmpty() && stack.peek()[0] >= a ){
                stack.pop() ; 
            }
            if( stack.isEmpty() ){
                System.out.print(0 + " ") ; 
            }else {
                int curr = stack.peek()[1] + 1 ; 
                System.out.print( curr + " " ) ; 
            }
            stack.add(new int[]{ a , i }) ; 
        }
    }
}
