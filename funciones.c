#include <stdio.h>
#include "funciones.h"
#include <math.h>


float ingreseComponente(char componente, int i) {
    float valor;
    printf("Ingrese el valor de la componente %c del cono %d: ", componente, i);
    scanf("%d", &valor);
    return valor;
}




float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float distancia;
    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    return distancia;
}




float calcularPerimetro(float puntos[4][3])
{
    float perimetro = 0.0;
    int i;

    for (i = 0; i < 3; i++)
    {
        perimetro += calcularDistancias(puntos[i][0], puntos[i][1], puntos[i][2], puntos[i + 1][0], puntos[i + 1][1], puntos[i + 1][2]);
    }
    perimetro += calcularDistancias(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]);

    return perimetro;
}


float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
    float area;
    float lado1, lado2, lado3, semiperimetro;

    lado1 = calcularDistancias(x1, y1, z1, x2, y2, z2);
    lado2 = calcularDistancias(x2, y2, z2, x3, y3, z3);
    lado3 = calcularDistancias(x3, y3, z3, x1, y1, z1);

    semiperimetro = (lado1 + lado2 + lado3) / 2.0;
    area = sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3));

    return area;
}



float calcularAreaSuperficial(float puntos[4][3])
{
    float areaSuperficial = 0.0;
    areaSuperficial += calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    areaSuperficial += calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    areaSuperficial += calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    areaSuperficial += calcularArea(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    return areaSuperficial;
}


float calcularVolumen(float puntos[4][3])
{
    float volumen = 0.0;
    float baseArea = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    float altura = calcularDistancias(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]);
    volumen = (baseArea * altura) / 3.0;
    return volumen;
}


int validarPiramide(float puntos[4][3])
{
    float baseArea = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    float altura = calcularDistancias(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]);
    float areaLateral = calcularArea(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]) +
                       calcularArea(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]) +
                       calcularArea(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
                       
    if (baseArea > 0.0 && altura > 0.0 && areaLateral > 0.0) {
        return 1; // Es una pirámide válida
    } else {
        return 0; // No es una pirámide válida
    }
}