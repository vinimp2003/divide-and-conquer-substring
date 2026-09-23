#!/bin/bash

# Archivo donde se almacenarán los resultados en formato CSV
resultados="resultados.csv"
echo "Tipo,Tamaño,Tiempo(ms)" > $resultados

# Recorrer cada archivo de la carpeta 'casos'
for archivo in casos/*.txt; do
    # Extraer la información del nombre del archivo, asumiendo el formato:
    # caso_tipo_n.txt (ejemplo: caso_favorable_100.txt)
    base=$(basename "$archivo" .txt)
    IFS='_' read -ra partes <<< "$base"
    tipo=${partes[1]}   # "favorable", "desfavorable" o "promedio"
    tam=${partes[2]}    # Ejemplo: "100", "1000", etc.

    # Ejecutar el programa con el archivo como entrada y capturar la salida
    salida=$(./subcadena < "$archivo")
    
    # Extraer el tiempo de ejecución
    # Se espera que la línea tenga el formato: "Tiempo de ejecución: X milisegundos"
    tiempo=$(echo "$salida" | grep "Tiempo de ejecución:" | awk '{print $4}')
    
    # Escribir el resultado en el archivo CSV
    echo "$tipo,$tam,$tiempo" >> $resultados
done

echo "Ejecución completada. Resultados guardados en $resultados"
