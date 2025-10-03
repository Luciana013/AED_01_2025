#include <stdio.h>
 
int main() {
 
    int a, b, c, maior, maiorf;
    
    scanf("%d %d %d", &a, &b, &c);
    
    maior = (a+b+abs(a-b))/2;
    
    maiorf = (maior+c+abs(maior-c))/2;
    
    printf("%d eh o maior\n", maiorf);
    
    return 0;
}
