import java.util.*;

public class ArrayLists {
    @SuppressWarnings("unused")
    public static void main(String[] args) {
        // Initialisation
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<String> list34 = new ArrayList<>(10);  // Initializes the list with an initial capacity of 10
        
        // Size - size()
        int size = arr.size();  // 0
        
        // Empty - isEmpty()
        boolean is_empty = arr.isEmpty();  // false

        // Insert Elements - add(e), add(i, e), addFirst(), addLast(), addAll(C), addAll(idx, C)
        arr.add(32);  // At the last location [32]. Same as addLast()
        arr.add(4325);  // [32, 4325]
        arr.add(1, 45);  // At the particular index [32, 45, 4325]
        ArrayList<String> list1 = new ArrayList<>(Arrays.asList("Apple", "Banana"));
        ArrayList<String> list2 = new ArrayList<>(Arrays.asList("Cherry", "Date"));
        // Add all elements of list2 to list1
        list1.addAll(list2);  // // Output: [Apple, Banana, Cherry, Date]

        // Modify the elements of an arraylist - set(). It does not have First() or Last() suffix.
        int old = arr.set(0, 5);

        // Access elements - get()
        arr.get(2);  // 4325
        arr.getFirst();
        arr.getLast();

        // Remove Elements - remove(), removeFirst(), removeLast(), removeAll(C)
        arr.removeLast();  // [32, 45]
        arr.remove(1);  // [32]

        // Sublists - .sublist(st, en); [st, en]
        // arr.subList(2, 5).clear(); // removes all the elements from 2 to 5 (exclusive)
        
        // Clear - clear()
        arr.clear();  // The list is now empty. []
        for(int i=0;i<5;i++) arr.add(i);

        // Front - getFirst()
        int front = arr.getFirst();  // 0
        
        // Back - getLast()
        int back = arr.getLast();  // 4

        // Printing an arraylist - arr_name
        System.out.println(arr);

        // Check if the arraylist contains the element
        boolean isPresent = arr.contains(3);  // true

        // Enhanced for loop
        for (Integer i : arr) System.out.print(i);

        // Iterator for traversing - Can use the following two functions while mutating the current list.
        Iterator<Integer> iter = arr.iterator();
        while (iter.hasNext()) System.out.println(iter.next());

        ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        Iterator<String> iterator = list.iterator();
        
        while (iterator.hasNext()) {
            String fruit = iterator.next();
            
            // Remove 'Banana' from the list during iteration
            if ("Banana".equals(fruit)) {
                iterator.remove();
            }
        }
        
        System.out.println(list); // Output: [Apple, Cherry]
    }
}