def floydWarshaw(nVer):
    for k in range(nVer):
        for i in range(nVer):
            for j in range(nVer):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist
    
nVer = 5

dist = [[float('inf') for e in range(nVer)] for e in range(nVer)]
for i in range(nVer):
    dist[i][i] = 0

listaAdj = [[] for e in range(nVer)]
listaAdj[0].append(1)
listaAdj[1].append(0)
dist[0][1] = 5
dist[1][0] = 5

listaAdj[0].append(4)
listaAdj[4].append(0)
dist[0][4] = 1
dist[4][0] = 1

listaAdj[2].append(1)
listaAdj[1].append(2)
dist[2][1] = 3
dist[1][2] = 3

listaAdj[4].append(1)
listaAdj[1].append(4)
dist[4][1] = 3
dist[1][4] = 3

listaAdj[4].append(3)
listaAdj[3].append(4)
dist[3][4] = 4
dist[4][3] = 4

listaAdj[2].append(3)
listaAdj[3].append(2)
dist[3][2] = 2
dist[2][3] = 2

distancia = floydWarshaw(nVer)
j = 1
print('   1  2  3  4  5')
for e in distancia:
    print(j, e)
    j += 1
