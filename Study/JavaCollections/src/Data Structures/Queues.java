import java.util.Queue;
import java.util.LinkedList;

public class Queues {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();

        queue.offer(10);  // Enqueue
        queue.offer(20);
        queue.offer(30);

        System.out.println(queue.peek());  // Front: 10
        System.out.println(queue.poll());  // Dequeue (10)
        System.out.println(queue.isEmpty()); // Check if empty
    }
}