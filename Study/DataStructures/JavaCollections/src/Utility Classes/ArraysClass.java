import java.util.*;

public class ArraysClass {
    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 3};

        // .sort()
        Arrays.sort(arr); // [1, 2, 3, 5, 8]
        
        // .toString()
        System.out.println("Sorted Array: " + Arrays.toString(arr)); // Output: [1, 2, 3, 5, 8]

        // .binarySearch() - If found index, else (-index-1)
        Arrays.binarySearch(arr, 3);  // 2

        // .fill() - Fill the complete array
        Arrays.fill(arr, 7); // [7, 7, 7, 7, 7]

        // .equals(arr1, arr2) - Compares the content of the two arrays
        Integer[] arr1 = {1, 2, 3};
        Integer[] arr2 = {1, 2, 3};
        Arrays.equals(arr1, arr2);  // True

        // .deepEquals(Object[] a1, Object[] a2) - Here it is necessary to find the wrapper class objects
        Arrays.deepEquals(arr1, arr2);


    }
}
