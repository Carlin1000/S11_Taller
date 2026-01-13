#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10
#define MAX_TITULO 100
#define MAX_NOMBRE 50
#define MAX_NACIONALIDAD 30

struct Autor {
    char nombre[MAX_NOMBRE];
    char nacionalidad[MAX_NACIONALIDAD];
};

struct InfoPublicacion {
    int fecha;
    int cantidadEjemplares;
};

struct Libro {
    int id;
    char titulo[MAX_TITULO];
    struct Autor autor;
    struct InfoPublicacion publicacion;
    char estado[20];
};

// Función para mostrar el menú principal
void mostrarMenu();

// Función para registrar un nuevo libro
void registrarLibro(struct Libro libros[], int *total);

// Función para mostrar todos los libros registrados
void mostrarLibros(struct Libro libros[], int total);

// Función para buscar un libro por ID o título
void buscarLibro(struct Libro libros[], int total);

// Función para actualizar el estado de un libro
void actualizarEstado(struct Libro libros[], int total);

// Función para eliminar un libro del sistema
void eliminarLibro(struct Libro libros[], int *total);

// Función para validar si un ID ya existe
int validarID(struct Libro libros[], int total, int id);

// Función para validar que el texto no contenga números
int validarTexto(char texto[]);
