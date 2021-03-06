import pandas as pd
"""
PRIMEIRO CASO COM 5000 BUCKETS
FUNÇÃO HASH BASEADO NAS LETRAS
"""

buckets = [0]*50000

def hashFunction(palavra):
    const = 0.6180339887
    tamanho = len(palavra)
    primeira = ord(palavra[0])
    if(len(palavra)>1):
        segunda = ord(palavra[1])
    else:
        segunda = 0
    
    numero = (tamanho*primeira)+segunda
    numero *= const
    soma = numero - int(numero)
    #print("Soma: ",soma)
    return int(49999*soma)

f = open("ascii_noaccent_noduplicates_FIXED_v2.txt","r")
a = f.readline()
while(a!= ''):
    a = a.replace('\n','')
    buckets[hashFunction(a)] += 1
    a = f.readline()
for i in range(0,len(buckets)):
    print("Bucket %d: %d valores" %(i+1,buckets[i]))
    
print("Bucket 0: ",buckets[0])

print("Resultados:")
print("\nMáximo:",max(buckets))
print("\nMínimo:",min(buckets))
print("\nMedia:",sum(buckets)/len(buckets))

df = pd.DataFrame(buckets)

print("\nDesvio padrão:",df.std())
print("\nMediana:",df.median())
print("\nModa:",df.mode())