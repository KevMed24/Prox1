#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    FILE *archivo;

    archivo = fopen("clientes.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de clientes\n");
        return 1;
    }
    fclose(archivo);

    archivo = fopen("reservas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de reservas\n");
        return 1;
    }
    fclose(archivo);

    char clientes[5][2][40]={{"Juan","1789654123"},
                             {"",""},
                             {"",""},
                             {"",""},
                             {"",""}};

    char habitaciones[9][3][40]={{"1","simple","Dan-Carlton"},
                                  {"2","doble","Dan-Carlton"},
                                  {"3","triple","Dan-Carlton"},
                                  {"4","simple","Swissotel"},
                                  {"5","doble","Swissotel"},
                                  {"6","triple","Swissotel"},
                                  {"7","simple","Sheraton"},
                                  {"8","doble","Sheraton"},
                                  {"9","triple","Sheraton"}};

    double precios[9]={90,120,160,65,100,140,85,110,150};

    int reservas[10][4]={{-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0}};

    leerClientes(clientes, "clientes.txt");
    leerReservas(reservas, "reservas.txt");

    int opcion, numHabitacion, numReserva;
    do {   
        printf("Escoja una opcion:\n1.Buscar Habitacion\n2.Realizar reserva\n3.Ver reservas\n4.Pagar Reserva\n>>");
        scanf("%d", &opcion);
        switch (opcion) {
        case 1:
            printf("1.Por tamano\n2.Por Hotel\n>>");
            scanf("%d", &opcion);
            switch (opcion) {
            case 1:
                buscarPorTamano(&numHabitacion, habitaciones, precios);
                break;
            case 2:
                buscarHotel(&numHabitacion, habitaciones, precios);
                break;
            default:
                printf("Opcion no valida\n");
                break;
            }
            break;
        case 2:
            realizarReserva(numHabitacion, habitaciones, clientes, reservas);
            guardarClientes(clientes, "clientes.txt");
            guardarReservas(reservas, "reservas.txt");
            break;
        case 3:
            buscarReservaPorCedula(&numReserva, clientes, reservas);
            imprimirReserva(numReserva, reservas, habitaciones, precios);
            guardarReservas(reservas, "reservas.txt");
            break;
        case 4:
            buscarReservaPorCedula(&numReserva, clientes, reservas);
            pagarReserva(numReserva, reservas, habitaciones, precios);
            guardarReservas(reservas, "reservas.txt");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        printf("Desea elegir otra opcion (1.Si 2.No)\n>>");
        scanf("%d", &opcion);
    } while (opcion == 1);

    return 0;
}