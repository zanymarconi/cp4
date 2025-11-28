public class _1413MinStartValue {
    public static void main(String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    int minStartValue(int[] nums) {
        int size = nums.length;
        if (size == 0) return 1;

        int currSum = 0, minSum = (int) -1e5;
        currSum = minSum = nums[0];
        for (int i = 1; i < size; ++i) {
            currSum += nums[i];
            minSum = Math.min(minSum, currSum);
        }

        if (minSum >= 1) return 1;
        return 1 - minSum;
    }
}

class SolutionTest extends Solution {
    void testAllNegativeNums() {
        int[] nums = {-1, -2, -3};
        int ans = minStartValue(nums);
        assert ans == 7;
    }

    public void run() {
        testAllNegativeNums();
        System.out.println("All scenarios passed");
    }
}

