#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 3
#define MAX_TRANS 50


// ===== ESTRUCTURA =====
typedef struct {
    char usuario[20];
    char clave[20];
    char nombre[50];
    float saldo;
    char historial[MAX_TRANS][50];
    int numTransacciones;
} Usuario;

// ===== USUARIOS =====
Usuario usuarios[MAX_USUARIOS] = {
    {"juan01", "1234", "Juan Perez",400000.0, {""}, 0},
    {"maria02", "abcd", "Maria Lopez", 70000.0, {""}, 0},
    {"carlos03", "pass", "Carlos Diaz", 25000.0, {""}, 0},
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
        printf("4. Ver historial de transacciones\n");
        printf("5. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Saldo: %.2f\n", usuario->saldo);
                break;

            case 2: {
                float monto;
    printf("Ingrese monto a depositar: ");
    scanf("%f", &monto);

    usuario->saldo += monto;

    sprintf(usuario->historial[usuario->numTransacciones],
            "Deposito: +%.2f", monto);
    usuario->numTransacciones++;   
    break;
            }

            case 3: {
                float monto;
    printf("Ingrese monto a retirar: ");
    scanf("%f", &monto);

    if (monto <= usuario->saldo) {
        usuario->saldo -= monto;

        sprintf(usuario->historial[usuario->numTransacciones],
                "Retiro: -%.2f", monto);
        usuario->numTransacciones++;
    } else {
        printf("Fondos insuficientes\n");
    }

    break;
            }
        


       case 4:
                printf("\n=== HISTORIAL DE TRANSACCIONES ===\n");

                if (usuario->numTransacciones == 0) {
                    printf("No hay transacciones.\n");
                } else {
                    for (int i = 0; i < usuario->numTransacciones; i++) {
                        printf("%d. %s\n", i + 1, usuario->historial[i]);
                    }
                }
                break;

            case 5:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 5);
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