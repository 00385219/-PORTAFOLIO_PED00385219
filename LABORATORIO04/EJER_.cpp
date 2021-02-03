#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include<malloc.h>
#include<stdio.h>

using namespace std;
typedef struct Celda{
       int Dato;
       struct Celda *sig;
       }NODO;
       NODO *Inicio;

void inicializar(){
     Inicio=NULL;
     }

int ListaVacia(NODO *Inicio){
if (Inicio==NULL)
  return 1;
else
  return 0;
}

void Agregar(  int elem){
     NODO *Nuevo, *anterior,*siguiente;
     Nuevo=(NODO *)malloc (sizeof (NODO));
     Nuevo->Dato=elem;
     Nuevo->sig=NULL;
     if (Inicio==NULL)
       Inicio=Nuevo;
     else
       if ( Nuevo->Dato<Inicio->Dato)
	 {
		Nuevo->sig=Inicio;
		Inicio=Nuevo;
		}
	 else
	   {
	      anterior=Inicio;
	      siguiente=anterior->sig;
	      while(siguiente!=NULL && Nuevo->Dato > siguiente->Dato)
		{
		    anterior=siguiente;
		    siguiente=siguiente->sig;
		 }
		 Nuevo->sig=  siguiente;
		 anterior->sig=Nuevo;
	    }
     }
void Eliminar(int elem)
     {
       NODO *aux,*anterior,*siguiente;
       if (ListaVacia(Inicio))
	 		cout<<"La lista esta vacia";
       else
    	if (elem==Inicio->Dato)
	    {
	 	    aux=Inicio;
	   	    Inicio=Inicio->sig;
	   	    free(aux);
	    }
	 else
	  {
	 	   anterior=Inicio;
	   	   siguiente=anterior->sig;
	    while(siguiente!=NULL && elem!=siguiente->Dato)
	    {
	      anterior=siguiente;
	      siguiente=siguiente->sig;
	    }
	    if(siguiente->Dato==elem)
	    {
	      anterior->sig=siguiente->sig;
	      free(siguiente);
	    }
	    else
	      cout<<"El dato no existe";
	  }
    }
     void Desplegar(NODO *aux){

	  if (!ListaVacia(Inicio) )
	  while (aux!=NULL)
	  {
	  	if(aux->Dato!=0)
	  	{
	  		cout<<"\t  "<< aux->Dato;
	     aux=aux->sig;
		  }
	    
		}
	  else
	    cout<<"Lista Vacia";
	  }
	  void eliminar_repetidos()
	  {
	  	int elem,pos=0,pos2=0;
	  	
		  NODO *aux,*anterior,*siguiente,*aux2;
		  while(aux!=NULL)
		  {
		  	elem=aux->Dato;
		  	pos2=0;
		  	while(aux2!=NULL)
		  	{
		  		if(pos!=pos2)
		  		{
		  			if (ListaVacia(Inicio))
			 		cout<<"La lista esta vacia";
				       else
				    	if (elem==Inicio->Dato)
					    {
					 	    aux=Inicio;
					   	    Inicio=Inicio->sig;
					   	    free(aux);
					    }
					 else
					  {
					 	   anterior=Inicio;
					   	   siguiente=anterior->sig;
					    while(siguiente!=NULL && elem!=siguiente->Dato)
					    {
					      anterior=siguiente;
					      siguiente=siguiente->sig;
					    }
					    if(siguiente->Dato==aux->Dato)
					    {
					      anterior->sig=siguiente->sig;
					      free(siguiente);
					    }
					    else
					      cout<<"El dato no existe";
					  }
				  }
		  		
		  		
				  pos2++;
			  }
			  	pos++;
		  }
	       
	  }
  void Buscar(int elem)
     {  NODO *aux;
       aux=Inicio;
       int existe =0;
       while(aux!=NULL){
          if(aux->Dato==elem){
       	 printf("Elemento encontrado");
	        existe=1;
          } 
	   aux=aux->sig;	
       }
       if (existe==0)
	     printf("No existe");
      }


    int  main(){
	int opc;
//	char letra;
	int num;
	inicializar();
	do{  
//	 system("CLS");
	//cls();
		system("color 0B");
		cout<<"\n\t           M E N U        ";
	   cout<<"\n\t----------------------------\n";
	   cout<<"\n\t     1.- Agregar ";
	   cout<<"\n\t     2.- Eliminar ";
	   cout<<"\n\t     3.- Desplegar ";
	   cout<<"\n\t     4.- Buscar ";
	   cout<<"\n\t     5.- Salir ";
	   cout<<"\n\t----------------------------\n";
	   cout<<"\n Opcion->";
	   cin>>opc;
	//   system("cls");
	   switch(opc){
		  case 1:
		  		cout<<"\n\t   A G R E G A R     ";
		  		 cout<<"\n\t----------------------------\n";
			      cout<<"\n\t Elemento:";
			      cin>>num;
			      Agregar(num);
		       break;
		  case 2: 
				  cout<<"\n\t   E L I M I N A R     ";
				  cout<<"\n\t----------------------------\n";
		  		cout<<"\tElemento:";
			    cin>>num;
			    Eliminar(num);
				break;
		  case 3:
		  		cout<<"\n\t___ ELEMENTOS EN LA LISTA ___\n";
		  		cout<<"\n\t----------------------------\n";
		  		eliminar_repetidos();
		  		Desplegar(Inicio);
				  break;
		  case 4: 
		  		cout<<"\n\t  ____ B U S C A R ___     \n";
		  		cout<<"\n\t----------------------------\n";
		  		cout<<"Elemento:";
			    cin>>num;
			    Buscar(num);
			    
				break;
		  }//switch
	   }  while(opc <5);
	  return (0);
	 }

