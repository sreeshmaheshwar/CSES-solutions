import java.lang.IllegalArgumentException;
import java.util.Scanner;
 
public class Solution {
 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println(SquareMatrix.diceThrows(scanner.nextLong()));
  }
}

class SquareMatrix {
 
  private final static int MOD = (int) (1e9 + 7);
  private final long[][] a;
  private final int n;
 
  public SquareMatrix(long[][] a) {
    this.a = a;
    n = a.length;
    assert(a[0].length == n);
  }
 
  public SquareMatrix(int n) {
    this.n = n;
    a = new long[n][n];
  }
 
  public static SquareMatrix identity(int n) {
    SquareMatrix res = new SquareMatrix(n);
    for (int i = 0; i < n; ++i) {
      res.a[i][i] = 1;
    }
    return res;
  }
 
  // naive O(n^3) matrix multiplication
  public static SquareMatrix multiply(SquareMatrix x, SquareMatrix y) {
    if (x.n != y.n) {
      throw new IllegalArgumentException("Square matrices must have same dimensions to be multiplied");
    }
    SquareMatrix res = new SquareMatrix(x.n);
    for (int i = 0; i < x.n; ++i) {
      for (int j = 0; j < x.n; ++j) {
        for (int k = 0; k < x.n; ++k) {
          res.a[i][j] = (((x.a[i][k] * y.a[k][j]) % MOD) + res.a[i][j]) % MOD;
        }
      }
    }
    return res;
  }
 
  // binary exponentiation adapted for a matrix base - works in O(n^3 * log(exponent))
  public SquareMatrix power(long exponent) {
    SquareMatrix current = this;
    SquareMatrix res = identity(n);
    while (exponent > 0) {
      if ((exponent & 1) == 1) {
        res = multiply(res, current);
      }
      current = multiply(current, current);
      exponent >>= 1;
    }
    return res;
  }
 
  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("Matrix:\n");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        sb.append(a[i][j]).append(" ");
      }
      sb.append('\n');
    }
    return sb.toString();
  }
 
  public static long diceThrows(long n) {
    SquareMatrix matrix = new SquareMatrix(new long[][]{
        new long[]{1, 1, 1, 1, 1, 1}, 
        new long[]{1, 0, 0, 0, 0, 0},
        new long[]{0, 1, 0, 0, 0, 0}, 
        new long[]{0, 0, 1, 0, 0, 0}, 
        new long[]{0, 0, 0, 1, 0, 0}, 
        new long[]{0, 0, 0, 0, 1, 0}
    });
    return matrix.power(n + 1).a[0][5];
  }
}
