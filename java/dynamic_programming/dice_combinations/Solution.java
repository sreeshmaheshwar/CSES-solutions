import java.util.Scanner;

public class Solution {

  private static final int MOD = (int) 1e9 + 7;

  public static int add(int a, int b) {
    return (int) ((long) a + b) % MOD;
  }

  public static int subtract(int a, int b) {
    return add(a - b, MOD);
  }

  // O(N) time algorithm, independent of number of dice faces!
  public static int diceCombinations(int n, int diceFaces) {
    int[] waysToSum = new int[n + 1];
    int waysToGetPreviousRoll = waysToSum[0] = 1;
    for (int i = 1; i <= n; ++i) {
      waysToSum[i] = waysToGetPreviousRoll;
      waysToGetPreviousRoll = add(waysToGetPreviousRoll, waysToSum[i]);
      if (i - diceFaces >= 0) {
        waysToGetPreviousRoll = subtract(waysToGetPreviousRoll, waysToSum[i - diceFaces]);
      }
    }
    return waysToSum[n];
  }

  public static void main(String[] args) {
    System.out.println(diceCombinations(new Scanner(System.in).nextInt(), 6));
  }
}