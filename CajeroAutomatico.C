#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 3

// ===== ESTRUCTURA =====
typedef struct {
    char usuario[20];
    char clave[20];
    char nombre[50];
} Usuario;

// ===== USUARIOS =====
Usuario usuarios[MAX_USUARIOS] = {
    {"juan01", "1234", "Juan Perez"},
    {"maria02", "abcd", "Maria Lopez"},
    {"carlos03", "pass", "Carlos Diaz"}
};

int totalUsuarios = 3;

// ===== FUNCION LOGIN =====
Usuario* autenticar() {
    char user[20];
    char pass[20];

    printf("\nIngrese usuario: ");
    scanf("%s", user);

    printf("Ingrese contrasena: ");
    scanf("%s", pass);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].usuario, user) == 0 &&
            strcmp(usuarios[i].clave, pass) == 0) {
            
            printf("Bienvenido %s\n", usuarios[i].nombre);
            return &usuarios[i];
        }
    }

    printf("Acceso denegado.\n");
    return NULL;
}

// ===== MAIN =====
int main() {
    Usuario *usuario = autenticar();

    if (usuario != NULL) {
        printf("Acceso permitido.\n");
    }

    return 0;
}