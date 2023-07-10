typedef struct MateriasDictadas{
char nombre[50];
char paralelo[50];
}md;

typedef struct Materiastomadas{
char nombre[50];
int creditos;
}mt;

typedef struct Profesor{
char nombre[50];
char carrera[50];
md materias_dictadas[3];
}prof;

typedef struct Alumno{
char nombre[50];
int nivel;
char carrera[50];
mt materias_tomadas[7]; 
}al;
int len(char *s);
void pedirDatosUsuario();
prof crearProfesor(int i);

al crearAlumno(int i);

void mostrarDatosProfesor(int i, prof profesores[]);

void mostrarDatosAlumno(int i, al alumnos[]);

void eliminarMateriaProfesor(int n_personas, prof profesores[]);

void eliminarMateriaAlumno(int n_personas, al alumnos[]);

void cambiarNivel(int n_personas, al alumnos[]);

