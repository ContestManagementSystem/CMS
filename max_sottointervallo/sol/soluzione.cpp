/* 
 * Massima sotto intervallo ascendente
 * Author: marco
 *
 * Created on March 25, 2017, 4:44 PM
 */

#include <fstream>
using namespace std;

int main() 
{
	int dim = 0;
	ifstream read("input.txt");
	ofstream write("output.txt");
	read >> dim;
    int a[dim]={0}, sx_temp=0,dx_temp=0,sx=0,dx=0;  //utilizzo degli indici temporanei e degli indici "finali"
        
    for(int i=0;i<dim;++i) read>>a[i];  // acquisisco i valori dell'array
    
    for(int i=0;i<dim-1;++i)  // ciclo su tutti i valori per trovare il massimo sottointervallo crescente
        {
        if(a[i]<a[i+1])
        {
            dx_temp++;  // se l'intervallo prosegue con andamento strettamente ascendente non vi è altro da fare
        }        
        else   //altrimenti...... 
        {
            if((dx_temp-sx_temp)>(dx-sx))   // se fino a questo momento l'inteervallo trovato è maggiore in numero di elementi di quello precedentemente acquisito....
            {
                dx=dx_temp;
                sx=sx_temp;
                sx_temp=i+1;
                dx_temp=i+1;   
                                     
            }
            else   // se no mi basta portare al nuovo elemento gli indici temporanei
            {
                sx_temp=i+1;
                dx_temp=i+1;   
            }                  
        }        
    }
    if((dx_temp-sx_temp)>(dx-sx))   //devo controllare ancora alla fine (se l'intervallo max era proprio quella che concludeva l'array.... meditate.....
    {
                dx=dx_temp;
                sx=sx_temp;                                    
    }
	write<<(dx-sx)+1<<endl;
    for(int i=sx;i<=dx;++i)  write<<a[i]<<' ';  // do in output l'intervallo...
    write<<endl;
    return 0;
}

