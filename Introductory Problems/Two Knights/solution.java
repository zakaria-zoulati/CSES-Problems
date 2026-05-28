import java.util.Scanner ; 
public class solution {
    static long calculateWays(int K) {
        long totalWays = ((long) K * K * (K * K - 1)) / 2;
        long attackingWays = 4 * (K - 1) * (K - 2);
        long ans = totalWays - attackingWays;
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ; 
        int N = sc.nextInt() ; 
        for (int K = 1; K <= N; K++) {
            System.out.print(calculateWays(K) + " ");
        }
    }
}

