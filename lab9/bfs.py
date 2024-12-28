def bfs(graph,start):
    visited=set()
    queue=Queue()
    queue.put(start)
    visited.add(start)
    while not queue.empty():
        current=queue.get()
        print(current, end=" ")
        for neighbor in graph[current]:
            if neighbor not in visited:
                queue.put(neighbor)
                visited.add(neighbor)