from queue import Queue

def bfs(no):
    q = Queue()
    vis = [False] * nVer
    dist = [0] * nVer

    q.put(no)
    vis[no] = True
    dist[no] = 0

    while not q.empty():
        top = q.get()
        for neig in listaAdj[top]:
            if not vis[neig]:
                vis[neig] = True
                dist[neig] = dist[top] + 1
                print('Visitei o %d' % (neig + 1))
                print('Distancia de %d até %d é %d\n' % (no + 1, neig + 1, dist[neig]))
                q.put(neig)

nVer = 9
listaAdj = [[] for e in range(nVer)]
listaAdj[0].append(1)
listaAdj[1].extend([0, 4, 2, 5, 7])
listaAdj[4].extend([1, 8])
listaAdj[8].append(4)
listaAdj[2].extend([1, 3])
listaAdj[3].append(2)
listaAdj[5].extend([1, 6])
listaAdj[6].append(5)
listaAdj[7].append(1)

bfs(1)