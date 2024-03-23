#include <iostream>
#include <malloc.h>
using namespace std;
/*LUISA FERNANDA GONZALEZ DELGADO Y VERONICA MORALES OROZCO*/

struct cliente {
    int num_cuenta ;
    int tipo ;
    int turno;
   cliente  *sig;
   
};

cliente *cabeza2, *cabeza, *aux,  *aux2 ;

void registrar(){

    int opc=0;
        cout<<"tipo de cuenta  "<<endl;;
        cout<<"1.preferencial"<<endl;
        cout<<"2.tradicional"<<endl;
         cin>>opc;
if (opc==1)
{
 
  if(! cabeza2){
 cabeza2=(struct cliente  *)malloc(sizeof(struct cliente ));
    
        cout<<"ingrese numero de cuenta  :  ";
        cin>>cabeza2->num_cuenta ;
       
        cabeza2->sig=NULL;
    }else{
        aux=cabeza2;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }

        aux2=(struct cliente *)malloc(sizeof(struct cliente ));
        cout<<"ingrese numero de cuenta:  ";
        cin>>aux2->num_cuenta ;
        
        aux2->sig=NULL;
        aux->sig=aux2;
        aux=aux2=NULL;
        free(aux);
        free(aux2);

    }
}
else 

        
        if(!cabeza){
cabeza=(struct cliente  *)malloc(sizeof(struct cliente ));
    
        cout<<"ingrese numero de cuenta  :  ";
        cin>>cabeza->num_cuenta ;
       
       cabeza->sig=NULL;
    }else{
        aux=cabeza;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }

        aux2=(struct cliente *)malloc(sizeof(struct cliente ));
        cout<<"ingrese numero de cuenta:  ";
        cin>>aux2->num_cuenta ;
        
        aux2->sig=NULL;
        aux->sig=aux2;
        aux=aux2=NULL;
        free(aux);
        free(aux2);

    }
            
            

}
void contar_clientes(){
int cantidad=0;
   int cant = 0;
       for(aux=cabeza2; aux!=NULL; aux=aux->sig){
     cant++;
       }
    cout<<" clientes en la fila preferencia es : "<<cant<<endl;

    for(aux=cabeza; aux!=NULL; aux=aux->sig){
     cant++;
       }
    cout<<" clientes en la fila tradicional es : "<<cantidad<<endl;
if (cantidad >= 5 && cant <=2 )
{
    
}


}



void eliminar(){
    int elemento=0, elemento1=0;
    int tip;
    cout<<"Digite tipo de cuenta "<<endl;
    cout<<"1.preferencial "<<endl;
    cout<<"2.tradicional "<<endl;
    cin>>tip;
    switch(tip)
    {
    case 1:
    cout<<"Digite numero de cuenta a eliminar: "<<endl;
    cin>>elemento;
    aux = cabeza2;
    while(aux != NULL && aux->num_cuenta!=elemento) {            
        aux = aux->sig;
    }
    if(aux!=NULL){
        aux2 = cabeza2;
        while(aux2->sig!=aux){
            aux2 = aux2->sig;
        }
        aux2->sig = aux->sig;
        free(aux);
        aux2 = NULL;
        free(aux2);
       
        break;
    case 2:
    cout<<"Digite numero de cuenta a eliminar: "<<endl;
    cin>>elemento1;
    aux = cabeza;
    while(aux != NULL && aux->num_cuenta!=elemento1) {            
        aux = aux->sig;
    }
    if(aux!=NULL){
        aux2 = cabeza;
        while(aux2->sig!=aux){
            aux2 = aux2->sig;
        }
        aux2->sig = aux->sig;
        free(aux);
        aux2 = NULL;
        free(aux2);
    default:
        break;
    }
    
}
    }
    }
void fila_preferencial(){
    
     double cantidad=1;
      
        for(aux=cabeza2; aux!=NULL; aux=aux->sig){
        cout<<"----------------------------------------"<<endl;
        cout<<" su numero de cuenta es : "<<aux->num_cuenta<<endl; 
        cout <<" tipo de cuenta :preferencial"<<endl;
        cout <<" turno"<<cantidad++<<endl;
      }
      
     free(aux);

    
   
    

}




void fila_tradicional(){
double cantidad=1;
for(aux=cabeza; aux!=NULL; aux=aux->sig){
        cout<<"----------------------------------------"<<endl;
        cout<<" su numero de cuenta es : "<<aux->num_cuenta<<endl; 
        cout <<" tipo de cuenta : tradicional"<<endl;
        cout <<" turno"<<cantidad++<<endl;
      }
      
     free(aux);


}

int main(){

    int opc=0;
    do{

    cout<<"menu"<<endl;
    cout<<"1.Registrar: "<<endl;
    cout<<"2.FILA PREFERENCIAL: "<<endl;
    cout<<"3.FILA TRADICIONAL: "<<endl;
    cout<<"4.Eliminar:"<<endl;
     cout<<"5.contar clientes :"<<endl;
    cout<<"6.salir"<<endl;
    cin>>opc;

        switch (opc)
        {
        case 1:registrar();
            break;
        case 2: fila_preferencial();
            break;
         case 3: fila_tradicional();

           break;
        case 4:eliminar();
            break;
        case 5: contar_clientes();
         break;
       

        default: cout<<"gracias por usar el programa"<<endl;
            break;
        }

    }while (opc!=6);

    return 0;
}
