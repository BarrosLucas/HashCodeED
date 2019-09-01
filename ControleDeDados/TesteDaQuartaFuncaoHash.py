import pandas as pd
import math
"""
PRIMEIRO CASO COM 5000 BUCKETS
FUNÇÃO HASH BASEADO NAS LETRAS
"""

buckets = [0]*50000

def hashFunction(palavra):
    a = (5**(1/2)-1)/2
    primeiro = ord(palavra[0])
    tamanho = len(palavra)
    if(tamanho > 1):
        segundo = ord(palavra[1])
    else:
        segundo = 0
    numero = (primeiro * tamanho)+segundo
    s = numero*a
    s = (s-math.floor(s))*numero
    saida = int(s)
    return saida%49999

f = open("ascii_noaccent_noduplicates_FIXED_v2.txt","r")
a = f.readline()
while(a!= ''):
    a = a.replace('\n','')
    buckets[hashFunction(a)] += 1
    a = f.readline()
for i in range(0,len(buckets)):
    print("Bucket %d: %d valores" %(i+1,buckets[i]))

print("Resultados:")
print("\nMáximo:",max(buckets))
print("\nMínimo:",min(buckets))
print("\nMedia:",sum(buckets)/len(buckets))

df = pd.DataFrame(buckets)

print("\nDesvio padrão:",df.std())
print("\nMediana:",df.median())
print("\nModa:",df.mode())