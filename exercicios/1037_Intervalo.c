#include <stdio.h>

int main() {
    double value;
    scanf("%lf", &value);

    if (value >= 0.0 && value <= 25.0) {
        printf("Intervalo [0,25]\n");
    } else if (value > 25.0 && value <= 50.0) {
        printf("Intervalo (25,50]\n");
    } else if (value > 50.0 && value <= 75.0) {
        printf("Intervalo (50,75]\n");
    } else if (value > 75.0 && value <= 100.0) {
        printf("Intervalo (75,100]\n");
    } else {
        printf("Fora de intervalo\n");
    }

    return 0;
}
