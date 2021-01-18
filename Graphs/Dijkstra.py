from queue import PriorityQueue

def dijkstra(no):
    q = PriorityQueue()
    dist = [float('inf')] * nVer
    
    q.put(no)
    dist[no] = 0
    while not q.empty():
        top = q.get()
        for neig in listaAdj[top]:
            if dist[neig[0]] > dist[top] + neig[1]:
                dist[neig[0]] = dist[top] + neig[1]
                q.put(neig[0])
    return dist

nVer = 7

listaAdj = [[] for e in range(nVer)]
listaAdj[0].append((1, 5))
listaAdj[1].append((0, 5))

listaAdj[0].append((2, 4))
listaAdj[2].append((0, 4))

listaAdj[0].append((3, 8))
listaAdj[3].append((0, 8))

listaAdj[1].append((4, 7))
listaAdj[4].append((1, 7))

listaAdj[2].append((4, 5))
listaAdj[4].append((2, 5))

listaAdj[3].append((4, 12))
listaAdj[4].append((3, 12))

listaAdj[3].append((5, 10))
listaAdj[5].append((3, 10))

listaAdj[2].append((5, 11))
listaAdj[5].append((2, 11))

listaAdj[4].append((6, 9))
listaAdj[6].append((4, 9))

listaAdj[5].append((6, 6))
listaAdj[6].append((5, 6))

print(dijkstra(0))



