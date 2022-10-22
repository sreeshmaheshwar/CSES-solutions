import java.util.Scanner;

public class Solution {

  private static final int MOD = (int) 1e9 + 7;
  private static final char TRAP = '*';

  public static int add(int a, int b) {
    return (a + b) % MOD;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();

    String[] grid = new String[n];
    for (int i = 0; i < n; ++i) {
      grid[i] = scanner.next();
    }

    int[][] numPathsToCell = new int[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i].charAt(j) == TRAP) {
          continue;
        }
        if (i == 0 && j == 0) {
          numPathsToCell[i][j] = 1;
        } else {
          numPathsToCell[i][j] = add(i > 0 ? numPathsToCell[i - 1][j] : 0,
              j > 0 ? numPathsToCell[i][j - 1] : 0);
        }
      }
    }

    System.out.println(numPathsToCell[n - 1][n - 1]);
  }
}