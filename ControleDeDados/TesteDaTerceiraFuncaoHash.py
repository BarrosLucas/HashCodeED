import pandas as pd
"""
PRIMEIRO CASO COM 5000 BUCKETS
FUNÇÃO HASH BASEADO NAS LETRAS
"""
maximo = 0
palavra = ""
buckets = [0]*50000

def hashFunction(palavra):
    soma = 0
    tamanho = len(palavra)
    for i in palavra:
        soma += ord(i)*31*tamanho
    return soma%49999

f = open("ascii_noaccent_noduplicates_FIXED_v2.txt","r")
a = f.readline()
while(a!= ''):
    a = a.replace('\n','')
    buckets[hashFunction(a)] += 1
    if(buckets[hashFunction(a)] > maximo):
        maximo = buckets[hashFunction(a)]
        palavra = a
    a = f.readline()
for i in range(0,len(buckets)):
    print("Bucket %d: %d valores" %(i+1,buckets[i]))

print("Resultados:")
print("\nMax calculado: ",maximo)
print("\nPalavra: ",palavra)
print("\nMáximo:",max(buckets))
print("\nMínimo:",min(buckets))
print("\nMedia:",sum(buckets)/len(buckets))

df = pd.DataFrame(buckets)

print("\nDesvio padrão:",df.std())
print("\nMediana:",df.median())
print("\nModa:",df.mode())