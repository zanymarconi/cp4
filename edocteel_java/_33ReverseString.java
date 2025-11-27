import java.util.*;

public class _33ReverseString {
  public static void main(String[] args) {
    SolutionTest solTest = new SolutionTest();
    solTest.runTestScenarios();
  }
}

// Author: Prakhar Dhama
class Solution {
  public void reverseString(char[] s) {
    int len = s.length;

    for (int i = 0; i < len / 2; ++i) {
      char temp = s[i];
      s[i] = s[len - 1 - i];
      s[len - 1 - i] = temp;
    }
  }
}

class SolutionTest extends Solution {

  private void testOddLenList() {
    char[] str = { 'a', 'b', 'c' };
    reverseString(str);
    String reversed = Arrays.toString(str);
    System.out.printf("Reversed string = %s\n", reversed);
    assert reversed.equals("cba");
  }

  private void testEvenLenList() {
    char[] str = { 'a', 'b', 'c', 'd', 'e', 'f' };
    reverseString(str);
    String reversed = Arrays.toString(str);
    System.out.printf("Reversed string = %s\n", Arrays.toString(str));
    assert reversed.equals("fedcba");
  }

  public void runTestScenarios() {
    testOddLenList();
    testEvenLenList();
  }
}