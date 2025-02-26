import java.util.PriorityQueue;

public class PriorityQueues {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        pq.offer(30);
        pq.offer(10);
        pq.offer(20);

        System.out.println(pq.poll()); // 10 (smallest element)
        System.out.println(pq.poll()); // 20
        System.out.println(pq.poll()); // 30
    }
}