Las técnicas generales de diseño de algoritmos ofrecen un amplio y
variado conjunto de herramientas que se pueden usar en la resolución de
muchos tipos de problemas. La aplicación de una técnica concreta debe
entenderse como un proceso metódico, que empieza con la interpretación y el
modelado del problema desde la perspectiva de esa técnica, sigue con la
definición de las partes genéricas del esquema algorítmico (tipos de datos y
funciones básicas), y acaba con la implementación, prueba, refinamiento y
optimización del algoritmo. En esta práctica se aplicará la técnica divide y
vencerás a la resolución de problemas de recorrido de cadenas.

La memoria entregada deberá contener en la portada el profesor de
prácticas correspondiente, el nombre de los alumnos, grupo, subgrupo y e-mail.
Para el problema asignado al grupo, se deberán incluir los siguientes
apartados (hay que obtener al menos un tercio de la nota en cada
apartado):

1. (hasta 2 puntos) Diseño de una solución divide y vencerás, incluyendo
   pseudocódigo y explicación del algoritmo, justificando las decisiones de
   diseño, las estructuras de datos y las funciones básicas del esquema
   algorítmico.
2. (hasta 2 puntos) Análisis teórico del tiempo de ejecución, en los casos
   mejor y peor (tm y tM), y del orden de ejecución del algoritmo obtenido.
3. (hasta 2 puntos) Implementación: Programación del algoritmo (lo normal
   es hacer el programa tras haber diseñado y estudiado teóricamente el
   algoritmo). El código fuente debe ir documentado, con explicación de qué
   es cada variable, qué realiza cada función y su correspondencia con las
   funciones básicas del esquema algorítmico correspondiente.
4. (hasta 1,5 puntos) Diseño y aplicación de un proceso de validación del
   algoritmo dyv implementado utilizando el método de resolución directa. Hay
   que indicar claramente los experimentos concretos realizados para
   asegurarnos de que el programa funciona correctamente, y en su caso
   programas utilizados para la validación.
5. (hasta 1,5 puntos) Estudio experimental del tiempo de ejecución para
   distintos tamaños de problema. Habrá que experimentar con tamaños
   suficientemente grandes para obtener resultados significativos (102n106
   ).
   Será necesaria para ello la implementación de un generador de casos de
   prueba, que genere entradas para el programa para los casos más
   favorable, más desfavorable y promedio.
6. (hasta 1 punto) Contraste del estudio teórico y el experimental, buscando
   justificación a las posibles discrepancias entre los dos estudios.
7. Conclusiones y valoraciones personales de la actividad, con una estimación
   del tiempo que se ha tardado en completarla (en horas, por cada miembro).

Dada una cadena A de longitud n, un natural m  n y un carácter C, hay que
encontrar B, la subcadena de A de tamaño m con más apariciones
consecutivas del carácter C. Devolver el índice p de comienzo de la solución B
y el número de veces que aparece el C consecutivamente en B. En caso de
empate, será válida cualquiera de las soluciones óptimas.
Ejemplo: n=10, m=5, C=c
A= c d d a b c d a c c
Solución: B, posición de inicio igual a 6, y número de apariciones consecutivas
igual a 2.
