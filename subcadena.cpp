#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

// Estructura para almacenar el resultado
struct Resultado
{
    int posicion;    // Posición inicial de la subcadena
    int apariciones; // Número de apariciones consecutivas
};

// Función auxiliar para contar apariciones consecutivas en una subcadena
Resultado contarAparicionesConsecutivas(const string &cadena, int inicio, int fin, char C, int m)
{
    Resultado res = {inicio, 0};
    int maxConsecutivas = 0; //guardar la mayor cantidad de apariciones consecutivas del carácter C
    int posicionMax = inicio; 

    // Para cada posible posición inicial de una subcadena de longitud m
    for (int i = inicio; i <= fin - m + 1; i++)
    {
        int consecutivas = 0;
        int maxActual = 0;

        // Contar apariciones consecutivas en la subcadena actual
        for (int j = i; j < i + m; j++)
        {
            if (cadena[j] == C)
            {
                consecutivas++;
                maxActual = max(maxActual, consecutivas);
            }
            else
            {
                consecutivas = 0;
            }
        }

        // Actualizar máximo si es necesario
        if (maxActual > maxConsecutivas)
        {
            maxConsecutivas = maxActual;
            posicionMax = i;
        }
    }

    res.posicion = posicionMax;
    res.apariciones = maxConsecutivas;
    return res;
}

// Función principal de divide y vencerás
Resultado encontrarSubcadenaOptima(const string &cadena, int inicio, int fin, char C, int m)
{
    // Caso base: si la longitud es menor que m, no hay solución
    if (fin - inicio + 1 < m)
    {
        return {-1, 0};
    }

    // Comprobación de homogeneidad: si toda la subcadena es igual a C, se devuelve inmediatamente.
    bool homogenea = true;
    for (int i = inicio; i <= fin; i++) {
        if (cadena[i] != C) {
            homogenea = false;
            break;
        }
    }
    if (homogenea) {
        // Como la subcadena es homogénea, cualquier ventana de tamaño m tendrá m apariciones consecutivas.
        return {inicio, m};
    }


    // Si la longitud es igual a m, contar directamente
    if (fin - inicio + 1 == m)
    {
        return contarAparicionesConsecutivas(cadena, inicio, fin, C, m);
    }

    // SI NO Dividir en dos mitades
    int medio = inicio + (fin - inicio) / 2;

    // Resolver recursivamente cada mitad
    Resultado izquierda = encontrarSubcadenaOptima(cadena, inicio, medio, C, m);
    Resultado derecha = encontrarSubcadenaOptima(cadena, medio + 1, fin, C, m);

    // Buscar en el límite entre las dos mitades
    int inicioLimite = max(inicio, medio - m + 1); //usamos el max para que no pille fuera del array
    int finLimite = min(fin, medio + m - 1);  //usamos el min para que no pille fuera del array
    Resultado limite = contarAparicionesConsecutivas(cadena, inicioLimite, finLimite, C, m);

    // Combinar resultados buscando cual es el mayor
    if (izquierda.apariciones >= derecha.apariciones && izquierda.apariciones >= limite.apariciones)
    {
        return izquierda;
    }
    else if (derecha.apariciones >= izquierda.apariciones && derecha.apariciones >= limite.apariciones)
    {
        return derecha;
    }
    else
    {
        return limite;
    }
}

Resultado solucionDirecta(const string& cadena, char C, int m) {
    Resultado res = {0, 0};
    int maxConsecutivas = 0;
    int posicionMax = 0;
    
    // Explorar todas las posibles subcadenas de longitud m
    for (int i = 0; i <= cadena.length() - m; i++) {
        int consecutivas = 0;
        int maxActual = 0;
        
        // Contar apariciones consecutivas en la subcadena actual
        for (int j = i; j < i + m; j++) {
            if (cadena[j] == C) {
                consecutivas++;
                maxActual = max(maxActual, consecutivas);
            } else {
                consecutivas = 0;
            }
        }
        
        // Actualizar máximo si es necesario
        if (maxActual > maxConsecutivas) {
            maxConsecutivas = maxActual;
            posicionMax = i;
        }
    }
    
    res.posicion = posicionMax;
    res.apariciones = maxConsecutivas;
    return res;
}




int main()
{
    string cadena;
    int n, m;
    char C;

    // Leer entrada
    cout << "Introduce la longitud de la cadena (n): ";
    cin >> n;

    cout << "Introduce la longitud de la subcadena (m): ";
    cin >> m;

    cout << "Introduce el carácter a buscar (C): ";
    cin >> C;

    cout << "Introduce la cadena: ";
    cin >> cadena;

    // Medir tiempo de ejecución
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    // Resolver el problema
    Resultado resultado = encontrarSubcadenaOptima(cadena, 0, n - 1, C, m);

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec) * 1000 + (tf.tv_usec - ti.tv_usec) / 1000.0; //Se calcula la diferencia en segundos, y se mul por 1000 para pasar a milisegundos y tb Se calcula la diferencia en microsegundos y se divide por 1000 para pasar a milisegundos
    // Mostrar resultado
    cout << "\nResultado:" << endl;
    cout << "Posición inicial: " << resultado.posicion + 1 << endl;
    cout << "Apariciones consecutivas: " << resultado.apariciones << endl;
    cout << "Tiempo de ejecución: " << tiempo << " milisegundos" << endl;

    return 0;
}