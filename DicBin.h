#include "Arbin.h"
typedef Arbin DicBin;

DicBin InsOrdab (Elem e,DicBin d)
{
	if(esnuevoab(d))
		return consab(e,nuevoab(),nuevoab());
	else if(Menor(e,raiz(d)))
			return consab(raiz(d),InsOrdab(e,hijoi(d)),hijod(d));
		else
			return consab(raiz(d),hijoi(d),InsOrdab(e,hijod(d)));
}

int estaen (Elem e, DicBin a)
{
	if(esnuevoab(a))
		return 0;
	else
		if(Igual(e,raiz(a)))
			return 1;
		else
			if(Menor(e,raiz(a)))
				return estaen(e,hijoi(a));
			else
				return estaen(e,hijod(a));
}

Elem maxelem (DicBin a)
{
	if(esnuevoab(hijoi(a))&&esnuevoab(hijod(a)))
		return raiz(a);
	else 
		if(esnuevoab(hijod(a)))
			return raiz(a);
		else 
			return maxelem(hijod(a));
}

Elem minelem (DicBin a)
{
	if(esnuevoab(hijoi(a))&&esnuevoab(hijod(a)))
		return raiz(a);
	else
		if(esnuevoab(hijoi(a)))
			return raiz(a);
		else
			return minelem(hijoi(a));
}

DicBin BorraElem (Elem e, DicBin a)
{
	if(esnuevoab(hijoi(a))&&esnuevoab(hijod(a)))	
		return nuevoab();
	else
		if(Igual(e,raiz(a)))	
			if(!esnuevoab(hijoi(a))&&!esnuevoab(hijod(a)))
				return consab(maxelem(hijoi(a)),BorraElem((maxelem(hijoi(a))),hijoi(a)),hijod(a));
			else 
				if(esnuevoab(hijoi(a)))
					return hijod(a);
				else
					return hijoi(a);
		else
			if(Menor(e,raiz(a)))
				return consab(raiz(a),BorraElem(e,hijoi(a)),hijod(a));
			else
				return consab(raiz(a),hijoi(a),BorraElem(e,hijod(a)));
}


