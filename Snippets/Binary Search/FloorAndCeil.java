import java.util.* ;
import java.io.*; 

public class FloorAndCeil {
   private static int lower_bound(int[] nums, int x){
        int i = 0, j = nums.length;
        while(i < j){
            int mid = i + (j - i) / 2;
             
            if(x <= nums[mid]) j = mid;
            else i = mid + 1;
          }  

        return i;
    }

    public static int upper_bound(int[] nums, int x){
        int i = 0, j = nums.length;
        while(i < j){ 
            int mid = i + (j - i) / 2;
              
            if(nums[mid] <= x) i = mid + 1;
            else j = mid;
        }
  
        return i;
    }


    public static int[] getFloorAndCeil(int[] a, int n, int x) {
      // Floor: ub--
      // Ceil: lb

      int floor = upper_bound(a, x) - 1;
      int ceil = lower_bound(a, x);

      int[] ans = {-1, -1};
      if(0 <= floor && floor < n) ans[0] = a[floor];
      if(0 <= ceil && ceil < n) ans[1] = a[ceil];
       
      return ans;
    }
}