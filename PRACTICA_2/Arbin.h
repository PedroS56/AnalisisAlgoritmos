#define TRUE 1
#define FALSE 0
typedef int Elem;
typedef char boolean;
typedef struct Nodo
{
	Elem r;
	struct Nodo *i;
	struct Nodo *d;
} *Arbin;

/*
	FUNCION: Inicializar
	RECIBE: Nada
	DESCRIPCION: Inicializa el arbol binario
	DEVUELVE: Un nodo NULL
*/
Arbin Inicializar (void){
	return NULL;
}

/*
	FUNCION: CrearNodo
	RECIBE: (Elem) contenido, (Arbin) hijo izquierdo, (Arbin) hijo derecho
	DESCRIPCION: Crea un nuevo nodo en el arbol
	DEVUELVE: Un nodo 
*/
Arbin CrearNodo(Elem r,Arbin i, Arbin d){
	Arbin t = (Arbin)malloc(sizeof(struct Nodo));
	t->r=r;
	t->i=i;
	t->d=d;
	return t;
}

/*
	FUNCION: ImpElem
	RECIBE: (Elem) un elemento
	DESCRIPCION:  Imprime el elemento dado
	DEVUELVE: Implicitamente, el valor del elemento
*/
void ImpElem (Elem e){
	printf("%d\n",e);
}

/*
	FUNCION: ObtenerValor
	RECIBE: (Arbin) Un nodo
	DESCRIPCION: Retorna el elemento que esta contenido en el nodo dado
	DEVUELVE: El elemento contenido en el nodo
*/
Elem ObtenerValor(Arbin a){
	return a->r;
}

/*
	FUNCION: HijoIzq
	RECIBE: (Arbin) Un nodo
	DESCRIPCION: Retorna el hijo izquierdo del nodo dado
	DEVUELVE: El hijo izquierdo del nodo
*/
Arbin HijoIzq (Arbin a){
	return a->i;
}

/*
	FUNCION: HijoDer
	RECIBE: (Arbin) Un nodo
	DESCRIPCION: Retorna el hijo derecho del nodo dado
	DEVUELVE: El hijo derecho del nodo
*/
Arbin HijoDer (Arbin a){
	return a->d;
}

/*
	FUNCION: ImpIn
	RECIBE: (Arbin) Un nodo
	DESCRIPCION: Imprime de manera InOrden el arbol binario dado
	DEVUELVE: Implicitamente, los valores almacenados en el arbol
*/
void ImpIn (Arbin a){
	if(a!=NULL){
		ImpIn(HijoIzq(a));
		ImpElem(ObtenerValor(a));
		ImpIn(HijoDer(a));
	}
}

/*
	FUNCION: Insertar
	RECIBE: (Elem) Un elemento, (Arbin) Un nodo contenedor del elemento
	DESCRIPCION: Crea un nuevo nodo en el arbol dado, con su respectivo
	hijo izquiero e hijo derecho.
	DEVUELVE: Un nuevo nodo con hijos y un elmento contenido
*/
Arbin Insertar(Elem e,Arbin d){
	if(d==NULL)
		return CrearNodo(e,Inicializar(),Inicializar());
	else if(e<ObtenerValor(d))
			return CrearNodo(ObtenerValor(d),Insertar(e,HijoIzq(d)),HijoDer(d));
		else
			return CrearNodo(ObtenerValor(d),HijoIzq(d),Insertar(e,HijoDer(d)));
}

/*
	FUNCION: BuscarElemento.
	RECIBE: (Elem) Un elemento, (Arbin) La raiz a un arbol binario.
	DESCRIPCION: Recorre el arbol binario dado en busca del elemento especificado.
		El recorrido se realiza en el subarbol derecho o izquierdo de la raiz,
		según se verifique el tamaño de elemento que contiene la raiz contra el 
		numero a buscar.
	DEVUELVE: TRUE en caso de encontrar el elemento, FALSE en caso de no encontrar nada.
	OBSERVACIONES: a DEBE SER DIFERENTE DE NULL.
*/
boolean BuscarElemento(Elem e, Arbin a){
	//Primero, comprobamos el valor que tenemos en el nodo a
	while(a!=NULL){//Mientras no encontremos una hoja
		if(e>(a->r)){ //Sigue buscando por la derecha
			a = a->d;
		}else if(e<(a->r)){ //Sigue buscando por la izquierda
			a = a->i;
		}else{//Lo encontro
			return 1;
		}
	}
}