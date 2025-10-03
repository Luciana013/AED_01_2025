#include <stdio.h>
 
int main() {
 
    int X;
    float Y, medio;
    
    scanf("%d %f", &X, &Y);
    
    medio = X / Y;
    
    printf("%.3f km/l\n", medio);
    
    return 0;
}
