def find(x):
    if pai[x] == x: 
        return x
    pai[x] = find(pai[x])
    return pai[x]

def join(x, y):
    x = find(x)
    y = find(y)
    if x == y: return
    if peso[x] < peso[y]:
        pai[x] = y
    elif peso[x] > peso[y]:
        pai[y] = x
    else:
        pai[x] = y
        peso[y] += 1

def krustal(arestas, nVertices):
    arestas.sort()
    mst = [[] for e in range(nVertices - 1)]
    tamanho = 0
    for a in range(len(arestas)):
        if find(arestas[a][1]) != find(arestas[a][2]):
            join(arestas[a][1], arestas[a][2])
            mst[tamanho] = arestas[a]
            tamanho += 1
    return mst

vert, aresta = 6, 5
pai = [0] * (vert + 1)
for i in range(vert + 1):
    pai[i] = i
peso = [0] * (vert + 1)

arestas = []
arestas.append((5, 1, 6))
arestas.append((4, 5, 6))
arestas.append((4, 5, 4))
arestas.append((9, 3, 4))
arestas.append((3, 2, 3))
arestas.append((2, 1, 2))
arestas.append((1, 1, 5))
arestas.append((7, 2, 5))
arestas.append((3, 3, 5))

arvoreMinima = krustal(arestas, vert)
soma = 0
for e in arvoreMinima:
    print(e)
    soma += e[0]

print('A soma dos caminhos é', soma)