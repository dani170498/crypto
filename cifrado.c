#include <stdio.h>
#include <ctype.h>

int generar_clave(int indice) {
    if (indice == 0) return 0;  // Valor inicial
    if (indice == 1) return 1;  // Segundo valor en la serie de Fibonacci

    // Generar la serie de Fibonacci
    int a = 0, b = 1, temp;
    for (int i = 2; i <= indice; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;  // Devolver el valor correspondiente en la serie de Fibonacci
}

void cifrar_cesar_avanzado(char mensaje[], int (*generar_clave)(int)) {
    for (int i = 0; mensaje[i] != '\0'; ++i) {
        if (isalpha(mensaje[i])) {
            char base = isupper(mensaje[i]) ? 'A' : 'a';
            int ascii_offset = base;
            int clave_actual = generar_clave(i);
            mensaje[i] = (mensaje[i] - ascii_offset + clave_actual) % 26 + ascii_offset;
        }
    }
}

int main() {
    char mensaje[1000];

    // Entrada del usuario
    printf("Ingrese el mensaje a cifrar: ");
    fgets(mensaje, sizeof(mensaje), stdin);

    // Cifrado utilizando la serie de Fibonacci para la clave
    cifrar_cesar_avanzado(mensaje, generar_clave);

    // Mostrar resultado
    printf("\nMensaje cifrado: %s\n", mensaje);

    return 0;
}

