#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 3
#define Max_TRANS 50

// ===== ESTRUCTURA =====
typedef struct {
    char usuario[20];
    char clave[20];
    char nombre[50];
    char historial[Max_TRANS][50];
    float saldo;
    int numTransacciones;
} Usuario;

// ===== USUARIOS =====
Usuario usuarios[MAX_USUARIOS] = {
    {"juan01", "1234", "Juan Perez", {{0}}, 7000.0, 0},
    {"maria02", "abcd", "Maria Lopez", {{0}}, 3500.0, 0},
    {"carlos03", "pass", "Carlos Diaz", {{0}}, 100000.0, 0}
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


void mostrarMenu(Usuario *usuario) {
    int opcion;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Su saldo es: %.2f\n", usuario->saldo);
                break;
            case 2: {
                float monto;
                printf("Ingrese monto a depositar: ");
                scanf("%f", &monto);

                usuario->saldo += monto;

                sprintf(usuario->historial[usuario->numTransacciones],
                        "Deposito: +%.2f", monto);
                usuario->numTransacciones++;

                printf("Deposito exitoso.\n");
                break;
            }
            case 3: {
                float monto;
                printf("Ingrese monto a retirar: ");
                scanf("%f", &monto);
                if (monto > usuario->saldo) {
                    printf("Fondos insuficientes.\n");
                } else {
                    usuario->saldo -= monto;
                    sprintf(usuario->historial[usuario->numTransacciones],
                            "Retiro: -%.2f", monto);
                    usuario->numTransacciones++;
                    printf("Retiro exitoso.\n");
                }
                break;
            }
            case 4:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);
}

// ===== MAIN =====
int main() {
    Usuario *usuario = autenticar();

    if (usuario != NULL) {
        printf("Acceso permitido.\n");
        mostrarMenu(usuario);
    }

    return 0;
}