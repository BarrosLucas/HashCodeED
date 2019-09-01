maximun = 0
f = open("ascii_noaccent_noduplicates_FIXED_v2.txt","r")
a = f.readline()
while(a!= ''):
    a = a.replace('\n','')
    if(len(a) > maximun):
        maximun = len(a)
    a = f.readline()
print("Max.:",maximun)
    
