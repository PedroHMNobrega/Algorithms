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
        qtd[y] += qtd[x]
    elif peso[x] > peso[y]:
        pai[y] = x
        qtd[x] += qtd[y]
    else:
        pai[x] = y
        peso[y] += 1
        qtd[y] += qtd[x]

nVertice = 4
pai = [0] * (nVertice + 1)
peso = [0] * (nVertice + 1)
qtd = [1] * (nVertice + 1)

for i in range(1, nVertice + 1):
    pai[i] = i

#Testes
join(1, 2)
join(3, 4)
join(1, 3)
print(find(2))
print(find(4))
print(pai)
print(qtd)