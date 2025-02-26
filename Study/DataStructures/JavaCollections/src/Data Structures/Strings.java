import java.util.Scanner;

public class Strings {

    @SuppressWarnings("unused")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Strings in java are immutable

        // Declaration and Initialisation
        String a;
        a = "Rishabh";
        String s = "Rishabh";

        // Input - "Hello world is a program" - trim() is used to remove leading and trailing whitespaces
        s = sc.next().trim();  // Hello
        s = sc.nextLine().trim();  // Hello World is a program
        
        // Split - Split in java is inbuilt to enable splitting according to regex expression. Such functionality isn't even available in python (We have to use the regex module).
        s.split(" ");
        s.split("[; ]");

        // Length - length()
        int l = s.length();

        // Access a character of the string
        char c = s.charAt(3);

        // Traversing a string
        for (char ch : s.toCharArray())
            System.out.print(ch + " "); // Output: H e l l o ,   W o r l d !

        // Concatinating strings
        s = "rishabh" + " " + "ramdhave";

        // Clear a string - Assign it to a new empty string
        s = "";
        
        // Comparing two strings
        String s1 = "abcasfaasdf", s2="dsaf";
        if(s1.equals(s2)) System.out.println("They are equal");
        if(s1.compareTo(s2) > 0) System.out.println("The first string is lexicographically greater.");

        // Checking empty
        boolean is_empty = s1.isEmpty();

        // Substring - Cpp index range [s, e)
        s = s1.substring(2, 5);

        // Find in strings
        boolean found = s.contains(a); // Checking if present
        int index = s.indexOf(s2);  // index if found. -1 if string not found.
        
        // Methods on strings
        s1 = s1.toLowerCase();
        s1 = s1.toUpperCase();
        
        sc.close();
    }
}
