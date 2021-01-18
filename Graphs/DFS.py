def dfs(no):
    vis[no] = True
    for neig in listaAdj[no]:
        if not vis[neig]:
            print('Visitei o %d' % (neig + 1))
            dfs(neig)

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

vis = [False] * nVer
dfs(0)