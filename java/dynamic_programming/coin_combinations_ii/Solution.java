import java.util.Scanner;
 
public class Solution {
 
  private static final int MOD = (int) 1e9 + 7;
 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt(), x = scanner.nextInt();
    long[] waysToSum = new long[x + 1];
    waysToSum[0] = 1;
    for (int i = 0; i < n; ++i) {
      int coin = scanner.nextInt();
      for (int j = coin; j <= x; ++j) {
        waysToSum[j] = (waysToSum[j] + waysToSum[j - coin]) % MOD;
      }
    }
    System.out.println(waysToSum[x]);
  }
}