import java.util.*;

public class Sets {
    @SuppressWarnings("unused")

    public static void main(String[] args) {
        //			Set 			    	Tree Set                LinkedHash Set
        //	increasing order 	    	No particular ordering      Order of insertion
        // Uses self balancing BST    	Hash Table                  DLL with a hashtable
        // Search, Insert, Delete       Search, Insert, Delete      Search, Insert, Delete
        //        O(log(n)) 				O(1), Worst - O(n)         O(1), Worst - O(n)     O(n) due to hash collisions

        // Initialisation
        HashSet<Integer> hs = new HashSet<>();
        TreeSet<Integer> ts = new TreeSet<>();
        LinkedHashSet<Integer> ls = new LinkedHashSet<>();
        TreeSet<String> treeSet = new TreeSet<>(Comparator.reverseOrder());

        // Insertion
        hs.add(1);
        ts.add(3);

        // Size 
        int szhs = hs.size();

        // First element of Tree Set
        ts.first();
        ts.last();

        // Check if present
        boolean is_present_hs = hs.contains(3);

        // Deletion
        hs.remove(4);
        ts.removeFirst();
        ts.removeLast();
        ts.remove(2);

        // Clear
        hs.clear();

        // Iterating over the Set
        for (Integer el : hs) 
            System.out.println(el);
    }
}
