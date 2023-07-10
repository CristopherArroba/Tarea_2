#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include "estructuras.h"

int main(int argc, char *argv[]) {
  
  int opt = getopt(argc, argv, ":e:p:a:");
  
  int nmaterias;
  if(opt == -1){
    pedirDatosUsuario();
  }
  while(opt  != -1)
    {   
        switch(opt) 
        { 
            
            case 'p':
                
                while(((optarg[0] - '0') < 2) || (isdigit(optarg[0]) == 0)){
                  printf("Debe ingresar dos o mas profesores\n");
                  printf("Ingrese el numero de profesores a registrar: ");
                  scanf("%s", optarg);
                  
                }
                
                prof *profesores;
                profesores = (prof*) calloc(optarg[0] - '0', sizeof(prof));

                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  prof p_temp = crearProfesor(i);
                  profesores[i] = p_temp;
                  printf("\n");
                }
                eliminarMateriaProfesor(optarg[0] - '0', profesores);
                printf("\n");
                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  mostrarDatosProfesor(i,profesores);
                  printf("\n");
                }
                

                free(profesores);
                printf("\n");
                break;


          
            case 'e':
                
                
                while(((optarg[0] - '0') < 2) || (isdigit(optarg[0]) == 0)){
                  printf("Debe ingresar dos o mas alumnos\n");
                  printf("Ingrese el numero de alumnos a registrar: ");
                  scanf("%s", optarg);
                  
                }
                al *alumnos;
                alumnos = (al*) calloc(optarg[0] - '0', sizeof(al));

                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  al al_temp = crearAlumno(i);
                  alumnos[i] = al_temp;
                  printf("\n");
                }
                eliminarMateriaAlumno(optarg[0] - '0', alumnos);
                printf("\n");
                cambiarNivel(optarg[0] - '0', alumnos);
                printf("\n");
                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  mostrarDatosAlumno(i, alumnos);
                  printf("\n");

                  
                }
                free(alumnos);
                printf("\n");
                
                break;


          
            case 'a':
                while(((optarg[0] - '0') < 2) || (isdigit(optarg[0]) == 0)){
                  printf("Debe ingresar dos o mas personas\n");
                  printf("Ingrese el numero de personas a registrar: ");
                  scanf("%s", optarg);
                  
                }
                
                prof *profesores_a;
                profesores_a = (prof*) calloc(1, sizeof(prof));
                al *alumnos_a;
                alumnos_a = (al*) calloc((optarg[0] - '0')-1, sizeof(al));

                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  if(i == 0)
                  {
                    prof p_temp = crearProfesor(i);
                    profesores_a[i] = p_temp;
                    printf("\n");
                  }
                  else{
                    al al_temp = crearAlumno(i-1);
                    alumnos_a[i-1] = al_temp;
                    printf("\n");
                  }
                }
                eliminarMateriaProfesor(1, profesores_a);
                printf("\n");
                eliminarMateriaAlumno((optarg[0] - '0')-1, alumnos_a);
                printf("\n");
                cambiarNivel((optarg[0] - '0')-1, alumnos_a);
                printf("\n");
                for(int i = 0; i < (optarg[0] - '0'); i++ ){
                  if(i == 0){
                  mostrarDatosProfesor(i,profesores_a);

                  printf("\n");
                  }
                  else{
                  mostrarDatosAlumno(i-1, alumnos_a);

                  printf("\n");
                  }
                }
                printf("\n");
                free(profesores_a);
                free(alumnos_a);
                break;
          
            case ':': 
                printf("Opción: %c  Falta argumento\n", optopt); 
                break; 
            case '?': 
                printf("Opción no reconocida: %c\n", optopt);
                break; 
         
        }
      opt = getopt(argc, argv, ":e:p:a:");
    }

  
    return 0;



  
}