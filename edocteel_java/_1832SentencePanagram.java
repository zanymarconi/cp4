import java.util.*;

public class _1832SentencePanagram {
    public static void main(String[] args) {
        new SolutionTest().run();
    }
}

// Author: Zany Marconi
class Solution {
    public boolean checkIfPangram(String sentence) {
        Map<Character, Integer> freqMap = new HashMap<>();

        for (int i = 0; i < sentence.length(); ++i) {
            char ch = sentence.charAt(i);
            freqMap.merge(ch, 1, Integer::sum);
        }

        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (!freqMap.containsKey(ch)) return false;

        return true;
    }
}

class SolutionTest extends Solution {

    void testPangram() {
        String sentence = "The quick brown fox jumps over a little lazy dog";
        assert checkIfPangram(sentence);
    }

    public void run() {
        testPangram();
        System.out.printf("All tests passed!");
    }
}
