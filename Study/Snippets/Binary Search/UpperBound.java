/*
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 * Where n is the search space size.
 */

import java.io.*;
import java.util.*;
  
public class UpperBound{
    public static int upper_bound(int[] nums, int x){
        int i = 0, j = nums.length;
        while(i < j){
            int mid = i + (j - i) / 2;
              
            if(nums[mid] <= x) i = mid + 1;
            else j = mid;
        }
  
        return i;
    }
  
    public static void main(String[] args) {
        // blah blah
    }
}