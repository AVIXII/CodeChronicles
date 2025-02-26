import java.util.Stack;

public class Stacks {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(10); // Push element
        stack.push(20);
        stack.push(30);
        
        System.out.println(stack.peek());  // Top element: 30
        System.out.println(stack.pop());   // Removes 30
        System.out.println(stack.isEmpty()); // Check if empty
    }
}