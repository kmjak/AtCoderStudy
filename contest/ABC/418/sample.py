import random as rd
N=int(2e5)
""""
D問題のサンプルコードを生成するつもりで書いたが、ローカルだと重たすぎて動かなかった。
"""
print(N)
for _ in range(N):
  print(rd.randint(0,1),end='')

