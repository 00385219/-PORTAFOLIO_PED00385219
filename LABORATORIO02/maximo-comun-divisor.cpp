#include<iostream>
using namespace std;
int maximo_comun_divisor(int numero1,int numero2);
int main()
{
	int n1,n2;
	cout<<"\n\t->  Calcula el Maximo Comun Divisor  <-\n"<<endl;
	
	do
	{
		cout<<"\nEl primer termino a ingresar debe ser mayor al segundo, si no se cumple, empezara nuevamente: \n";
		cout<<"Primer termino: ";
		cin>>n1;
		cout<<"Segundo termino: ";
		cin>>n2;
	} while (n1 <= n2);
	

	cout<<"\n\tMaximo comun divisor de "<<n1<<" y "<<n2<< " es:"<<endl;
	cout<<"\t"<<maximo_comun_divisor(n1,n2)<<endl;

	cout<<"\n¡Hasta pronto!\n\n";
}
int maximo_comun_divisor(int numero1,int numero2)
{
	if(numero1==0 && numero2==0)
		return 0;
	if(numero1==0 )
		return numero2;
	else if(numero2==0)
		return numero1;
	else
	{
		return  maximo_comun_divisor(numero2,numero1%numero2);
		
	}
}
