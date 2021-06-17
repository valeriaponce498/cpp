#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

string libros[11][3];

void cargaLibros(){
    // Arreglo con categoria y descripcion
    libros[0][0] = "Algoritmos"; libros[0][1] = "Algoritmos y Programacion (Guia para docentes)"; libros[0][2] = "Juan Carlos Lopez Garcia";
	libros[1][0] = "Algoritmos"; libros[1][1] = "Apuntes de Algoritmos y Estructuras de Datos"; libros[1][2] = "Javier Campo";
	libros[2][0] = "Algoritmos"; libros[2][1] = "Breves Notas sobre Analisis de Algoritmos"; libros[2][2] = "Jorge L. Ortega-Arjona";
	libros[3][0] = "Algoritmos"; libros[3][1] = "Fundamentos de Informatica y Programacion"; libros[3][2] = "Gregorio Martin";
	libros[4][0] = "Algoritmos"; libros[4][1] = "Temas selectos de estructuras de datos"; libros[4][2] = "Rosario Arauz";
	libros[5][0] = "Algoritmos"; libros[5][1] = "Teoria sintactico-gramatical de objetos"; libros[5][2] = "Eugenia Bahit";
	libros[6][0] = "Base de Datos"; libros[6][1] = "Apuntes de Base de Datos 1";libros[6][2] = "Armando Suarez";
	libros[7][0] = "Base de Datos"; libros[7][1] = "Base de Datos (2005)";libros[7][2] = "Henry Korth";
	libros[8][0] = "Base de Datos"; libros[8][1] = "Base de Datos (2011)";libros[8][2] = "Valeria Ponce";
	libros[9][0] = "Base de Datos"; libros[9][1] = "Base de Datos Avanzadas (2013)";libros[9][2] = "Roberto Schramm";
	libros[10][0] = "Base de Datos"; libros[10][1] = "Diseno Conceptual de Bases de Datos";libros[10][2] = "Gerardo Lara";

}

int main(int argc, char const *argv[])
{
    cargaLibros();

    srand(time(NULL));

    bool salir = false;

   while (salir == false)
   {
       string buscar = "";
       system("cls");
       cout << "Ingrese la descripcion del libro que busca: ";
       cin >> buscar;

       //busqueda, este hacerlo por autor tambien
       for (int i = 0; i < 11; i++)
       {
           string libro = libros[i][1];
           string autor = libros[i][2];
           string libroEnminuscula = libro;
           string autorEnminuscula = autor;
           // transformacion a minuscula los string buscar y libro
           transform(libroEnminuscula.begin(), libroEnminuscula.end(), libroEnminuscula.begin(), ::tolower);
           transform(autorEnminuscula.begin(), autorEnminuscula.end(), autorEnminuscula.begin(), ::tolower);
           transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);
           
           if (libroEnminuscula.find(buscar) != string::npos || autorEnminuscula.find(buscar) != string::npos){
               cout << "Libro encontrado: " << libro <<endl;

                cout << "Tambien te sugerimos estos libros: " << endl;

                int sugerencia1 = rand() % 5 + 1;
                int sugerencia2 = rand() % 5 + 1;
                int sugerencia3 = rand() % 5 + 1;

                cout << "Sugerencia 1: " << libros[sugerencia1][1] << endl;
                cout << "Sugerencia 2: " << libros[sugerencia2][1] << endl;
                cout << "Sugerencia 3: " << libros[sugerencia3][1] << endl;

               salir = true;
               break;
           }
         }

       if (salir == false){
           char continuar = 'n';
           while (true){
               system("cls");
               cout << "No se encontro el libro que busca. Desea continuar? s/n ";
               cin >> continuar;

               if(continuar == 's' || continuar == 'S'){
                   break;
               }else if(continuar == 'n' || continuar == 'N'){
                   salir = true;
                   break;
               }  
           }  
       }   
   }

    return 0;
}