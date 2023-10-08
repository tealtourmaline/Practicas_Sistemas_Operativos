#include <stdio.h>

int main(){
    double altura, radio, volumen;
    const double pi = 3.14159265358979323846;

    printf("altura: ");
    scanf("%lf", &altura);

    printf("radio: ");
    scanf("%lf", &radio);

    volumen = (pi * radio * radio * altura) / 3;

    printf("El volumen del cono es: %lf\n", volumen);

    return 0;
}