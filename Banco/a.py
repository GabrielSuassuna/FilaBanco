import os
for i in range(1, 201):
    os.system("./main  "+str(i))
    
    if (i < 10):
        os.system("diff saida-000" + str(i) + ".txt saida.txt")
    elif (i < 100):
        os.system("diff saida-00" + str(i) + ".txt saida.txt")
    else:
        os.system("diff saida-0" + str(i) + ".txt saida.txt")
    
    print("Terminou ", i)
