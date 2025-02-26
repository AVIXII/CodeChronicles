
public class StringBuilders {
    public static void main(String[] args) {
        // Create a new StringBuilder
        StringBuilder sb = new StringBuilder("Hello");

        // Traversing a stringbuilder
        for (char ch : sb.toString().toCharArray())
            System.out.print(ch + " "); // Output: H e l l o ,   W o r l d !

        // Converting to a string
        String s = sb.toString();
        System.out.println(s);

        // Append a string
        sb.append(" World");
        System.out.println("After append: " + sb);  // Output: Hello World
        
        // Insert a substring
        sb.insert(6, "Java ");
        System.out.println("After insert: " + sb);  // Output: Hello Java World

        // Replace a substring - This is the same as cpp.
        sb.replace(6, 11, "Python ");
        System.out.println("After replace: " + sb);  // Output: Hello Python World

        // Delete a substring
        sb.delete(6, 13);
        System.out.println("After delete: " + sb);  // Output: Hello World

        // Reverse the string
        sb.reverse();
        System.out.println("After reverse: " + sb);  // Output: dlroW olleH
    }    
}
