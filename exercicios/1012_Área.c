#include <stdio.h>

#define PI 3.14159
 
int main() {
 
    double A, B, C, tri, cir, tra, qua, re;
    
    scanf("%lf %lf %lf", &A, &B, &C);
    
    tri = (A*C)/2;
    
    cir = C * C * PI;
    
    tra = ((A + B)*C)/2;
    
    qua = B * B;
    
    re = A * B;
    
    printf("TRIANGULO: %.3lf\n", tri);
    printf("CIRCULO: %.3lf\n", cir);
    printf("TRAPEZIO: %.3lf\n", tra);
    printf("QUADRADO: %.3lf\n", qua);
    printf("RETANGULO: %.3lf\n", re);
    
    return 0;
}
