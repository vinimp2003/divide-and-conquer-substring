import matplotlib.pyplot as plt
import math

# Datos experimentales
tamanos = [100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
desfavorable = [0.001, 0.387, 4.452, 46.92, 483.699, 5185.18, 74369.4]
favorable    = [0.001, 0.004, 0.041, 0.403, 12.749, 113.238, 660.479]
promedio     = [0.001, 0.573, 9.415, 113.227, 991.054, 5652.41, 54495.9]

# Parámetros teóricos
# Supongamos que m=100 es constante, entonces:
# Caso favorable: T(m) = O(n)
# Casos desfavorable y promedio: T(M) y T(promedio) = O(n·m·log n)
A = 1.66e-7  # Factor para O(n) (T(m))
B = 4e-5     # Factor para O(n·m·log n) (T(M))
C = 3.5e-5   # Factor para O(n·m·log n) (T(promedio))

theory_favorable   = [A * n for n in tamanos]
theory_desfavorable = [B * n * math.log(n) for n in tamanos]
theory_promedio    = [C * n * math.log(n) for n in tamanos]

plt.figure(figsize=(9,7))

# Graficamos las curvas experimentales con etiquetas T(m), T(M) y T(promedio)
plt.loglog(tamanos, favorable, 's-', label=r'$T(m)$')
plt.loglog(tamanos, desfavorable, 'o-', label=r'$T(M)$')
plt.loglog(tamanos, promedio, '^-', label=r'$T(\mathrm{promedio})$')

# Graficamos las curvas teóricas en gris claro (líneas punteadas)
plt.loglog(tamanos, theory_favorable, '--', color='lightgray', label=r'$O(n)$')
plt.loglog(tamanos, theory_desfavorable, '--', color='lightgray', label=r'$O(n\cdot m\cdot \log n)$')

# Añadimos etiquetas de texto sobre las curvas teóricas para identificarlas
plt.text(tamanos[-2], theory_favorable[-2]*1.2, r'$O(n)$', fontsize=10, color='gray')
plt.text(tamanos[-2], theory_desfavorable[-2]*1.2, r'$O(n\cdot m\cdot \log n)$', fontsize=10, color='gray')

plt.xlabel('Tamaño (n)')
plt.ylabel('Tiempo (ms)')
plt.title('Comparación de tiempos experimentales y órdenes teóricos')
plt.legend()
plt.grid(True, which="both", ls="--")
plt.show()
