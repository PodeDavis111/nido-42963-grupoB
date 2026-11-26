# Pruebas

Comunidad: nido-lechuza (10 cuentas iniciales, 16 seguimientos). Cada prueba se ejecuta en una sesion nueva del programa, desde la ficha original, con las ordenes de la columna *Orden o secuencia* (separadas por `;`). Resultados obtenidos con la version actual de `nido.cpp`. El post de `alcance` y `llega` se propaga hacia los seguidores (si @a sigue a @b, un post de @b llega a @a).

| ID | Req. | Orden o secuencia | Resultado esperado | Resultado obtenido | OK |
|----|------|-------------------|--------------------|--------------------|----|
| P01 | R1 | `registrar @kiwi ; registrar @kiwi` | 1ra: `Registrado: @kiwi (id 10)`<br>2da: `E: No se pudo registrar @kiwi` | `registrar @kiwi` → Registrado: @kiwi (id 10)<br>`registrar @kiwi` → E: No se pudo registrar @kiwi | ✅ |
| P02 | R1 | `registrar kiwi` | `E: No se pudo registrar kiwi` | E: No se pudo registrar kiwi | ✅ |
| P03 | R1 | `registrar` | `Uso: registrar @usuario` | Uso: registrar @usuario | ✅ |
| P04 | R1 | `registrar @Kiwi` | `E: No se pudo registrar @Kiwi` (mayuscula no valida) | E: No se pudo registrar @Kiwi | ✅ |
| P05 | R1 | `registrar @ab12` | `Registrado: @ab12 (id 10)` (letras y digitos validos) | Registrado: @ab12 (id 10) | ✅ |
| P06 | R1 | `registrar @a1 ; registrar @a2 ; registrar @a3` | `@a1` (id 10) y `@a2` (id 11) registrados; `@a3`: `E: No se pudo registrar @a3` (MAX = 12) | `registrar @a1` → Registrado: @a1 (id 10)<br>`registrar @a2` → Registrado: @a2 (id 11)<br>`registrar @a3` → E: No se pudo registrar @a3 | ✅ |
| P07 | R1 | `perfil @hielo` | `@hielo \| id 9 \| seguidores 2 \| siguiendo 2` | @hielo \| id 9 \| seguidores 2 \| siguiendo 2 | ✅ |
| P08 | R1 | `perfil @nadie` | `E: No existe @nadie` | E: No existe @nadie | ✅ |
| P09 | R2 | `arbol` | `Preorden: @lago @gif @bambu @indie @hielo @vapor @rock @nachos @salsa @trueno`<br>`Nodos: 10 \| altura: 5 \| hojas: 4` | Preorden: @lago @gif @bambu @indie @hielo @vapor @rock @nachos @salsa @trueno / Nodos: 10 \| altura: 5 \| hojas: 4 | ✅ |
| P10 | R2 | `usuarios` | `Usuarios (enorden): @bambu @gif @hielo @indie @lago @nachos @rock @salsa @trueno @vapor` | Usuarios (enorden): @bambu @gif @hielo @indie @lago @nachos @rock @salsa @trueno @vapor | ✅ |
| P11 | R2 | `registrar @wifi ; arbol` | `Registrado: @wifi (id 10)`<br>Preorden con @wifi al final; `Nodos: 11 \| altura: 5 \| hojas: 5` | `registrar @wifi` → Registrado: @wifi (id 10)<br>`arbol` → Preorden: @lago @gif @bambu @indie @hielo @vapor @rock @nachos @salsa @trueno @wifi / Nodos: 11 \| altura: 5 \| hojas: 5 | ✅ |
| P12 | R3 | `seguir @lago @lago` | `E: Una cuenta no puede seguirse a si misma` | E: no puedes seguirte a ti mismo | ❌ |
| P13 | R3 | `seguir` | `Uso: seguir @a @b` | Uso: seguir @a @b | ✅ |
| P14 | R3 | `seguir @lago @zzz` | `E: no existe @zzz` | E: no existe @zzz | ✅ |
| P15 | R3 | `seguir @zzz @lago` | `E: no existe @zzz` | E: no existe @zzz | ✅ |
| P16 | R3 | `seguir @lago @vapor` | `E: @lago ya sigue a @vapor` | E: @lago ya sigue a @vapor | ✅ |
| P17 | R3 | `seguir @gif @lago` | `@gif sigue ahora a @lago` | E: @gif ya sigue a @lago | ❌ |
| P18 | R3 | `seguir @gif @lago ; seguidores @lago` | `@gif sigue ahora a @lago`<br>`Seguidores de @lago (2): @gif @rock` | `seguir @gif @lago` → E: @gif ya sigue a @lago<br>`seguidores @lago` → Seguidores de @lago (2): @gif @rock | ❌ |
| P19 | R3 | `dejar @gif @lago` | `E: @gif no sigue a @lago` | E: @gif no sigue a @lago | ✅ |
| P20 | R3 | `dejar @vapor @trueno` | `@vapor dejo de seguir a @trueno` | @vapor dejo de seguir a @trueno | ✅ |
| P21 | R3 | `dejar` | `Uso: dejar @a @b` | Uso: dejar @a @b | ✅ |
| P22 | R3 | `siguiendo @hielo` | `@hielo sigue a (2): @nachos @bambu` | @hielo sigue a (2): @nachos @bambu | ✅ |
| P23 | R3 | `seguidores @gif` | `Seguidores de @gif (0): (nadie)` | Seguidores de @gif (0): (nadie) | ✅ |
| P24 | R3 | `seguidores @nachos` | `Seguidores de @nachos (4): @vapor @indie @bambu @hielo` | Seguidores de @nachos (4): @vapor @indie @bambu @hielo | ✅ |
| P25 | R4 | `mutuos @bambu` | `mutuos de @bambu (2): @trueno @hielo` | mutuos de @bambu (2): @trueno @hielo | ✅ |
| P26 | R4 | `mutuos @lago` | `mutuos de @lago (0): (nadie)` | mutuos de @lago (0): (nadie) | ✅ |
| P27 | R4 | `mutuos @zzz` | `E: no existe @zzz` | E: no existe @zzz | ✅ |
| P28 | R4 | `popular` | `Mas popular: @nachos \| seguidores: 4` | Mas popular: @nachos \| seguidores: 4 | ✅ |
| P29 | R5 | `alcance @lago` | `Alcance de @lago: @rock @salsa @trueno @vapor @bambu @hielo @gif \| alcanzados: 7` (el post llega a los seguidores, no llega a @indie ni @nachos) | Alcance de  @lago: @rock @salsa @trueno @vapor @bambu @hielo @gif \| alcanzados: 7 | ✅ |
| P30 | R5 | `alcance @gif` | `(nadie)` y `alcanzados: 0` (nadie sigue a @gif) | Alcance de  @gif:(nadie) \| alcanzados: 0 | ✅ |
| P31 | R5 | `alcance @nachos` | Llega a 9 cuentas (todas menos @nachos): `alcanzados: 9` | Alcance de  @nachos: @vapor @lago @rock @salsa @trueno @bambu @hielo @gif @indie \| alcanzados: 9 | ✅ |
| P32 | R5 | `alcance @zzz` | `E: No existe @zzz` | E: No existe @zzz | ✅ |
| P33 | R5 | `llega @lago @trueno` | `Un post de @lago llega a @trueno: si` | Un post de @lagollega a @trueno: si | ❌ |
| P34 | R5 | `llega @vapor @nachos` | `Un post de @vapor llega a @nachos: no` | Un post de @vaporllega a @nachos: no | ❌ |
| P35 | R5 | `llega @nachos @vapor` | `Un post de @nachos llega a @vapor: si` | Un post de @nachosllega a @vapor: si | ❌ |
| P36 | R5 | `llega @lago @lago` | `E: Elijan dos cuentas distintas` | E: Elijan dos cuentas distintas | ✅ |
| P37 | R5 | `llega @zzz @lago` | `E: No existe @zzz` | E: No existe @zzz | ✅ |
| P38 | R5 | `llega` | `Uso: llega @a @b` | E: No existe  | ❌ |
| P39 | R6 | `cargar` | Sin `nido.txt`: `E: No existe nido.txt` | E: No existe nido.txt | ✅ |
| P40 | R6 | `guardar` | `Guardado: 10 cuentas y 16 seguimientos en nido.txt` | Guardado: 10 cuentas y 0 seguimientos en nido.txt | ❌ |
| P41 | R6 | `guardar ; cargar ; arbol` | `Cargado: 10 cuentas y 16 seguimientos \| altura 5` y el mismo preorden | `guardar` → Guardado: 10 cuentas y 0 seguimientos en nido.txt<br>`cargar` → Cargado: 10 cuentas y 0 seguimientos \| altura 5<br>`arbol` → Preorden: @lago @gif @bambu @indie @hielo @vapor @rock @nachos @salsa @trueno / Nodos: 10 \| altura: 5 \| hojas: 4 | ❌ |
| P42 | R7 | `hola ; seguir ; perfil @nadie` | `hola: orden no encontrada (escribe ayuda)`, `Uso: seguir @a @b`, `E: No existe @nadie`; el programa sigue | `hola` → hola: orden no encontrada (escribe ayuda)<br>`seguir` → Uso: seguir @a @b<br>`perfil @nadie` → E: No existe @nadie | ✅ |
| P43 | R7 | `reporte` | `Cuentas: 10 \| seguimientos: 16`, `Arbol: altura 5 \| hojas 4`, `Mas popular: @nachos \| seguidores: 4` | Reporte de la comunidad nido-lechuza / Cuentas: 10 \| seguimientos: 16 / Arbol: altura 5 \| hojas 4 / Mas popular: @nachos \| seguidores: 4 / Sin seguidores (1): @gif / No siguen a nadie (1): @nachos | ✅ |
| P44 | R7 | (Enter vacio) | Linea vacia: no imprime nada y el programa sigue | (sin salida; el programa sigue) | ✅ |
| P45 | R7 | `help` | Muestra la tabla de ordenes (igual que `ayuda`) |   ORDEN                   EN INGLES            QUE HACE /   registrar @u            signup @u            crear una cuenta (ABB: insertar) /   perfil @u               whois @u             ver una cuenta (ABB: buscar) /   usuarios                users                cuentas en orden alfabetico (enorden) /   arbol                   tree                 preorden, nodos, altura y hojas /   seguir @a @b            follow @a @b         @a empieza a seguir a @b /   dejar @a @b             unfollow @a @b       @a deja de seguir a @b /   seguidores @u           followers @u         quienes siguen a @u /   siguiendo @u            following @u         a quienes sigue @u /   mutuos @u               mutuals @u           se siguen los dos /   popular                 trending             cuenta con mas seguidores /   alcance @u              reach @u             a quienes llega un post de @u (DFS) /   llega @a @b             reaches @a @b        un post de @a llega a @b? /   guardar / cargar        save / load          archivo nido.txt /   reporte                 stats                resumen de la comunidad /   salir                   exit                 terminar | ✅ |
| P46 | R7 | `registrar @wifi ; registrar @wifi ; registrar @wifi` | 1ra: `Registrado: @wifi (id 10)`; 2da y 3ra: `E: No se pudo registrar @wifi` | `registrar @wifi` → Registrado: @wifi (id 10)<br>`registrar @wifi` → E: No se pudo registrar @wifi<br>`registrar @wifi` → E: No se pudo registrar @wifi | ✅ |
| P47 | R7 | `registrar @wifi ; seguir @wifi @trueno ; seguir @hielo @wifi ; seguir @hielo @wifi` | `@wifi sigue ahora a @trueno`, `@hielo sigue ahora a @wifi`, y la 3ra: `E: @hielo ya sigue a @wifi` | `registrar @wifi` → Registrado: @wifi (id 10)<br>`seguir @wifi @trueno` → E: @wifi ya sigue a @trueno<br>`seguir @hielo @wifi` → E: @hielo ya sigue a @wifi<br>`seguir @hielo @wifi` → E: @hielo ya sigue a @wifi | ❌ |
| P48 | R7 | `dejar @vapor @trueno ; alcance @lago` | `@vapor dejo de seguir a @trueno`<br>`alcanzados: 6` (@vapor ya no recibe el post de @lago) | `dejar @vapor @trueno` → @vapor dejo de seguir a @trueno<br>`alcance @lago` → Alcance de  @lago: @rock @salsa @trueno @bambu @hielo @gif \| alcanzados: 6 | ✅ |
| P49 | R7 | `registrar @wifi ; seguir @wifi @trueno ; seguir @hielo @wifi ; dejar @vapor @trueno ; guardar ; cargar ; arbol` | `Guardado: 11 cuentas y 17 seguimientos en nido.txt`<br>`Cargado: 11 cuentas y 17 seguimientos \| altura 5` | `registrar @wifi` → Registrado: @wifi (id 10)<br>`seguir @wifi @trueno` → E: @wifi ya sigue a @trueno<br>`seguir @hielo @wifi` → E: @hielo ya sigue a @wifi<br>`dejar @vapor @trueno` → @vapor dejo de seguir a @trueno<br>`guardar` → Guardado: 11 cuentas y 0 seguimientos en nido.txt<br>`cargar` → Cargado: 11 cuentas y 0 seguimientos \| altura 5<br>`arbol` → Preorden: @lago @gif @bambu @indie @hielo @vapor @rock @nachos @salsa @trueno @wifi / Nodos: 11 \| altura: 5 \| hojas: 5 | ❌ |
| P50 | R7 | `salir` | `Nodos liberados: 10. Hasta pronto.` | Nodos liberados: 10. Hasta pronto. | ✅ |


