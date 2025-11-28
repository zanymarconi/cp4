import java.util.*;

public class _2090KRadiusSum {
    public static void main(String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    public int[] getAverages(int[] nums, int k) {
        int size = nums.length;
        if (size == 0)
            return new int[] {};

        int[] radiusSum = new int[size];
        if (k > size) {
            Arrays.fill(radiusSum, -1);
            return radiusSum;
        }

        long[] prefixSum = new long[size];
        prefixSum[0] = nums[0];
        for (int i = 1; i < size; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for (int i = 0; i < k; ++i)
            radiusSum[i] = -1;
        for (int i = k; i < size - k; ++i) {
            long currSum = prefixSum[i + k] - prefixSum[i - k] + nums[i - k];
            radiusSum[i] = (int) (currSum / (2 * k + 1));
        }
        for (int i = size - k; i < size; ++i)
            radiusSum[i] = -1;

        return radiusSum;
    }
}

class SolutionTest extends Solution {
    void testPositiveArray() {
        int[] nums = { 2, 3, -4, 1, 8 };
        int[] ans = getAverages(nums, 1);
        System.out.printf("testPositiveArray response: %s\n", Arrays.toString(ans));
        assert Arrays.equals(ans, new int[] { -1, 0, 0, 1, -1 });
    }

    public void run() {
        testPositiveArray();
        System.out.println("All tests passed");
    }
}
