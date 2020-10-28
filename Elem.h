typedef int Elem;

void ImpElem (Elem e)
{
	printf("%d\n",e);
}


Elem resta1Elem (Elem e)
{
	return e-1;
}

Elem suma1Elem (Elem e)
{
	return e+1;
}

int Menor(Elem e1, Elem e2)
{
	if(e1<e2)
		return 1;
	else
		return 0;
}

int Igual(Elem e1, Elem e2)
{
	if(e1==e2)
		return 1;
	else
		return 0;
}

int MayorOIgual (Elem e1, Elem e2)
{
	if(e1>=e2)
		return 1;
	else
		return 0;
}


