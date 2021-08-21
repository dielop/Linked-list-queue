#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato ;
    struct nodo * sgte ;
} cola ;


void encolar(cola **,cola **,int );//aniade elemento al final de la cola

int desencolar(cola **,cola **);//elimina y retorna el primer elemento de la cola (elimina por FRENTE)

void vaciaCola(cola **);

int tamanio(cola *);

int estaVacia(cola **);

int imprimeFrente(cola *);



int main(){
    cola *frente, *end ;
    frente = NULL ;
    end = NULL ;
    cola **pfrente;
    pfrente = &frente;
    cola **pend;
    pend = &end;

    int e;
    int x=0;
    int ult=0;

    do{
        printf("Elija lo que quiera hacer con la COLA:\n 1 - ENCOLAR\n 2 - DESENCOLAR\n 3 - VER FRENTE\n 4 - VACIAR\n 5 - VER TAMANIO\n 6 - VER SI ESTA VACIA\n 7 - SALIR\n\n");
        scanf("%d",&x);
        switch(x){
        case 1:
            printf("Ingrese el elemento que desea encolar:\n");
            scanf("%d", &e);
            encolar(pfrente,pend,e);
            break;
        case 2:
            if (estaVacia(pfrente)==0) printf("La COLA ya esta VACIA\n");
            else{
                ult = desencolar(pfrente,pend);
                if (ult == -1) printf ("La COLA quedo VACIA\n");
                else printf("Ahora el ultimo elemento es:%d\n",ult);
            }
            break;
        case 3:
            if (estaVacia(pfrente) != 0) printf("El FRENTE de la COLA es: %d\n",imprimeFrente(frente));
            else printf("La COLA no tiene elementos\n");
            break;
        case 4:
            vaciaCola(pfrente);
            break;
        case 5:
            printf("El numero de elementos de la COLA es: %d\n",tamanio(frente));
            break;
        case 6:
            if (estaVacia(pfrente)==0) printf("La COLA esta vacia\n");
            else printf("la COLA no esta vacia\n");
            break;
        case 7:
            printf("Fin del programa");
            break;
             
        default:
            printf("Ingrese una opcion entre 1 y 7.\n");
            break;
        }
    } while (x!=7);


return 0;
}

void encolar(cola **pf, cola **pe, int e){ 
    if (*pf == NULL && *pe == NULL){
        *pf = (cola*)malloc(sizeof(cola));
        (*pf)->dato = e;
        (*pf)->sgte = NULL;
        *pe = &(**pf);
    }
    else{
       (*pe)->sgte = (cola*)malloc(sizeof(cola));
        *pe = (*pe)->sgte;
        (*pe)->dato = e;
        (*pe)->sgte = NULL;
    }
}

int desencolar(cola **pf, cola **pe){ 
    cola *temp = (*pf)->sgte;
    free(*pf);
    *pf = &(*temp);

    if(estaVacia(pf)!=0){
        int dat = (*pf)->dato;
        return dat;
    }
    else return -1;
}

void vaciaCola(cola **pf){
    if (estaVacia(pf)==0) printf("La COLA ya esta vacia\n");
    else{
        cola *temp;
        while((*pf) != NULL){
            temp = *pf;
            *pf = (*pf)->sgte;
            free(temp);
        }
    }
}

int tamanio(cola *p){
    if(p == NULL) return 0;
    else if ((p->sgte) == NULL) return 1;
    else{
        int cont=0;
        cola *temp;
        temp = &(*p);

        while(((temp)->sgte) != NULL){
            cont ++;
            cola *temp2;
            temp2 = &*(temp->sgte);
            temp = temp2;
        }
    return cont+1; 
    }
}

int estaVacia(cola **pf){
    if(*pf == NULL) return 0;
    else return 1;
}

int imprimeFrente(cola *f){
    int dato = f->dato;
    return dato;
}
