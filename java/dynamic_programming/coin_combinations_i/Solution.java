import java.util.Scanner;

public class Solution {

  private static final int MOD = (int) 1e9 + 7;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt(), x = scanner.nextInt();

    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = scanner.nextInt();
    }

    long[] waysToSum = new long[x + 1];
    waysToSum[0] = 1;
    for (int i = 1; i <= x; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i - a[j] >= 0) {
          waysToSum[i] = (waysToSum[i] + waysToSum[i - a[j]]) % MOD;
        }
      }
    }

    System.out.println(waysToSum[x]);
  }
}