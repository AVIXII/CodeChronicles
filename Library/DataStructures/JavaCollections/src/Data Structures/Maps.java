import java.util.*;

public class Maps{
    @SuppressWarnings("unused")

    public static void main(String[] args) {
        //      TreeMap                     Hashmap
        // increasing order of        No particular ordering
        // key values                 of elements
        // Self balancing BST (RB)    Hash values -> Buckets
        // Search, Insert, Delete     Search, Insert, Delete
        //      O(log n)                    O(1)
        // 1 Null key, multiple null  No null key, Multiple null  
        // values                     values
        
        // Initialisation
        TreeMap<Character, Integer> tm = new TreeMap<>();
        HashMap<Character, Integer> hm = new HashMap<>();

        // Insert 
        tm.put('c', 3);
        tm.put('a', 3);
        hm.put('c', 3);
        hm.put('f', 32);

        // Size
        int sz;
        sz = tm.size();
        sz = hm.size();

        // Check if present
        char c = 'a';
        tm.getOrDefault(c, 0);
        hm.getOrDefault(c, 0);

        // Delete
        tm.remove(c);
        hm.remove(c);

        // Iterating over the TreeMap
        for (Map.Entry<Character, Integer> entry : tm.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        // Iterating over the HashMap
        for (Map.Entry<Character, Integer> entry : hm.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }
    }
}