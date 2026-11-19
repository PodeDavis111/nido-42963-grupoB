# Nido · comunidad `<nido-nombre-de-su-ave>`

![Nido CI](../../actions/workflows/nido.yml/badge.svg)

Red social de consola hecha en C++ con un **arbol binario de busqueda** (las cuentas, ordenadas
por @usuario), un **grafo dirigido** en matriz de adyacencia (quien sigue a quien), **recursion**
(recorridos del arbol y DFS para el alcance de un post) y persistencia en `nido.txt`.

Estructura de Datos · Evaluacion C2 · Unidad 4 · 2026-20 · NRC `<NRC>` · Grupo `<letra>`

## Equipo

| Integrante | Usuario de GitHub | Rol | Requisitos |
|---|---|---|---|
|  |  | Lider (scrum) |  |
|  |  | Dev · arbol | R1, R2 |
|  |  | Dev · grafo | R3, R4 |
|  |  | Dev · alcance y archivo | R5, R6 |
|  |  | QA y documentacion | R7, pruebas |

Tablero del equipo: `<enlace a GitHub Projects>` · Presentacion: `<enlace>`

## Como compilar y ejecutar

1. Abrir `nido.cpp` en Dev-C++ y compilar (F11). Si aparece un aviso, activar C++11 en
   Herramientas > Opciones del compilador.
2. Ejecutar y escribir `ayuda`.
3. Para guardar la salida de una secuencia: `nido.exe < pruebas\secuencia.txt > pruebas\salida.txt`

## Pruebas automaticas (GitHub Actions)

En cada push, GitHub compila el programa, ejecuta `pruebas/secuencia.txt` y revisa que cada linea
de `pruebas/esperado.txt` aparezca en la salida. El kit trae el ejemplo de la comunidad de prueba.
Cuando carguen su ficha, reemplacen:

- `pruebas/secuencia.txt` por la secuencia oficial de su ficha;
- `pruebas/esperado.txt` por las lineas de su traza a mano (arbol, alcance, llega, reporte).

Si la marca sale roja, abran la pestana **Actions** y vean que linea falta.

## Versiones

| Etiqueta | Entrega | Contenido |
|---|---|---|
| v0.1 | E1 | Equipo, repositorio, tablero y acuerdos |
| v0.5 | E2 | Diseno, traza a mano y los requisitos de la etapa 2 |
| v1.0 | E3 | R1 a R7, informe, pruebas, presentacion |
