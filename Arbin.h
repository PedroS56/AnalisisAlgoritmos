typedef struct NodoAB
{
	Elem r;
	struct NodoAB *i;
	struct NodoAB *d;
} *Arbin;

Arbin nuevoab (void)
{
	return NULL;
}

Arbin consab(Elem r,Arbin i, Arbin d)
{
	Arbin t = (Arbin)malloc(sizeof(struct NodoAB));
	t->r=r;
	t->i=i;
	t->d=d;
	return t;
}

int esnuevoab (Arbin a)
{
	return a==NULL;
}

Elem raiz (Arbin a)
{
	return a->r;
}

Arbin hijoi (Arbin a)
{
	return a->i;
}

Arbin hijod (Arbin a)
{
	return a->d;
}

void ImpIn (Arbin a)
{
	if(!esnuevoab(a))
	{
		ImpIn(hijoi(a));
		ImpElem(raiz(a));
		ImpIn(hijod(a));
	}
}

int maximo (int a1, int a2)
{
	if(a1>=a2)
		return a1;
	else
		return a2;
		
}

int altura (Arbin a)
{
	if(esnuevoab(a))
		return 0;
	else
		return 1+maximo(altura(hijoi(a)),altura(hijod(a)));
}

int NumNodos (Arbin a)
{
	if(esnuevoab(a))
		return 0;
	else
		return 1+NumNodos(hijoi(a))+NumNodos(hijod(a));
}

void ImpNivelN (Arbin a, int nivel)
{
	if(esnuevoab(a))
		return;
	if(nivel==1)
		ImpElem(raiz(a));	
	else 
		if(nivel>1)
		{
			ImpNivelN(hijoi(a),nivel-1);
			ImpNivelN(hijod(a),nivel-1);
		}
}

void ImpArbin (Arbin a)
{
	int h = altura(a);
	int hx = h-1;
	int i,j;
	for(i=1; i<=h; i++)
	{
		ImpNivelN(a,i);
		printf("\n");
	}
}


int Eslleno (Arbin a)
{
	if(esnuevoab(a))
		return 1;
	else
		if(altura(hijoi(a))==altura(hijod(a))&&Eslleno(hijoi(a))&&Eslleno(hijod(a)))
			return 1;
		else
			return 0;
		
}

int EsCompleto (Arbin a)
{
	if(esnuevoab(a))
		return 1;
	else
		if(altura(hijoi(a))==altura(hijod(a)))
			if(Eslleno(hijoi(a))&&EsCompleto(hijod(a)))
				return 1;
			else
				return 0;
		else
			if((altura(hijoi(a))-altura(hijod(a)))>=0&&(altura(hijoi(a))-altura(hijod(a)))<=1)
				return EsCompleto(hijoi(a))&&Eslleno(hijod(a));
}

Arbin consCompleto (Elem e, Arbin a)
{
	if(esnuevoab(a))
		return consab(e,nuevoab(),nuevoab());
	else
		if(Eslleno(a)||!Eslleno(hijoi(a)))	
			return consab(raiz(a),consCompleto(e,hijoi(a)),hijod(a));
		else
			return consab(raiz(a),hijoi(a),consCompleto(e,hijod(a)));
}

int esHoja (Arbin a)
{
	if(esnuevoab(hijod(a))&&esnuevoab(hijoi(a)))
		return 1;
	else
		return 0;
}

Elem masDerecho(Arbin a)
{
	if(esHoja(a))
		return raiz(a);
	else
		if(altura(hijoi(a))==altura(hijod(a)))
			return masDerecho(hijod(a));
		else
			return masDerecho(hijoi(a));
}