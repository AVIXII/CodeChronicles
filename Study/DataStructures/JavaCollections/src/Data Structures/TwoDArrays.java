public class TwoDArrays {
    public static void main(String[] args) {

        // Initialisation
        int[][] mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };  // Static Arrays
        System.out.println(mat);  // Dummy statement to remove error squiggles

        int[][] mat1 = new int[3][3];  // Dynamic Arrays
        for (int i = 0; i < mat1.length; i++) for (int j = 0; j < mat1[i].length; j++) mat1[i][j] = i + j; 

        int[][] jaggedArray = new int[3][];  // Jagged Arrays
        jaggedArray[0] = new int[2];
        jaggedArray[1] = new int[4];
        jaggedArray[2] = new int[3];

        // Printing 2D array
        for (int[] row : jaggedArray) {
            for (int col : row) {
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }    
}
