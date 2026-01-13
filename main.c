#include "biblioteca.h"
int main() {
    struct Libro libros[MAX_LIBROS];
    int total = 0;
    int opcion;
    
    printf("\n Sistema de biblioteca\n");
    
    do {
        mostrarMenu();
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');
        
        switch(opcion) {
            case 1:
                registrarLibro(libros, &total);
                break;
            case 2:
                mostrarLibros(libros, total);
                break;
            case 3:
                buscarLibro(libros, total);
                break;
            case 4:
                actualizarEstado(libros, total);
                break;
            case 5:
                eliminarLibro(libros, &total);
                break;
            case 6:
                printf("\nHasta luego!\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }
    } while(opcion != 6);
    return 0;
}
