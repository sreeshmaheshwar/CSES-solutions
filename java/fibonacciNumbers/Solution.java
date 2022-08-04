import java.security.InvalidParameterException;
import java.util.Scanner;
 
public class Solution {
 
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println(Matrix.fib(scanner.nextLong()));
  }
}

class Matrix {
 
  private final static int MOD = (int) (1e9 + 7);
  private final long[][] a;
  private final int n;
 
  public Matrix(long[][] a) {
    this.a = a;
    n = a.length;
    assert(a[0].length == n);
  }
 
  public Matrix(int n) {
    this.n = n;
    a = new long[n][n];
  }
 
  public static Matrix identity(int n) {
    Matrix res = new Matrix(n);
    for (int i = 0; i < n; ++i) {
      res.a[i][i] = 1;
    }
    return res;
  }
 
  // naive O(n^3) implementation
  public static Matrix multiply(Matrix x, Matrix y) {
    if (x.n != y.n) {
      throw new InvalidParameterException("Square matrices must have same dimensions to be multiplied");
    }
    Matrix res = new Matrix(x.n);
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
  public Matrix power(long exponent) {
    Matrix current = this;
    Matrix res = identity(n);
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
 
  public static long fib(long n) {
    Matrix fibMatrix = new Matrix(new long[][]{new long[]{1, 1}, new long[]{1, 0}});
    return fibMatrix.power(n).a[0][1];
  }
}
