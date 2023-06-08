#include <stdio.h>
#include "funciones.h"
#include <math.h>


int main (int argc, char *argv[]) {

    float puntos[4][3];
    char componente[3]={'X','Y','Z'};
    float areas[4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            puntos[i][j]=ingreseComponente(componente[j],i);
        }    
    }
    if (validarPiramide(puntos)==1)
    {
        float perimetro = calcularPerimetro(puntos);
        printf("El perimetro de la piramide es %f",perimetro);
        float areaSuperficial = calcularAreaSuperficial(puntos);
        printf("El area superficial de la piramide es %f",areaSuperficial);
        float volumen = calcularVolumen(puntos);
        printf("El area superficial de la piramide es %f",areaSuperficial);
    }else
    {
        printf("No es una piramide");
    }
    
    
    

    return 0;
}
