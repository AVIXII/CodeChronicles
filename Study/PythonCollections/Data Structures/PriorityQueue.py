import heapq

# Create an empty heap
pq = []

# Insert elements
heapq.heappush(pq, 30)
heapq.heappush(pq, 10)
heapq.heappush(pq, 20)

# Remove and return the smallest element
print(heapq.heappop(pq))  # 10
print(heapq.heappop(pq))  # 20
print(heapq.heappop(pq))  # 30

arr = [30, 10, 20, 5, 50]
heapq.heapify(arr)

print(arr)  # Heapified list: [5, 10, 20, 30, 50]
print(heapq.heappop(arr))  # 5

arr = [30, 10, 20, 5, 50]

print(heapq.nsmallest(2, arr))  # [5, 10]
print(heapq.nlargest(2, arr))   # [50, 30]

