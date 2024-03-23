#include <iostream>
#include <malloc.h>
using namespace std;
/*LUISA FERNANDA GONZALEZ DELGADO Y VERONICA MORALES OROZCO*/
struct cliente_preferencial{
    int num_cuenta ;
    int tipo ;
    int turno;
   cliente_preferencial  *sig;
};
cliente_preferencial  *cabeza, *aux,  *aux2  ;
struct cliente_tradicional{
    int num_cuenta ;
    int tipo ;
    int turno;
   cliente_tradicional  *sig;
};

cliente_tradicional  *cabeza2, *aux0,  *aux1  ;

void registrar(){

    int opc=0;
        cout<<"tipo de cuenta  "<<endl;;
        cout<<"1.preferencial"<<endl;
        cout<<"2.tradicional"<<endl;
         cin>>opc;

        switch (opc)
        {
        case 1: if(!cabeza){
 cabeza=(struct cliente_preferencial  *)malloc(sizeof(struct cliente_preferencial ));
    
        cout<<"ingrese numero de cuenta  :  ";
        cin>>cabeza->num_cuenta ;
       
        cabeza->sig=NULL;
    }else{
        aux=cabeza;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }

        aux2=(struct cliente_preferencial  *)malloc(sizeof(struct cliente_preferencial ));
        cout<<"ingrese numero de cuenta:  ";
        cin>>aux2->num_cuenta ;
        
        aux2->sig=NULL;
        aux->sig=aux2;
        aux=aux2=NULL;
        free(aux);
        free(aux2);

    }
            
            break;
        case 2: 
      
        if(!cabeza2){
 cabeza2=(struct cliente_tradicional  *)malloc(sizeof(struct cliente_tradicional ));
        
        cout<<"ingrese numero de cuenta  :  ";
        cin>>cabeza2->num_cuenta ;
        
        cabeza2->sig=NULL;
    }else{
        aux0=cabeza2;
        while(aux0->sig!=NULL){
            aux0 = aux0->sig;
        }

        aux1=(struct cliente_tradicional *)malloc(sizeof(struct cliente_tradicional ));
        cout<<"ingrese numero de cuenta:  ";
        cin>>aux1->num_cuenta ;
       
        aux1->sig=NULL;
        aux0->sig=aux1;
        aux0=aux1=NULL;
        free(aux0);
        free(aux1);
break;
    }
        default:
            break;
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
    aux = cabeza;
    while(aux != NULL && aux->num_cuenta!=elemento) {            
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
       
        break;
    
    default:
        break;
    }
    
}
}
void fila_preferencial(){
     double cantidad=1;
      cout<<" FILA PREFERENCIAL"<<endl;
    for(aux = cabeza; aux!=NULL; aux=aux->sig){
        
        cout<<"----------------------------------------"<<endl;
        cout<<" su numero de cuenta es : "<<aux->num_cuenta<<endl; 
        cout <<" tipo de cuenta : preferencial "<<endl;
        cout <<" turno"<<cantidad++<<endl;

    }
    free(aux);
    

}


void fila_tradicional(){
double cantidad=1;
cout<<" FILA TRADICIONAL"<<endl;
    for(aux0 = cabeza2; aux0!=NULL; aux0=aux0->sig){
    
    cout<<"----------------------------------------"<<endl;
    cout<<" su numero de cuenta es : "<<aux0->num_cuenta<<endl; 
    cout <<"su tipo de cuenta es: tradicional "<<endl;
     cout <<" turno"<<cantidad++<<endl;

}
free(aux0);

}



int main(){

    int opc=0;
    do{

    cout<<"menu"<<endl;
    cout<<"1.Registrar: "<<endl;
    cout<<"2.FILA PREFERENCIAL: "<<endl;
    cout<<"3.FILA TRADICIONAL:"<<endl;
    cout<<"4.Eliminar:"<<endl;
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

       

        default: cout<<"gracias por usar el programa"<<endl;
            break;
        }

    }while (opc!=6);

    return 0;
}
