import java.util.*;

public class _977SquareArray {
    public static void main(String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    public int[] sortedSquares(int[] nums) {
        int size = nums.length;
        if (nums == null || size == 0)
            return new int[] {};

        int[] squares = new int[size];
        int left = 0, right = size - 1, k = size - 1;
        while (left <= right) {
            int numl = Math.abs(nums[left]);
            int numr = Math.abs(nums[right]);

            if (numl > numr) {
                squares[k--] = numl * numl;
                left++;
            } else {
                squares[k--] = numr * numr;
                --right;
            }
        }
        return squares;
    }
}

class SolutionTest extends Solution {
    public void testMixedNums() {
        int[] nums = { -4, -1, 0, 3, 10 };
        int[] ans = sortedSquares(nums);
        System.out.printf("Squared Array: %s\n", Arrays.toString(ans));
        int[] expected = { 0, 1, 9, 16, 100 };
        assert Arrays.equals(ans, expected) == true;
    }

    public void testWithoutZero() {
        int[] nums = { -7, -3, 2, 3, 11 };
        int[] ans = sortedSquares(nums);
        System.out.printf("Squared Array: %s\n", Arrays.toString(ans));
        int[] expected = { 4, 9, 9, 49, 121 };
        assert Arrays.equals(ans, expected);
    }

    public void run() {
        testMixedNums();
        testWithoutZero();
    }
}