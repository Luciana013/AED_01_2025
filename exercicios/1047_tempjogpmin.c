#include <stdio.h>

int main() {
    int horaInicio, minutoInicio, horaFim, minutoFim;
    int duracaoHoras, duracaoMinutos;

    scanf("%d %d %d %d", &horaInicio, &minutoInicio, &horaFim, &minutoFim);

    duracaoHoras = horaFim - horaInicio;
    duracaoMinutos = minutoFim - minutoInicio;

    if (duracaoMinutos < 0) {
        duracaoMinutos += 60;
        duracaoHoras -= 1;
    }

    if (duracaoHoras < 0) {
        duracaoHoras += 24;
    }

    if (horaInicio == horaFim && minutoInicio == minutoFim) {
        duracaoHoras = 24;
        duracaoMinutos = 0;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracaoHoras, duracaoMinutos);

    return 0;
}
