import java.util.Arrays;
import java.util.Scanner;
 
public class Solution {
 
  private final static int INF = (int) 1e6 + 1;
 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt(), x = scanner.nextInt();
    int[] minCoinsToSum = new int[x + 1];
    Arrays.fill(minCoinsToSum, 1, x + 1, INF);
    for (int i = 0; i < n; ++i) {
      int coin = scanner.nextInt();
      for (int j = coin; j <= x; ++j) {
        minCoinsToSum[j] = Math.min(minCoinsToSum[j], minCoinsToSum[j - coin] + 1);
      }
    }
    System.out.println(minCoinsToSum[x] == INF ? -1 : minCoinsToSum[x]);
  }
}