#include <stdio.h>
 
int main() {
 
    char nome [20];
    double n1, n2, total;
    
    scanf("%s %lf %lf", nome, &n1, &n2);
    
    total = n1 + (n2 * 0.15);
    
    printf ("TOTAL = R$ %.2lf\n", total);
    
    return 0;
}
