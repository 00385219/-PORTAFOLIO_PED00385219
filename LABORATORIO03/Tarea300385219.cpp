#include <iostream>
using namespace std;

struct estudiante 
{
    string nombre, nivel, horas;
    int carnet;
};

struct nodo 
{
    estudiante datosEstudiante;
    nodo* sig;
};

void pilaDatos(nodo** pPila, estudiante estud);
void colaDatos(nodo** pCola, estudiante estud);
void filtrarDatos(nodo* pPila, nodo* pCola, int id);
void mostrarEstudiantesPila(nodo* lista);
void mostrarEstudiantesCola(nodo* lista);

int main(void) 
{
    nodo* pPila = NULL, *pCola = NULL;
    estudiante estud;

    int opcion = 0, carnetBuscar = 0, ingresarOtro = 0;

    do {
        cout << endl <<"\tBienvenido al sistema de registro de estudiantes de la UCA\n" << endl;
        cout << "1. Ingresar registro de estudiante  " << endl;
        cout << "2. Ingresar asistencia de estudiante" << endl;
        cout << "3. Mostrar registro de asistencia de estudiantes" << endl;
        cout << "4. Buscar estudiantes por carnet" << endl;
        cout << "5. Ver todos los estudiantes" << endl;
        cout << "0. Salir" << endl;
        cout << "\n¿Que opcion elige?: "; 
        cin >> opcion;
        cout << endl;

        cin.clear(), cin.ignore(1000, '\n');

        if (opcion < 0 or opcion >5)
        {
            cout << "\n OPCION INGRESADA ES INVALIDA\n Intente nuevamente.\n";
        }
        
        switch(opcion) 
        {
            case 1:
                do {
                    cout << "\tIngresa la informacion del estudiante:\n";
                    cout << "Carnet: "; cin >> estud.carnet;
                    cin.clear(); cin.ignore(1000, '\n');

                    //getline(cin,*variable*,'\n') -> permite que se almacene toda la informacion ingresada hasta
                    //que exista un salta de linea
                    //el cin normal solo me almacenaba la primera palabra lo cual daba problema al ingresar nombre completo
                    cout << "Nombre: "; getline(cin,estud.nombre,'\n');
                    cout << "Nivel de carrera: "; getline(cin,estud.nivel,'\n');
                    cout << "Horas sociales: "; getline(cin,estud.horas,'\n');

                    pilaDatos(&pPila, estud);

                    cout << "\n¿Ingresara otro estudiante?\n"; 
                    cout << "Ingrese 0 para 'NO' - Ingrese 1 para 'SI': "; 
                    cin >> ingresarOtro;
                    cout << endl;

                }while(ingresarOtro != 0);

                break;

            //Para la toma de asistencia, no se especifica que datos se deben tomar, pero analizando, solo es necesario
            //pedir carnet y nombre, ya que segun mi opinion para la asistencia es lo que generalmente se pide
            case 2:
                do {
                    cout << "\tIngresa la informacion del estudiante:\n";
                    cout << "Carnet: "; cin >> estud.carnet;
                    cin.clear(); cin.ignore(1000, '\n');

                    cout << "Nombre: "; getline(cin,estud.nombre);

                    colaDatos(&pCola, estud);

                    cout << "\n¿Ingresara otro estudiante?\n"; 
                    cout << "Ingrese 0 para 'NO' - Ingrese 1 para 'SI': "; 
                    cin >> ingresarOtro;
                    cout << endl;

                }while(ingresarOtro != 0);
                
                break;

            case 3:
                cout << endl << "\tEstudiantes registrados en asistencia" << endl;
                cout << endl << "\tDeben salir en este orden:" << endl;
                mostrarEstudiantesCola(pCola);
                break;

            case 4:
                cout << "Ingresar numero de carnet a buscar: "; cin >> carnetBuscar;
                filtrarDatos(pPila, pCola, carnetBuscar);
                break;

            case 5:
                cout << "\tTodos los estudiantes registrados: " << endl;
                mostrarEstudiantesPila(pPila);
                break;

            case 0: //este case es para validar si realmente el usuario desea salir del programa o ingreso 0 erroneamente
                int seguroSalir;
                cout << "\n¿estas seguro de salir?\nIngresa '0' si deseas realmente salir o ingresa '1' para regresar al menu:\n";
                cin >> seguroSalir;

                if (seguroSalir==0)
                {
                    cout << "\t\nHas ingresado salir del programa de registros, ¡Hasta pronto!\n" << endl;
                    return 0;
                }
                else
                {
                    //con esto cambiamos la opcion ingresada originalmente por el usuario
                    //al ser 6 no realiza ningua de las 5 opciones y hace que el bucle del while continue
                    opcion = 6; 
                }
                

            default:
                break;
        }

 

    } while(opcion != 0);

}

void pilaDatos(nodo** pPila, estudiante estud) 
{
    nodo* n = new nodo;
    n->datosEstudiante = estud;
    n->sig = *pPila;
    *pPila = n;
}

void colaDatos(nodo** pCola, estudiante estud) 
{
    nodo* n = new nodo;
    n->datosEstudiante = estud;
    n->sig = NULL;

    if(!*pCola)
        *pCola = n;
    else {
        nodo* aux = *pCola;

        while(aux->sig)
            aux = aux->sig;
        
        aux->sig = n;
    }
}

void filtrarDatos(nodo* pPila, nodo* pCola, int carnet) 
{

    bool encontrado = false;

    nodo* aux = pPila;

    while(aux) 
    {
        if(aux->datosEstudiante.carnet == carnet) 
        {
            cout << "Nombre: " << aux->datosEstudiante.nombre << endl;
            cout << "Nivel de carrera: " << aux->datosEstudiante.nivel << endl;
            cout << "Horas sociales: " << aux->datosEstudiante.horas << endl;

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(encontrado)
        return;
    
    if(!encontrado)
    {
        cout << "No se ha encontrado ese estudiante" << endl;
    }
}

void mostrarEstudiantesPila(nodo* lista) 
{
    nodo* aux = lista;

    while(aux) 
    {
        cout << "Carnet: " << aux->datosEstudiante.carnet << endl;
        cout << "Nombre: " << aux->datosEstudiante.nombre << endl;
        cout << "Nivel de horas: " << aux->datosEstudiante.nivel << endl;
        cout << "Horas sociales: " << aux->datosEstudiante.horas << endl << endl;

        aux = aux->sig;
    }
}

void mostrarEstudiantesCola(nodo* lista) 
{
    if(lista) {
        cout << "Carnet: " << lista->datosEstudiante.carnet << endl;
        cout << "Nombre: " << lista->datosEstudiante.nombre << endl << endl;

        mostrarEstudiantesCola(lista->sig);
    }
}