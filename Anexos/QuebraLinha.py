file = open('constituicao.txt','r')
newFile = open('constituicaoPronto.txt','w')
a = file.readline()
while(a != ''):
    if(a != '\n' and a != '-'):
        a = a.replace(';','')
        a = a.replace(':','')
        a = a.replace('.','')
        a = a.replace('-','')
        newFile.writelines(a)
    a = file.readline()
    
file.close()
newFile.close()

print("Pronto.")
