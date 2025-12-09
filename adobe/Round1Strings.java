package adobe;
import java.util.*;

// You are given two lowercase strings, s and t. You may reorder the characters of t in any way you choose. Your goal is to 
// rearrange t so that:
//
// s appears as a subsequence of the reordered string, and
// among all valid reorderings that satisfy this condition, the result is lexicographically smallest.
// A subsequence means characters of s must appear in order, but not necessarily contiguously.
 
// Examples:
// Input:
// s = "ab"
// t = "cba"
// Output:
// "abc"
// Input:
// s = "dcbe"
// t = "bedbaecfc"
// Output:
// "abcdcbeef"
// Input:
// s = "babaisyou"
// t = "flagiswin"
// Output:
// "Impossible"
// Input:
// s: "aa"
// t: "abab"
// Output:
// "aabb"
 
// Check if all letters of s appears in t
// Remaining letters of t will be enterred in a-z order
//
// Second example
// "dcbe"
// Remaining from t: bedbaecfc: abbccdeef: "abcef"
// Merge "dcbe" with "abcf" by order a-z
// abcdcbeef
class Solver {
    public String solve (String S, String T) {
        int[] freqS = new int[26];
        int[] freqT = new int[26];
        Arrays.fill(freqS, 0);
        Arrays.fill(freqT, 0);
        
        // Count frequency
        for (char ch: S.toCharArray())
            freqS[ch-'a']++;
        for (char ch: T.toCharArray())
            freqT[ch-'a']++;
        
        // Check Possiblility
        boolean valid = true;
        for (int i = 0; i < 26; ++i)
            if (freqT[i] < freqS[i]) {
                valid = false;
                break;
            } 
        if (!valid) return "Impossible";
        
        // Subtract in T
        for (int i = 0; i < 26; ++i)
            freqT[i] -= freqS[i];
            
        // System.out.printf("\tDebug FreqT: %s\n", Arrays.toString(freqT));
        // System.out.printf("\tDebug FreqS: %s\n", Arrays.toString(freqS));
        
        StringBuilder sb = new StringBuilder();
        int ptr = 0;
        for (int i = 0; i < 26; ++i) {
            char ch = (char)('a' + i);
            
            while (freqT[i] > 0) {
                sb.append((char)('a' + i));
                freqT[i]--;
            }
            
            while (ptr < S.length() && S.charAt(ptr) <= ch) {
                char nch = S.charAt(ptr);
                sb.append(nch);
                ptr++;
            }
        
        }
        return sb.toString();
    }
}

class Round1Strings {
    
    public static void main(String[] args) {
        System.out.println(new Solver().solve("babaisyou", "flagiswin"));
        System.out.println(new Solver().solve("ab", "cba"));
        System.out.println(new Solver().solve("dcbe", "bedbaecfc"));
    }
}
