#include <stdio.h>
 
int main() {
 
    int c1, n1, c2, n2;
    float vlr1, vlr2, vlrf;
    
    scanf("%d %d %f", &c1, &n1, &vlr1);
    scanf("%d %d %f", &c2, &n2, &vlr2);
    
    vlrf = ((n1 * vlr1) + (n2 * vlr2));
    
    printf("VALOR A PAGAR: R$ %.2f\n", vlrf);
 
    return 0;
}
