#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "estructuras.h"
//retorna la longitud de la cadena
int len(char *s){
  char *p = s;
  while(*p!='\0'){
    p++;
  }
  return p-s;
}
prof crearProfesor(int i){
  prof p_temp;
  int materias;
  printf("Ingrese el nombre del profesor %d (sin espacios): ", i+1);
  scanf("%s", p_temp.nombre);
  printf("Ingrese el nombre de la carrera (sin espacios): ");
  scanf("%s", p_temp.carrera);
  printf("Ingrese el numero de materias a dictar: ");
  scanf("%d", &materias);
  while(materias > 3 || materias < 2){
    printf("El numero de materias a dictar es entre 2 y 3\n");
    printf("Ingrese el numero de materias a dictar: ");
    scanf("%d", &materias);
  }
  for(int m = 0; m < 3; m++){
    p_temp.materias_dictadas[m].nombre[0] = '\0';
  }
  for(int m = 0; m < materias; m++){
    printf("Ingrese el nombre de la materia %d: ", m+1);
    scanf("%s", p_temp.materias_dictadas[m].nombre);
    printf("Ingrese el nombre del paralelo: ");
    scanf("%s", p_temp.materias_dictadas[m].paralelo);
  }
  return p_temp;
}

al crearAlumno(int i){
  al al_temp;
  int materias;
  printf("Ingrese el nombre del alumno %d (sin espacios): ", i+1);
  scanf("%s", al_temp.nombre);
  printf("Ingrese el nivel (sin espacios-numero): ");
  scanf("%d", &al_temp.nivel);
  printf("Ingrese el nombre de la carrera (sin espacios): ");
  scanf("%s", al_temp.carrera);
  printf("Ingrese el numero de materias a tomar: ");
  scanf("%d", &materias);
  while(materias > 7 || materias < 3){
    printf("El numero de materias a tomar es entre 3 y 7\n");
    printf("Ingrese el numero de materias a dictar: ");
    scanf("%d", &materias);
  }
  for(int m = 0; m < 7; m++){
    al_temp.materias_tomadas[m].nombre[0] = '\0';
  }
  for(int m = 0; m < materias; m++){
    
    printf("Ingrese el nombre de la materia %d: ", m+1);
    scanf("%s", al_temp.materias_tomadas[m].nombre);
    printf("Ingrese el numero de creditos de la materia %s: ", al_temp.materias_tomadas[m].nombre);
    scanf("%d", &al_temp.materias_tomadas[m].creditos);
  }
  return al_temp;
}

void mostrarDatosProfesor(int i, prof profesores[]){
  
  printf("\nEl nombre del profesor %d es: %s", i+1, profesores[i].nombre);
  printf("\nEl nombre de la carrera es: %s", profesores[i].carrera);
  
  for(int j = 0; j < 3; j++){
    
    if((len(&profesores[i].materias_dictadas[j].nombre[0])) > 0 ){
      printf("\nMateria dictada: %s", profesores[i].materias_dictadas[j].nombre);
      printf("\nEl nombre del paralelo es: %s", profesores[i].materias_dictadas[j].paralelo);
      
    }
  }
}

void mostrarDatosAlumno(int i, al alumnos[]){
  printf("\nEl nombre del alumno %d es: %s", i+1, alumnos[i].nombre);
  printf("\nEl nivel es: %d", alumnos[i].nivel);
  printf("\nEl nombre de la carrera es: %s", alumnos[i].carrera);
  for(int j = 0; j < 7; j++){
    
    if((len(&alumnos[i].materias_tomadas[j].nombre[0])) > 0){
      printf("\nMateria tomada: %s", alumnos[i].materias_tomadas[j].nombre);
      printf("\nEl numero de creditos es: %d", alumnos[i].materias_tomadas[j].creditos);
      
    }
    
  }
  
}

void eliminarMateriaProfesor(int n_personas, prof profesores[]){
  char letra;
  printf("Desea eliminar una materia de un profesor s/n \n");
  printf("s = si\n");
  printf("n = no\n");
  scanf("%c", &letra);
  
  while(letra != 'S' && letra != 's' && letra != 'N' && letra != 'n'){
    printf("Ingrese el caracter 's' o 'n': ");
    scanf("%c", &letra);
    printf("\n");
  }
  if(letra == 'S' || letra == 's'){
    
    for(int i = 0; i < n_personas; i++ ){
      printf("\n%d profesor: %s", i+1, profesores[i].nombre);
    }
    int num;
    printf("\n");
    printf("Escoja un profesor; ");
    printf("Seleccione un numero: ");
    scanf("%d", &num);
    for(int j = 0; j < 3; j++){
    
      if((len(&profesores[num-1].materias_dictadas[j].nombre[0])) > 0 ){
        printf("\n%d materia: %s", j+1, profesores[num-1].materias_dictadas[j].nombre);
      }
    }
    int num2;
    printf("\n");
    printf("Escoja la materia a eliminar; ");
    printf("Seleccione un numero: ");
    scanf("%d", &num2);
    strcpy(profesores[num-1].materias_dictadas[num2 -1].nombre, "\0");
    strcpy(profesores[num-1].materias_dictadas[num2 -1].paralelo, "\0");
    printf("\nMateria borrada\n");
    eliminarMateriaProfesor(n_personas, profesores);
  }
  
}

void eliminarMateriaAlumno(int n_personas, al alumnos[]){
  char letra;
  printf("Desea eliminar una materia de un alumno s/n \n");
  printf("s = si\n");
  printf("n = no\n");
  scanf("%c", &letra);
  
  while(letra != 'S' && letra != 's' && letra != 'N' && letra != 'n'){
    printf("Ingrese el caracter 's' o 'n': ");
    scanf("%c", &letra);
    printf("\n");
  }
  if(letra == 'S' || letra == 's'){
    
    for(int i = 0; i < n_personas; i++ ){
      printf("\n%d alumno: %s", i+1, alumnos[i].nombre);
    }
    int num;
    printf("\n");
    printf("Escoja un alumno; ");
    printf("Seleccione un numero: ");
    scanf("%d", &num);
    for(int j = 0; j < 7; j++){
    
      if((len(&alumnos[num-1].materias_tomadas[j].nombre[0])) > 0 ){
        printf("\n%d materia: %s", j+1, alumnos[num-1].materias_tomadas[j].nombre);
      }
    }
    int num2;
    printf("\n");
    printf("Escoja la materia a eliminar; ");
    printf("Seleccione un numero: ");
    scanf("%d", &num2);
    strcpy(alumnos[num-1].materias_tomadas[num2 -1].nombre, "\0");
    alumnos[num-1].materias_tomadas[num2 -1].creditos = 0;
    printf("\nMateria borrada\n");
    eliminarMateriaAlumno(n_personas, alumnos);
  }
}

void cambiarNivel(int n_personas, al alumnos[]){
  char letra;
  printf("Desea cambiar el nivel de un alumno s/n \n");
  printf("s = si\n");
  printf("n = no\n");
  scanf("%c", &letra);
  
  while(letra != 'S' && letra != 's' && letra != 'N' && letra != 'n'){
    printf("Ingrese el caracter 's' o 'n': ");
    scanf("%c", &letra);
    printf("\n");
  }
  if(letra == 'S' || letra == 's'){
    
    for(int i = 0; i < n_personas; i++ ){
      printf("\n%d alumno: %s", i+1, alumnos[i].nombre);
      
    }
    int num;
    printf("\n");
    printf("Escoja un alumno: ");
    scanf("%d", &num);
    printf("Escriba en numeros el nuevo nivel: ");
    scanf("%d", &alumnos[num-1].nivel);
    printf("\nNivel cambiado\n");
    cambiarNivel(n_personas, alumnos);
  }
}