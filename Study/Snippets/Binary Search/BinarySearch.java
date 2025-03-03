/*
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 * Where n is the search space size.
 */

import java.io.*;
import java.util.*;

public class BinarySearch{
    public static int binary_search(int[] nums, int x){
        int i = 0, j = nums.length-1;  // j = n is not required unlike in case of lb and ub.
        while(i < j){  // The equality sign can be ignored. If i == j there is no need to do any operation on the search space.
            int mid = i + (j - i) / 2;  // Better way of doing instead of (i+j)/2 to avoid integer overflow
            
            if(nums[mid] == x) return mid;
            else if(x < nums[mid]) j = mid - 1;  // Left search space
            else i = mid + 1;  // Right search space
        }

        return -1;  // Answer does not exist in the range
    }

    public static void main(String[] args) {
        // blah blah
    }
}