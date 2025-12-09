public class _643SubarraySum {
    public static void main(String[] args) {
        new SolutionTest643().run();
    }
}

// Author: Zany Marconi
class Solution643 {
    public double findMaxAverage(int[] nums, int k) {
        assert k >= 0 : "k should be greater than 0";
        
        int size = nums.length;
        assert k <= size: "k should be less than nums size";

        double sum = 0, maxSum = -1e10;
        for (int i = 0; i < k; ++i)
            sum += nums[i];
        maxSum = Math.max(sum, maxSum);

        for (int i = k; i < size; ++i) {
            sum += nums[i];
            sum -= nums[i-k];
            maxSum = Math.max(sum, maxSum);
        }

        return maxSum / k;
    }
}

class SolutionTest643 extends Solution643 {
    double EPS = 1e-6;

    void testAllNegative() {
        int[] nums = { -8, -9, -2, -6};
        double ans = findMaxAverage(nums, 2);
        System.out.printf("testAllNegative: ans is %.2f\n", ans);
        double expected = -4;
        assert (ans > expected - EPS && ans < expected + EPS): "testAllNegative failed";
    }

    void testInvalidInput() {
        int[] nums = {-4, 7, 10};
        try {
            findMaxAverage(nums, 5);
        } catch (AssertionError e) {
            System.out.printf("testInvalidInput pass with exception e: %s\n", e.getMessage());
        }
    }

    public void run() {
        testAllNegative();
        testInvalidInput();
        System.out.println("All scenarios passed!");
    }
}
