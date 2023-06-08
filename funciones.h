float ingreseComponente(char componente, int i); //Devuelve un valor flotante
float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2); //calcula la distancia entre dos puntos
float calcularPerimetro(float puntos[4][3]); //calcula el perimetro total de la piramide sumando las distancias entre los puntos
float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,float x3, float y3, float z3); //calcula el área de un triangulo utilizando las componente de los 3 puntos que lo conforman
float calcularAreaSuperficial(float puntos[4][3]); //calcula el área surficial de toda la piramide
float calcularVolumen(float puntos[4][3]); //calcula el volumen de la piramide
int validarPiramide(float puntos[4][3]); //valida si el cuarto punto describe una perpendicular con la base de la piramide