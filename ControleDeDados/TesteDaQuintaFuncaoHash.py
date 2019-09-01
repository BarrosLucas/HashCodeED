import pandas as pd
"""
PRIMEIRO CASO COM 5000 BUCKETS
FUNÇÃO HASH BASEADO NAS LETRAS
"""

buckets = [0]*50000

def hashFunction(palavra):
    tamanho = len(palavra)
    primeiro = ord(palavra[0])
    if(tamanho > 1):
        segundo = ord(palavra[1])
    else:
        segundo = 0
    numero = (primeiro * tamanho)+segundo
    return (numero*2654435761)%49999;
    

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