# -*- coding: utf-8 -*-
import os
#Listamos todos los archivos en una carpeta
path = input("Ingrese ruta:\n>")
files = os.listdir(path)
print(files)
for file in files:
	file = open(path+"//"+file,"r") #Leemos el archivo
	new_file = open(file.name[:-4]+".csv","w")
	new_file.write("Numero a buscar, Tamaño n, Tiempo real, Encontrado\n")
	for row in range(0,20): #Son 20 columnas las de cada tabla
		file.readline() #Leemos la primera fila que es un salto de linea
		file.readline() #Leemos la segunda linea que son -----
		n = file.readline()[2:] #Leemos la n, nos saltamos el 'n='
		x = file.readline()[2:] #Leemos la x, nos saltamos el 'x='
		estaEn = file.readline().split(' ')[0] 
		file.readline()
		tiempo = file.readline().split(' ')[4]
		print(tiempo)
		#Escribimos una nueva linea en el archivo de salida
		new_file.write(x[:-1]+","+n[:-1]+","+tiempo+","+estaEn[:-1]+"\n")
	new_file.close()
	file.close()