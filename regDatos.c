#include "estructuras.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void pedirDatosUsuario() {
  char opcion;

  printf("1 : Crear profesores\n");
  printf("2 : Crear alumnos\n");
  printf("3 : crear ambos\n");
  printf("Escoja una opcion: ");
  scanf("%c", &opcion);
  while (((opcion - '0') > 3) || (isdigit(opcion) == 0)) {
    printf("Escoja una opcion\n");
    printf("1 : Crear profesores\n");
    printf("2 : Crear alumnos\n");
    printf("3 : crear ambos\n");
    printf("Escriba un numero: ");
    scanf("%c", &opcion);
  }
  if (opcion == '1') {
    char num;
    printf("Escriba el numero de profesores a registrar: ");
    scanf("%c", &num);
    while (((num - '0') < 2) || (isdigit(num) == 0)) {
      printf("Debe ingresar dos o mas profesores\n");
      printf("Ingrese el numero de profesores a registrar: ");
      scanf("%c", &num);
    }

    prof *profesores;
    profesores = (prof *)calloc(num - '0', sizeof(prof));

    for (int i = 0; i < (num - '0'); i++) {
      prof p_temp = crearProfesor(i);
      profesores[i] = p_temp;
      printf("\n");
    }
    eliminarMateriaProfesor(num - '0', profesores);
    printf("\n");
    for (int i = 0; i < (num - '0'); i++) {
      mostrarDatosProfesor(i, profesores);
      printf("\n");
    }

    free(profesores);
  } else if (opcion == '2') {
    char num;
    printf("Escriba el numero de alumnos a registrar: ");
    scanf("%c", &num);
    while (((num - '0') < 2) || (isdigit(num) == 0)) {
      printf("Debe ingresar dos o mas alumnos\n");
      printf("Ingrese el numero de alumnos a registrar: ");
      scanf("%s", &num);
    }
    al *alumnos;
    alumnos = (al *)calloc(num - '0', sizeof(al));

    for (int i = 0; i < (num - '0'); i++) {
      al al_temp = crearAlumno(i);
      alumnos[i] = al_temp;
      printf("\n");
    }
    eliminarMateriaAlumno(num - '0', alumnos);
    printf("\n");
    cambiarNivel(num - '0', alumnos);
    printf("\n");
    for (int i = 0; i < (num - '0'); i++) {
      mostrarDatosAlumno(i, alumnos);
      printf("\n");
    }
    free(alumnos);
    printf("\n");
  } else if (opcion == '3') {
    char num;
    printf("Escriba el numero de personas a registrar: ");
    scanf("%c", &num);
    while (((num - '0') < 2) || (isdigit(num) == 0)) {
      printf("Debe ingresar dos o mas personas\n");
      printf("Ingrese el numero de personas a registrar: ");
      scanf("%s", &num);
    }

    prof *profesores_a;
    profesores_a = (prof *)calloc(1, sizeof(prof));
    al *alumnos_a;
    alumnos_a = (al *)calloc((num - '0') - 1, sizeof(al));

    for (int i = 0; i < (num - '0'); i++) {
      if (i == 0) {
        prof p_temp = crearProfesor(i);
        profesores_a[i] = p_temp;
        printf("\n");
      } else {
        al al_temp = crearAlumno(i - 1);
        alumnos_a[i - 1] = al_temp;
        printf("\n");
      }
    }
    eliminarMateriaProfesor(1, profesores_a);
    printf("\n");
    eliminarMateriaAlumno((num - '0') - 1, alumnos_a);
    printf("\n");
    cambiarNivel((num - '0') - 1, alumnos_a);
    printf("\n");
    for (int i = 0; i < (num - '0'); i++) {
      if (i == 0) {
        mostrarDatosProfesor(i, profesores_a);

        printf("\n");
      } else {
        mostrarDatosAlumno(i - 1, alumnos_a);

        printf("\n");
      }
    }
    printf("\n");
    free(profesores_a);
    free(alumnos_a);
  }
}