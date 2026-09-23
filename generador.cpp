#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

// Función para generar una cadena aleatoria de longitud n
string generarCadenaAleatoria(int n)
{
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    string cadena;
    cadena.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        cadena += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return cadena;
}

// Función para generar caso favorable (máximo número de apariciones consecutivas)
string generarCasoFavorable(int n, int m, char C)
{
    string cadena(n, C); // Cadena llena del carácter C
    return cadena;
}

// Función para generar caso desfavorable (mínimo número de apariciones consecutivas)
string generarCasoDesfavorable(int n, int m, char C)
{
    string cadena = generarCadenaAleatoria(n);
    // Aseguramos que no haya apariciones consecutivas del carácter C
    for (int i = 0; i < n; i++)
    {
        if (cadena[i] == C)
        {
            // Reemplazamos C por otro carácter aleatorio
            static const char alphanum[] = "abdefghijklmnopqrstuvwxyz";
            cadena[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }
    }
    return cadena;
}

// Función para generar caso promedio (distribución aleatoria)
string generarCasoPromedio(int n, int m, char C)
{
    return generarCadenaAleatoria(n);
}

int main()
{
    // Configuración de la semilla aleatoria
    srand(time(nullptr));

    // Parámetros de prueba
    int n = 100000000; // Tamaño máximo de la cadena
    int m = 100;       // Tamaño de la subcadena
    char C = 'c';      // Carácter a buscar

    // Generar casos de prueba
    for (int tam = 100; tam <= n; tam *= 10)
    {
        // Crear archivo para el caso favorable
        ofstream fout("casos/caso_favorable_" + to_string(tam) + ".txt");
        fout << tam << " " << m << " " << C << endl;
        fout << generarCasoFavorable(tam, m, C) << endl;
        fout.close();

        // Crear archivo para el caso desfavorable
        fout.open("casos/caso_desfavorable_" + to_string(tam) + ".txt");
        fout << tam << " " << m << " " << C << endl;
        fout << generarCasoDesfavorable(tam, m, C) << endl;
        fout.close();

        // Crear archivo para el caso promedio
        fout.open("casos/caso_promedio_" + to_string(tam) + ".txt");
        fout << tam << " " << m << " " << C << endl;
        fout << generarCasoPromedio(tam, m, C) << endl;
        fout.close();

        cout << "Generados casos de prueba para n = " << tam << endl;
    }

    return 0;
}