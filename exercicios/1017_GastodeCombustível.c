#include <stdio.h>
 
int main() {
 
    int horas, vel;
    float litros;
    
    scanf("%d %d", &horas, &vel);
    
    litros = (horas * vel) / 12.0;
    
    printf("%.3f\n", litros);
 
    return 0;
}
