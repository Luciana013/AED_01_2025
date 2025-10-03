#include <stdio.h>
 
int main() {
 
    int a, b;
    float c, salary;
    
    scanf("%d %d %f", &a, &b, &c);
    
    salary = b * c;
    
    printf("NUMBER = %d\n", a);
    printf("SALARY = U$ %.2f\n", salary);
 
    return 0;
}
