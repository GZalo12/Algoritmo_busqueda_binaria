//Algoritmo, busqueda binaria dentro de un arreglo, se puede utilizadar para arreglos grandes y ordenados
#include <stdio.h>
#define TAMANIO 15

//prototipo funciones
int busquedaBinaria( const int b[], int chalveDeBusqueda, int bajo, int alto);
void despliegaEncabezado(void);
void despliegaLinea(const int b[], int bajo, int medio, int alto);

int main()
{
    int a[TAMANIO]; //crea el arreglo
    int i;          //contador para inicializar los elementos de 0 a 14 del arreglo
    int llave;      //valor a localizar en el arreglo a
    int resultado;  //variable para almacenar la ubicacion de la llave  o -1

    //crea los datos, realiza las multiplicaciones de las cifras del 0 al 14 ejemplo
    //2*1=2, 2*2=4, 2*3=6, 2*4=8, y asi secesivamente hasta realizar todas las evaluaciones
    for ( i=0; i < TAMANIO; i++)
    {
        a[i]= 2 * i;
    }

    printf("Introduzca un numero entre 0 y 28: ");
    scanf("%d", &llave);

    despliegaEncabezado();  //mandamos a llamar a la funcion

    //busca la llave en el arreglo
    resultado= busquedaBinaria(a, llave, 0, TAMANIO - 1);

    //despliega los resultados
    if ( resultado != -1)
    {
        printf("\n %d se encuentra en el elemento %d del arreglo \n", llave, resultado);
    }
    else
    {
        printf("\n %d no se encuentra  \n", llave);
    }
    return 0;
}

//funcion para realizar la busqueda binaria en un arreglo
int busquedaBinaria(const int b[], int claveDeBusqueda, int bajo, int alto)
{
    int central;    //variable para mantener el elemento central del arreglo

    //realiza el ciclo hasta que el subindice bajo es mayor que el subindice alto
    while( bajo <= alto)
    {
        //determina el elemento central del subarreglo en el que se busca
        central = (bajo + alto ) / 2;

        //despliega el subarreglo utilizado en este ciclo, funcion declrada en un inicio
        despliegaLinea(b, bajo, central, alto);

        //si clave de busqueda coincide con el elemento central, devuelve central
        if( claveDeBusqueda == b[central])
        {
            return central;
        }
        //si clave de busqueda es menor que el elemento central, establece el nuevo valor de alto
        else if( claveDeBusqueda < b[central])
        {
            alto = central - 1; //busca en la mitad inferior del arreglo
        }
        //si clavedeBusqueda es mayor que el elemento central, establece el nuevo valor por bajo
        else
        {
            bajo = central + 1; //busca en la mitad superiror del arreglo
        }
    }
    return -1;  //nose encontro clavedeBusqueda
}

//imprime un encabezado para la salida
void despliegaEncabezado(void)
{
    int i;  //contador

    printf("\n subindices: \n");

    //muestra el encabezado de la columna, muestras todos los valores que son evaluados
    //osea del 0 al 14
    for ( i=0; i < TAMANIO; i++)
    {
        printf("%3d", i);
    }

    printf("\n");   //comienza la nueva linea de salida
    //inicializamos el contador en 1, lo que significa que realizara el ciclo de 1 a 15,
    //y la operacion sera de 15 * 4=60 y imprimira un guion 60 veces hasta que se cumpla el ciclo
    for(i =1; i <= 4 * TAMANIO; i++)
    {
        printf("-");
    }

    printf("\n");
}

//imprime una linea de salida que muestra la parte actual del arreglo que se esta procesando
void despliegaLinea(const int b[], int baj, int cen, int alt)
{
    int i;      //contador para la iteracion a travez del arreglo b

    //ciclo atravez del arreglo completo
    for (i = 0; i < TAMANIO; i++)
    {
        //despliega espacios si se encuentra fuera del rango actual del subarreglo
        if( i < baj || i > alt)
        {
            printf("    ");
        }
        else if( i == cen)  //despliega el elemento central
        {
            printf("%3d*", b[i]);   //marca el valor central
        }
        else    //despliga otros elementos en el subarreglo
        {
            printf("%3d ", b[i]);
        }

    }

    printf("\n");
}
