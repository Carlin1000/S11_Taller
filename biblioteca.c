#include "biblioteca.h"
void mostrarMenu() {
    printf("\n   Menu de Biblioteca   \n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
}

int validarTexto(char texto[]) {
    for (int i = 0; texto[i] != 0; i++) {
        if (texto[i] >= '0' && texto[i] <= '9') {
            return 0;
        }
    }
    return 1;
}

void registrarLibro(struct Libro libros[], int *total) {
    if (*total >= MAX_LIBROS) {
        printf("\nBiblioteca llena.\n");
        return;
    }
    
    struct Libro libro;

    printf("\n  Registrar libro  \n");

    do {
        printf("ID: ");
        scanf("%d", &libro.id);
        while(getchar() != '\n');
        
        if (libro.id <= 0) {
            printf("El ID debe ser positivo.\n");
        } else if (validarID(libros, *total, libro.id)) {
            printf("El ID ingresado ya existe.\n");
        } else {
            break;
        }
    } while(1);
    
    printf("Titulo: ");
    fgets(libro.titulo, MAX_TITULO, stdin);
    libro.titulo[strcspn(libro.titulo, "\n")] = 0;
    
    do {
        printf("Autor: ");
        fgets(libro.autor.nombre, MAX_NOMBRE, stdin);
        libro.autor.nombre[strcspn(libro.autor.nombre, "\n")] = 0;
        
        if (!validarTexto(libro.autor.nombre)) {
            printf("El autor no debe contener numeros.\n");
        } else {
            break;
        }
    } while(1);
    
    do {
        printf("Nacionalidad: ");
        fgets(libro.autor.nacionalidad, MAX_NACIONALIDAD, stdin);
        libro.autor.nacionalidad[strcspn(libro.autor.nacionalidad, "\n")] = 0;
        
        if (!validarTexto(libro.autor.nacionalidad)) {
            printf("La nacionalidad no debe contener numeros.\n");
        } else {
            break;
        }
    } while(1);
    
    do {
        printf("Año de publicacion: ");
        if (scanf("%d", &libro.publicacion.fecha) != 1) {
            printf("Ingrese solo numeros.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');
        
        if (libro.publicacion.fecha < 1000 || libro.publicacion.fecha > 2026) {
            printf("Fecha invalida (1000-2026).\n");
        } else {
            break;
        }
    } while(1);
    
    do {
        printf("Cantidad ejemplares: ");
        if (scanf("%d", &libro.publicacion.cantidadEjemplares) != 1) {
            printf("Ingrese solo numeros.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');
        
        if (libro.publicacion.cantidadEjemplares <= 0) {
            printf("La cantidad debe ser mayor a 0.\n");
        } else {
            break;
        }
    } while(1);
    
    char disponible[] = "Disponible";
    for (int i = 0; disponible[i] != '\0'; i++) {
        libro.estado[i] = disponible[i];
    }
    libro.estado[10] = '\0';
    
    libros[*total] = libro;
    (*total)++;
    
    printf("\nLibro registrado\n");
}

void mostrarLibros(struct Libro libros[], int total) {
    if (total == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }
    printf("\n       Lista de Libros     \n");
    
    for (int i = 0; i < total; i++) {
        printf("\n[Libro %d]\n", i + 1);
        printf("  ID: %d\n", libros[i].id);
        printf("  Titulo: %s\n", libros[i].titulo);
        printf("  Autor: %s\n", libros[i].autor.nombre);
        printf("  Nacionalidad: %s\n", libros[i].autor.nacionalidad);
        printf("  Fecha: %d\n", libros[i].publicacion.fecha);
        printf("  Cantidad: %d ejemplares\n", libros[i].publicacion.cantidadEjemplares);
        printf("  Estado: %s\n", libros[i].estado);
    }
    printf("\n\nTotal de libros: %d\n", total);
}

void buscarLibro(struct Libro libros[], int total) {
    if (total == 0) {
        printf("\nNo hay libros.\n");
        return;
    }
    
    int opcion;
    printf("\n1. Buscar por ID\n2. Buscar por titulo\nOpcion: ");
    scanf("%d", &opcion);
    while(getchar() != '\n');
    
    int encontrado = 0;
    
    if (opcion == 1) {
        int id;
        printf("ID: ");
        scanf("%d", &id);
        while(getchar() != '\n');
        
        for (int i = 0; i < total; i++) {
            if (libros[i].id == id) {
                printf("\n    Libro encontrado   \n");
                printf("ID: %d\n", libros[i].id);
                printf("Titulo: %s\n", libros[i].titulo);
                printf("Autor: %s\n", libros[i].autor.nombre);
                printf("Nacionalidad: %s\n", libros[i].autor.nacionalidad);
                printf("Fecha: %d\n", libros[i].publicacion.fecha);
                printf("Cantidad: %d\n", libros[i].publicacion.cantidadEjemplares);
                printf("Estado: %s\n", libros[i].estado);
                encontrado = 1;
                break;
            }
        }
    } else if (opcion == 2) {
        char titulo[MAX_TITULO];
        printf("Titulo: ");
        fgets(titulo, MAX_TITULO, stdin);
        titulo[strcspn(titulo, "\n")] = 0;
        
        for (int i = 0; i < total; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("\n    Libro encontrado   \n");
                printf("ID: %d\n", libros[i].id);
                printf("Titulo: %s\n", libros[i].titulo);
                printf("Autor: %s\n", libros[i].autor.nombre);
                printf("Nacionalidad: %s\n", libros[i].autor.nacionalidad);
                printf("Fecha: %d\n", libros[i].publicacion.fecha);
                printf("Cantidad: %d\n", libros[i].publicacion.cantidadEjemplares);
                printf("Estado: %s\n", libros[i].estado);
                encontrado = 1;
                break;
            }
        }
    }
    
    if (!encontrado) {
        printf("\nLibro no encontrado.\n");
    }
}

void actualizarEstado(struct Libro libros[], int total) {
    if (total == 0) {
        printf("\nNo hay libros.\n");
        return;
    }
    
    int id;
    printf("\nID del libro: ");
    scanf("%d", &id);
    while(getchar() != '\n');
    
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            printf("Estado actual: %s\n", libros[i].estado);
            
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                char prestado[] = "Prestado";
                for (int j = 0; prestado[j] != '\0'; j++) {
                    libros[i].estado[j] = prestado[j];
                }
                libros[i].estado[8] = '\0';
            } else {
                char disponible[] = "Disponible";
                for (int j = 0; disponible[j] != '\0'; j++) {
                    libros[i].estado[j] = disponible[j];
                }
                libros[i].estado[10] = '\0';
            }
            
            printf("Nuevo estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void eliminarLibro(struct Libro libros[], int *total) {
    if (*total == 0) {
        printf("\nNo hay libros.\n");
        return;
    }
    
    int id;
    printf("\nID a eliminar: ");
    scanf("%d", &id);
    while(getchar() != '\n');
    
    for (int i = 0; i < *total; i++) {
        if (libros[i].id == id) {
            printf("Eliminando: %s\n", libros[i].titulo);
            
            for (int j = i; j < *total - 1; j++) {
                libros[j] = libros[j + 1];
            }
            
            (*total)--;
            printf("Libro eliminado.\n");
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

int validarID(struct Libro libros[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            return 1;
        }
    }
    return 0;
}
