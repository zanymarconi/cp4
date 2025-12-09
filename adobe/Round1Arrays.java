package adobe;

// You are given an array of n integers and a number k representing how many operations you may perform. In each operation, you may select any element of the array and increase it by 1. You may apply multiple increments to the same element as long as the total number of operations does not exceed k.
// After performing at most k operations, your goal is to maximize how many times a single integer appears in the array. If multiple values can achieve the same maximum frequency, return the smallest such value.

// Input:
// n = 5, k = 3
// array = [6, 3, 4, 0, 2]
// Output:
// 3 4 (frequency, number)
// Input:
// n = 3, k = 4
// array = [5, 5, 5]
// Output:
// 3 5
// Input:
// n = 5, k = 3

// Add entire array in hashmap
// Recursively backtrack from first (index, k)
//      Check if increasing value at index increases frequency
//      
// Time O (N * K) Memoization on Top Down DP
//
// if K is large, only go till max of element in the array 
// if O (N * max(array))
//
// Check maximum achievable frequency of each element in the array
// O (N^2)
//
// Sort
// 0 2 3 4 6
//   0
//   2 -> 2 2's (still 1 k left)
//   3 -> utilize previous result (2 3's no 0 left)
//   4 ->
// at 4:
//     end at 4
//     start 4*3 = 12
//     current sum = 6
//     number of operations < k
// O (N)

public class Round1Arrays {
    
}
