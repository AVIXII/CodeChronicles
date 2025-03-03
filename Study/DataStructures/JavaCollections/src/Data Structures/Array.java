import java.util.*;

public class Array {
    @SuppressWarnings("unused")
    public static void main(String[] args) {
        // Declaration
        int[] arr1;

        // Initialisation
        arr1 = new int[6];
        int[] arr2 = {5, 4, 3, 2, 1};
        arr1[0] = arr1[1] = 1;

        // Size
        int size = arr1.length;  // 6

        // Iterating over an array
        for(int el: arr2) System.out.print(el + " ");
        
        // Print the array
        System.out.println(Arrays.toString(arr2));  // [5, 4, 3 ,2 ,1]
    }
}
