#include<stdio.h>

int second()
{
    
    float x0 = 1.47;
    float x1 = 0.14;
    float xn;
    int Sum = 0;
        printf(" 0 %f\n", x0);
    for ( int n = 1; n <= 10; n++) {

        {
        
        xn = 0.8 * x1 + 0.2 * x0;
        x0 = x1;
        x1 = xn;
        printf(" %d %f\n", n, x0);
        if ( (x1 - x0) >= 0){
            Sum = Sum + 2;
        }
        else if ((x1 - x0) < 0) {
            Sum = Sum - 2;
        }
        
        }
    
    }
    if (Sum == 20){
        printf("dx/dn is always positive or zero");
    }
    
    else if (Sum == -20){
        printf("dx/dn is always negative");
    }
    
    else if (Sum < 20){
        printf("The sign of dx/dn varies");
    }
    
    return 0;

}
