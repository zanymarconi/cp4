import java.util.Arrays;

public class _1480RunningSum {
    public static void main(String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    int[] runningSum(int[] nums) {
        int size = nums.length;
        if (size == 0) return new int[]{};

        int[] prefix = new int[size];
        prefix[0] = nums[0];

        for (int i = 1; i < size; ++i)
            prefix[i] = prefix[i-1] + nums[i];

        return prefix;
    }
}

class SolutionTest extends Solution {
    void testNumsSize3() {
        int[] nums = {1, -1, 3};
        int[] ans = runningSum(nums);
        int[] expected = {1, 0, 3};

        assert Arrays.equals(ans, expected): "testNumsSize3 failed";
    }

    public void run() {
        testNumsSize3();
        System.out.println("All tests passsed");
    }
}
