import pandas as pd
"""
PRIMEIRO CASO COM 5000 BUCKETS
FUNÇÃO HASH BASEADO NAS LETRAS
"""

buckets = [0]*50000
maximo = 0
palavra = ""
bucket = 0
def hashFunction(palavra):
    soma = 0
    for i in range(0,len(palavra)):
        soma += ord(palavra[i])*(26**i)
        if(palavra == "superantipatico"):
            print("Soma: %d" %(soma))
    
    if(palavra == "superantipatico"):
        print("Soma: ",soma)
        print("Resto: ",soma%49999)
    return soma%49999

f = open("ascii_noaccent_noduplicates_FIXED_v2.txt","r")
a = f.readline()
while(a!= ''):
    a = a.replace('\n','')
    buckets[hashFunction(a)] += 1
    if(buckets[hashFunction(a)] > maximo):
        maximo = buckets[hashFunction(a)]
        palavra = a
        bucket = hashFunction(a)
    a = f.readline()
#sfor i in range(0,len(buckets)):
    #print("Bucket %d: %d valores" %(i+1,buckets[i]))
print("\nMax calculado: ",maximo)
print("\nPalavra max calculada: ",palavra)
print("Resultados:")
print("\nMáximo:",max(buckets))
print("\nMínimo:",min(buckets))
print("\nMedia:",sum(buckets)/len(buckets))

df = pd.DataFrame(buckets)

print("\nDesvio padrão:",df.std())
print("\nMediana:",df.median())
print("\nModa:",df.mode())