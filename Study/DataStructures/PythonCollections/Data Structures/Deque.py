from collections import deque

queue = deque()

queue.append(10)  # Enqueue
queue.append(20)
queue.append(30)

print(queue[0])  # Front: 10
print(queue.popleft())  # Dequeue (10)
print(len(queue) == 0)  # Check if empty