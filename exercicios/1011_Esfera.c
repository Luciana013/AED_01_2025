#include <stdio.h>

#define PI 3.14159
 
int main() {
 
    double r, esfera;
    
    scanf("%lf", &r);
    
    esfera = (4/3.0) * PI * pow(r,3);
    
    printf("VOLUME = %.3lf\n", esfera);
 
    return 0;
}
