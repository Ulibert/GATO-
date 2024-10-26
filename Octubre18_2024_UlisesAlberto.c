#include <stdio.h>

void imprimirTablero(char tablero[3][3]) {
    printf(" %c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);
}
char verificarGanador(char tablero[3][3]) {

for (int i = 0; i < 3; i++) {
if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
return tablero[i][0];
        }
    }

for (int i = 0; i < 3; i++) {
if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
return tablero[0][i];
        }
    }

if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }
if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
    return tablero[0][2];
    }


    return ' ';
}


int tableroLleno(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int turnoJugador = 1;
    int eleccion;
    char marca;
    char ganador = ' ';


    while (ganador == ' ' && !tableroLleno(tablero)) {

        imprimirTablero(tablero);


        if (turnoJugador == 1) {
            marca = 'X';
        } else {
            marca = 'O';
        }

        printf("Jugador %d, elige una posición (1-9): ", turnoJugador);
        scanf("%d", &eleccion);

        if (eleccion >= 1 && eleccion <= 9) {
            int fila = (eleccion - 1) / 3;
            int columna = (eleccion - 1) % 3;


            if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
                tablero[fila][columna] = marca;
            } else {
                printf("¡Esa posición ya está ocupada! Intenta de nuevo.\n");
                continue;
            }

            ganador = verificarGanador(tablero);


            turnoJugador = (turnoJugador == 1) ? 2 : 1;
        } else {
            printf("Elección no válida. Por favor, elige un número entre 1 y 9.\n");
        }
    }

    imprimirTablero(tablero);

    if (ganador != ' ') {
        printf("¡Felicidades! El jugador %c ha ganado.\n", ganador);
    } else {
        printf("¡Es un empate!\n");
    }

    return 0;
}
