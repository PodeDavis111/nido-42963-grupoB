# Pruebas

| ID | Requisito | Orden o secuencia | Resultado esperado | Resultado obtenido | OK |
|---|---|---|---|---|---|
| P01 | R1 | `registrar @kiwi` (dos veces) | La segunda vez: `E: No se pudo registrar @kiwi` |  |  |
| P02 | R1 | `registrar kiwi` (sin @) | `E: No se pudo registrar kiwi` |  |  |
| P03 | R2 |  |  |  |  |
| P04 | R3 | `seguir @a @a` | `E: Una cuenta no puede seguirse a si misma` |  |  |
| P05 | R4 |  |  |  |  |
| P06 | R5 |  |  |  |  |
| P07 | R6 | `guardar`, `salir`, abrir, `cargar`, `arbol` | El mismo preorden, la misma altura y los mismos seguimientos |  |  |
| P08 | R7 | `hola`, `seguir`, `perfil @nadie` | Mensajes de error; el programa sigue |  |  |

Agreguen todas las que necesiten. Incluyan casos con datos invalidos.
