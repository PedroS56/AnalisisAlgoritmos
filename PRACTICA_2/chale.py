# -*- coding: utf-8 -*-
import os
#Listamos todos los archivos en una carpeta
#x = [0,5000,61396,152503,214826,322486,3128036,6337399,10393545,14700764,187645041,450057883,1295390003,1360839354,1493283650,1843349527,1980098116,2109248666,2147445644,214747085]
path = input("Ingrese ruta:\n>")
files = os.listdir(path)
#print(files)
for file in files:
	file = open(path+"//"+file,"r") #Leemos el archivo
	new_file = open(file.name[:-4]+".csv","w")
	new_file.write("Numero a buscar, Tamaño n, Tiempo real, Encontrado\n")
	for row in range(0,20): #Son 20 columnas las de cada tabla
		lin1 = file.readline() #Leemos la primera fila que es un salto de linea
		if lin1 == 'Encontrado\n':
			lin2 = file.readline()
			if lin2 == 'Encontrado\n':
				lin3 = file.readline()
				if lin3 == 'Encontrado\n':
					file.readline() #salto de linea
					n = file.readline()[2:]
					x = file.readline()[2:]
					estaEn = 'n'
					tiempo = file.readline().split(' ')[4]
			else:
				n = file.readline()[2:]
				x = file.readline()[2:]
				estaEn = 'n'
				tiempo = file.readline().split(' ')[4]	
		else:
			n = file.readline()[2:]
			x = file.readline()[2:]
			estaEn = 'n'
			tiempo = file.readline().split(' ')[4]
		file.readline()
		#print(tiempo)
		#Escribimos una nueva linea en el archivo de salida
		new_file.write(x+","+n+","+tiempo+","+estaEn+"\n")
	new_file.close()
	file.close()