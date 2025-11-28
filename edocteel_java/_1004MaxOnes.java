import java.util.*;

public class _1004MaxOnes {
    public static void main (String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    public int longestOnes(int[] nums, int k) {
        assert k >= 0: "k should be greater than equal to 0";

        int size = nums.length;
        if (k >= size) return size;

        int left = 0;
        int currZeroes = 0;
        int ans = -1;
        for (int right = 0; right < size; ++right) {
            if (nums[right] == 0) ++currZeroes;

            while (currZeroes > k) {
                if (nums[left] == 0) --currZeroes;
                ++left;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}

class SolutionTest extends Solution {
    void testTwoFlips() {
        int[] nums = {0, 1, 1, 0, 1, 0, 0};
        int ans = longestOnes(nums, 2);
        assert ans == 5: "testTwoFlips failed";
    }

    void testInvalidInput() {
        try {
            longestOnes(new int[]{}, -1);
        } catch (AssertionError e) {
            System.out.printf("testInvalidInput passed with exception: %s\n", e.getMessage());
        }
    }
    
    public void run() {
        testTwoFlips();
        testInvalidInput();
        System.out.println("All scenarios passed!");
    }
}
