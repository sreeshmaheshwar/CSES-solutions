import java.util.Scanner;
 
public class Solution {
 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println(SquareMatrix.diceThrows(scanner.nextLong()));
  }
}

class SquareMatrix {

  private final static int MOD = (int) 1e9 + 7;
  protected final int n;
  protected final long[][] a;

  public SquareMatrix(int n) {
    this.n = n;
    a = new long[n][n];
  }

  public SquareMatrix(long[][] a) {
    this.a = a;
    n = a.length;
    assert(a[0].length == n);
  }

  boolean canBeSet(int row, int col, long value) {
    return 0 <= row && row < n && 0 <= col && col < n;
  }

  public void setCell(int row, int col, long value) {
    if (canBeSet(row, col, value)) {
      a[row][col] = value;
    }
  }

  public SquareMatrix power(long exponent) {
    SquareMatrix current = this;
    SquareMatrix res = getIdentity(n);
    while (exponent > 0) {
      if ((exponent & 1) == 1) {
        res = res.multiply(current);
      }
      current = current.multiply(current);
      exponent >>= 1;
    }
    return res;
  }

  SquareMatrix getIdentity(int n) {
    SquareMatrix res = new SquareMatrix(n);
    for (int i = 0; i < n; ++i) {
      res.a[i][i] = 1;
    }
    return res;
  }

  SquareMatrix multiply(SquareMatrix matrix) {
    SquareMatrix res = new SquareMatrix(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          res.a[i][j] = (((a[i][k] * matrix.a[k][j]) % MOD) + res.a[i][j]) % MOD;
        }
      }
    }
    return res;
  }
 
  public static long diceThrows(long n) {
    SquareMatrix diceMatrix = new SquareMatrix(new long[][]{
        new long[]{1, 1, 1, 1, 1, 1}, 
        new long[]{1, 0, 0, 0, 0, 0},
        new long[]{0, 1, 0, 0, 0, 0}, 
        new long[]{0, 0, 1, 0, 0, 0}, 
        new long[]{0, 0, 0, 1, 0, 0}, 
        new long[]{0, 0, 0, 0, 1, 0}
    });
    return diceMatrix.power(n).a[0][0];
  }
}
