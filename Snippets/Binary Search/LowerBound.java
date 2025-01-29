/*
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 * Where n is the search space size.
 */

import java.io.*;
import java.util.*;
 
public class LowerBound{
    public static int lower_bound(int[] nums, int x){
        int i = 0, j = nums.length;
        while(i < j){
            int mid = i + (j - i) / 2;
             
            if(x <= nums[mid]) j = mid;
            else i = mid + 1;
        }
 
        return i;
    }
 
    public static void main(String[] args) {
        // blah blah
    }
 }