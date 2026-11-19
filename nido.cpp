/* =============================================================
   Curso      : Estructura de Datos (24UC00428)
   Evaluacion : C2 - Unidad 4 - Semana 15
   Proyecto   : Nido, la red social del campus (kit base)
   Institucion: Universidad Continental
   Docente    : Carlos del Carpio
   Semestre   : 2026-20
   Compilador : Dev-C++ (MinGW / GCC, C++11 o superior)
   NRC        :
   Grupo      :
   Integrantes:
   ============================================================= */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const int MAX = 12;
const string ARCHIVO = "nido.txt";

struct NodoUsuario {
    string usuario;
    int    id;
    NodoUsuario *izq, *der;
};

int sigue[MAX][MAX];
NodoUsuario *porId[MAX];
int nUsuarios = 0;

// ===== FICHA =====
const string COMUNIDAD = "nido-de-prueba";
const int N_U = 8;
string fUsuario[N_U] = {"@mango", "@byte", "@pixel", "@andes", "@cuy", "@nova", "@zenit", "@lofi"};
const int N_S = 10;
string fSigue[N_S][2] = {{"@byte", "@mango"}, {"@pixel", "@mango"}, {"@mango", "@byte"}, {"@cuy", "@byte"},
                         {"@andes", "@cuy"}, {"@nova", "@pixel"}, {"@zenit", "@nova"}, {"@mango", "@pixel"},
                         {"@lofi", "@zenit"}, {"@zenit", "@lofi"}};
// =================

NodoUsuario* crearUsuario(string usuario, int id) {
    NodoUsuario *n = new NodoUsuario;
    n->usuario = usuario; n->id = id;
    n->izq = n->der = nullptr;
    return n;
}

bool esUsuarioValido(string u) {
    if (u.size() < 2 || u.size() > 16 || u[0] != '@') return false;
    for (int i = 1; i < (int)u.size(); i++)
        if (!((u[i] >= 'a' && u[i] <= 'z') || (u[i] >= '0' && u[i] <= '9'))) return false;
    return true;
}

void imprimirMarcados(string titulo, bool marca[]) {
    int k = 0;
    for (int x = 0; x < nUsuarios; x++) if (marca[x]) k++;
    cout << titulo << " (" << k << "):";
    if (k == 0) cout << " (nadie)";
    for (int x = 0; x < nUsuarios; x++) if (marca[x]) cout << " " << porId[x]->usuario;
    cout << endl;
}

/* ---------- Arbol binario de busqueda (todo recursivo) ---------- */

NodoUsuario* buscar(NodoUsuario *r, string u) {
    // TODO R1a
    return nullptr;
}

bool insertar(NodoUsuario *&r, NodoUsuario *nuevo) {
    // TODO R1b
    return false;
}

bool registrarUsuario(NodoUsuario *&raiz, string u) {
    // TODO R1c
    return false;
}

void enorden(NodoUsuario *r) {
    // TODO R2a
}

void preorden(NodoUsuario *r) {
    // TODO R2b
}

int contar(NodoUsuario *r) {
    // TODO R2c
    return 0;
}

int altura(NodoUsuario *r) {
    // TODO R2d
    return 0;
}

int hojas(NodoUsuario *r) {
    // TODO R2e
    return 0;
}

/* ---------- Grafo dirigido: matriz de adyacencia sigue ---------- */

int contarSiguiendo(int id) {
    int k = 0;
    for (int x = 0; x < nUsuarios; x++) if (sigue[id][x] == 1) k++;
    return k;
}

int contarSeguidores(int id) {
    // TODO R3a
    return 0;
}

void difundir(int v, bool visto[], bool imprimir) {
    // TODO R5a
}

/* ---------- Archivos y memoria ---------- */

void guardarPreorden(NodoUsuario *r, ofstream &f) {
    // TODO R6a
}

int liberar(NodoUsuario *r) {
    // TODO R7a
    return 0;
}

/* ---------- Ordenes ---------- */

void leerOrden(string linea, string &orden, string &a1, string &a2) {
    string t[6]; int n = 0;
    stringstream ss(linea);
    while (n < 6 && ss >> t[n]) n++;
    orden = a1 = a2 = "";
    if (n == 0) return;
    string c = t[0];
    if (c == "signup") c = "registrar";
    else if (c == "whois") c = "perfil";
    else if (c == "users") c = "usuarios";
    else if (c == "tree") c = "arbol";
    else if (c == "follow") c = "seguir";
    else if (c == "unfollow") c = "dejar";
    else if (c == "followers") c = "seguidores";
    else if (c == "following") c = "siguiendo";
    else if (c == "mutuals") c = "mutuos";
    else if (c == "trending") c = "popular";
    else if (c == "reach") c = "alcance";
    else if (c == "reaches") c = "llega";
    else if (c == "save") c = "guardar";
    else if (c == "load") c = "cargar";
    else if (c == "stats") c = "reporte";
    else if (c == "help" || c == "man") c = "ayuda";
    else if (c == "exit" || c == "quit") c = "salir";
    orden = c;
    if (n > 1) a1 = t[1];
    if (n > 2) a2 = t[2];
}

void ayuda() {
    cout << "  ORDEN                   EN INGLES            QUE HACE" << endl;
    cout << "  registrar @u            signup @u            crear una cuenta (ABB: insertar)" << endl;
    cout << "  perfil @u               whois @u             ver una cuenta (ABB: buscar)" << endl;
    cout << "  usuarios                users                cuentas en orden alfabetico (enorden)" << endl;
    cout << "  arbol                   tree                 preorden, nodos, altura y hojas" << endl;
    cout << "  seguir @a @b            follow @a @b         @a empieza a seguir a @b" << endl;
    cout << "  dejar @a @b             unfollow @a @b       @a deja de seguir a @b" << endl;
    cout << "  seguidores @u           followers @u         quienes siguen a @u" << endl;
    cout << "  siguiendo @u            following @u         a quienes sigue @u" << endl;
    cout << "  mutuos @u               mutuals @u           se siguen los dos" << endl;
    cout << "  popular                 trending             cuenta con mas seguidores" << endl;
    cout << "  alcance @u              reach @u             a quienes llega un post de @u (DFS)" << endl;
    cout << "  llega @a @b             reaches @a @b        un post de @a llega a @b?" << endl;
    cout << "  guardar / cargar        save / load          archivo nido.txt" << endl;
    cout << "  reporte                 stats                resumen de la comunidad" << endl;
    cout << "  salir                   exit                 terminar" << endl;
}

int main() {
    NodoUsuario *raiz = nullptr;
    for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) sigue[i][j] = 0;

    for (int i = 0; i < N_U; i++) registrarUsuario(raiz, fUsuario[i]);
    for (int i = 0; i < N_S; i++) {
        NodoUsuario *a = buscar(raiz, fSigue[i][0]);
        NodoUsuario *b = buscar(raiz, fSigue[i][1]);
        if (a != nullptr && b != nullptr) sigue[a->id][b->id] = 1;
    }

    cout << "Nido - comunidad " << COMUNIDAD << " (" << nUsuarios << " cuentas). Escribe ayuda." << endl;

    string linea;
    while (true) {
        cout << "nido@" << COMUNIDAD << ":~$ ";
        if (!getline(cin, linea)) break;
        string orden, a1, a2;
        leerOrden(linea, orden, a1, a2);
        if (orden == "") continue;
        cout << "> " << linea << endl;

        if (orden == "registrar") {
            // TODO R1d
        }
        else if (orden == "perfil") {
            NodoUsuario *u = buscar(raiz, a1);
            if (u == nullptr) cout << "E: No existe " << a1 << endl;
            else cout << u->usuario << " | id " << u->id << " | seguidores " << contarSeguidores(u->id)
                      << " | siguiendo " << contarSiguiendo(u->id) << endl;
        }
        else if (orden == "usuarios") {
            cout << "Usuarios (enorden):";
            enorden(raiz);
            cout << endl;
        }
        else if (orden == "arbol") {
            cout << "Preorden:";
            preorden(raiz);
            cout << endl;
            cout << "Nodos: " << contar(raiz) << " | altura: " << altura(raiz) << " | hojas: " << hojas(raiz) << endl;
        }
        else if (orden == "seguir") {
            // TODO R3b
        }
        else if (orden == "dejar") {
            // TODO R3c
        }
        else if (orden == "siguiendo") {
            NodoUsuario *u = buscar(raiz, a1);
            if (u == nullptr) cout << "E: No existe " << a1 << endl;
            else {
                bool marca[MAX] = {false};
                for (int x = 0; x < nUsuarios; x++) if (sigue[u->id][x] == 1) marca[x] = true;
                imprimirMarcados(u->usuario + " sigue a", marca);
            }
        }
        else if (orden == "seguidores") {
            // TODO R3d
        }
        else if (orden == "mutuos") {
            // TODO R4a
        }
        else if (orden == "popular") {
            // TODO R4b
        }
        else if (orden == "alcance") {
            // TODO R5b
        }
        else if (orden == "llega") {
            // TODO R5c
        }
        else if (orden == "guardar") {
            ofstream f(ARCHIVO);
            int m = 0;
            guardarPreorden(raiz, f);
            // TODO R6b
            f.close();
            cout << "Guardado: " << contar(raiz) << " cuentas y " << m << " seguimientos en " << ARCHIVO << endl;
        }
        else if (orden == "cargar") {
            ifstream f(ARCHIVO);
            if (!f) cout << "E: No existe " << ARCHIVO << endl;
            else {
                int m = 0;
                // TODO R6c
                cout << "Cargado: " << contar(raiz) << " cuentas y " << m << " seguimientos | altura "
                     << altura(raiz) << endl;
            }
        }
        else if (orden == "reporte") {
            // TODO R7b
        }
        else if (orden == "ayuda") ayuda();
        else if (orden == "salir") break;
        else cout << orden << ": orden no encontrada (escribe ayuda)" << endl;
    }

    int liberados = liberar(raiz);
    raiz = nullptr;
    cout << "Nodos liberados: " << liberados << ". Hasta pronto." << endl;
    return 0;
}
