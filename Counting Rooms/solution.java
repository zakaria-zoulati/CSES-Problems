import java.util.Scanner;
import java.util.Stack ; 
public class solution {
    static int[][] ds = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine(); 
        char[][] chars = new char[n][m];
        for (int i = 0; i < n; ++i) {
            chars[i] = sc.nextLine().toCharArray();
        }

        boolean[][] isSeen = new boolean[n][m];
        int rs = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (chars[i][j] == '.' && !isSeen[i][j]) {
                    rs++;
                    dfs(isSeen, chars, i, j);
                }
            }
        }
        System.out.println(rs);
    }
    public static void dfs(boolean[][] isSeen, char[][] chars, int i, int j) {
        int n = chars.length, m = chars[0].length;
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{i, j});
        isSeen[i][j] = true;
        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int x = current[0], y = current[1];
            for (int[] d : ds) {
                int newX = x + d[0];
                int newY = y + d[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    chars[newX][newY] == '.' && !isSeen[newX][newY]) {
                    stack.push(new int[]{newX, newY});
                    isSeen[newX][newY] = true;
                }
            }
        }
    }
    
}
