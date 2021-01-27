//Estos arreglos son globales porque casi todas las funciones los utilizan.
var elements = [];
var new_data = [];
var coords = [];
var left_parts = [];
var right_parts = [];

/*
	RECIBE: subarreglo izquierdo (left) y subarreglo derecho (right)
	DEVUELVE: arreglo que contiene los elementos de ambos subarreglos, ordenados de menor a mayor
	DESCRIPCIÓN: Se compara cada elemento A del arreglo izquierdo con los B del arreglo derecho. Si A > B entonces 
		se agrega primero B al nuevo arreglo result. Finalmente se regresa result, que contiene todos los elementos 
		de ambos subarreglos, ordenados de menor a mayor.
*/
function merge(left, right){
	let result = []; 
	let i = 0; 
	let j = 0;
	while(i < left.length && j < right.length){			
		if(left[i] > right[j]) {
			result.push(right[j]);
			j++;
		} else {
			result.push(left[i]);
			i++;
		}
	}
	while(i < left.length){
		result.push(left[i]);
		i++;
	}
	while(j < right.length){
		result.push(right[j]);
		j++;
	}
	return result;
}
	
/*
	RECIBE: Un arreglo desordenado.
	DEVUELVE: Un nuevo arreglo con los elementos del original, ordenados de menor a mayor.
	DESCRIPCIÓN: De manera recursiva se divide en mitades hasta llegar al caso base, a partir del cual comienza a regresar
		los subarreglos ordenados de menor a mayor.
*/
function mergeSort(arr){
	if(arr.length <= 1) return arr;
	let halfPoint = Math.ceil(arr.length / 2);
	let firstHalf = mergeSort(arr.splice(0, halfPoint));
	let secondHalf = mergeSort(arr.splice(-halfPoint));
	left_parts.push(firstHalf);
	right_parts.push(secondHalf);
	return merge(firstHalf, secondHalf);
}

/*
	RECIBE: Tiempo (milisegundos) a esperar
	DEVUELVE: Una promise
	DESCRIPCIÓN: Permite detener la ejecución de una función asíncrona por un tiempo especificado.
*/
function sleep(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}

/*
	RECIBE: Nada
	DEVUELVE: Implícitamente crea los elementos especificados por el usuario y los agrega al div 'container'
	DESCIPCIÓN: Obtiene los valores ingresados por el usuario, por cada valor crea un div que será hijio del div 'container'
		dado que los elementos tienen posición fixed, es necesario calcular las coordenadas en las que serán acomodados. Dichas
		coordenadas son almacenadas en el arreglo coords para posteriormente utilizarlas en el proceso de animación.
*/
function createElements(){		
	
	elements = [];
	coords = [];
	const status = document.getElementById("status");// Limpia los los elemento de anteriores animaciones
	while (status.firstChild) {
		status.removeChild(status.lastChild);
	}
	const halfs = document.getElementById("halfs");
	while (halfs.firstChild) {
		halfs.removeChild(halfs.lastChild);
	}


	var values = document.getElementById('string-values').value;
	var container = document.getElementById('status');
	let x = 100;
	values.split(',').forEach(e => {
		elements.push(parseInt(e,10));
		x += 50;
		//Guardamos el número original y su posición original
		coords.push(x);
		//Creamos un nuevo div con el número adentro 
		var new_div = document.createElement('div');
		var new_content = document.createTextNode(e);
		new_div.id = e;
		new_div.classList.add("element");
		new_div.style.top = '150px';
		new_div.style.left = x + 'px';
		new_div.appendChild(new_content);
		container.appendChild(new_div);
	});

}

/*
	RECIBE: Un elemento del arreglo original (e), el arreglo objetivo (arr)
	DEVUELVE: Acomoda el elemento del arreglo original según su posición en el arreglo objetivo.
	DESCRIPCIÓN: Dado un elemento e, se obtiene su índice en el arreglo objetivo. El arreglo objetivo hace uso del arreglo
		de coordenadas, previamente calculado, para situar a e en el lugar que debe estar. Si el elemento e no existe, el acomodo
		se realiza de manera automática y el resto de los hijos que contiene el div 'halfs' actualizan su posición.
		Si el elemento ya está dentro de los hijos del div 'halfs', solamente hay que actualizar la posición de todos los hijos.
*/
function updateDiv(e,arr){
	let div = document.getElementById('halfs');
	let elm = document.getElementById(`half-${e}`);
	if(elm == null){//Si no existe agrégalo
		var new_div = document.createElement('div');
		var new_content = document.createTextNode(e);
		new_div.id = `half-${e}`;
		new_div.classList.add("element");
		new_div.style.top = '350px';
		new_div.style.left = `${coords[arr.indexOf(e)]}px`;
		new_div.appendChild(new_content);
		div.appendChild(new_div);
	}
	//Actualiza el div
	div.childNodes.forEach(n =>{
		let num = parseInt(n.textContent,10);
		n.style.left = `${coords[arr.indexOf(num)]}px`;
	});
	return;
}

/*
	RECIBE: Implícitamente recibe una serie de pasos que sigue el algoritmo. Dichos pasos los contienen los arreglos left_parts y right_parts
	DEVUELVE: Anima el proceso de merge-sort sobre los div contenidos en 'container', situando el resultado dentro del div 'halfs'
	DESCRIPCIÓN: Recorre cada elemento de las partes izquierdas y derechas de los pasos que ha segido merge-sort para ordenar los números
		por cada paso (tanto izquierdo como derecho) se desplazan los divs de arriba hacia abajo para identificar sobre qué subarreglo 
		se está actuando. Además, cambia el tono de las partes izquierdas y las derechas para identificarlas fácilmente.
		Para los cambios en el arreglo. Se toman cuatro estados del algoritmo como  importantes:
			1.- Cuando se tienen las dos mitades del arreglo original con sus correspondientes mitades ordenadas. (Cada cuarto del arreglo original está
				ordenado ascendentemente).
			2.- Cuando se tiene la mitad izquierda ordenada ascendentemente y la derecha por cuartos ordenados.
			3.- Cuando se tiene el arreglo ordenado ascendentemente por mitades.
			4.- Cuando se tiene el arreglo completamente ordenado ascendentemente (final).
		Esta función identifica de qué estado del algoritmo se trata para poder registrar los cambios sobre los divs que se encuentran en
		el div 'halfs', que muestra el resultado de los procesos merge llevados a cabo por el algoritmo de ordenamiento.
*/
async function animerge(){
	
	let long = left_parts.length;
	let m = Math.floor(long/2);
	/*Si  observamos nuestros arreglos de pasos y analizamos un poco, el primer estado se obtiene del paso realizado en 
		[m-1] y [long-2]. Por lo tanto, concatenamos los arreglos que se encuentran ahí en uno solo*/
	var leftAux = left_parts[m-1].concat(right_parts[m-1]);
	var rightAux = left_parts[long-2].concat(right_parts[long-2]);
	var algoStat = leftAux.concat(rightAux);
	var p = document.getElementById("descripcion");

	//Comanzamos a animar la mitad izquierda del arreglo completo
	for(let i = 0; i <= (m-1); i++){
		p.innerHTML = "Izquierda:  "+left_parts[i]+"  Derecha:  "+right_parts[i];
		//Pintamos y bajamos cada elemento de la parte izquirda
		left_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.backgroundColor = '#97CADB';
			my_div.style.transform = 'translateY(100px)';
		});
		//También de la derecha
		right_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.backgroundColor = '#01BABE';
			my_div.style.transform = 'translateY(100px)';
		});
		await sleep(2000);
		p.innerHTML = "Merge..."
		await sleep(1000);
		p.innerHTML= "Arreglo Resultante:  "+merge(left_parts[i],right_parts[i]);
		//Hacemos cambios
		if(i<(m/2)){//Ordenamos el primer cuarto del areglo
			left_parts[i].forEach(e=>{updateDiv(e,algoStat)});
			right_parts[i].forEach(e=>{updateDiv(e,algoStat)});
		}else if(i==(m-1)){ //Es momento de ordenar toda la mitad izquierda del arreglo completo
			left_parts[i].forEach(e=>{updateDiv(e,left_parts[long-1])});
			right_parts[i].forEach(e=>{updateDiv(e,left_parts[long-1])});
		}else{//Ordenamos el segundo cuarto del arreglo
			left_parts[i].forEach(e=>{updateDiv(e,algoStat)});
			right_parts[i].forEach(e=>{updateDiv(e,algoStat)});
		}

		//Terminamos los cambios, subimos el arreglo
		left_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.transform = 'translateY(0px)';
		});
		right_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.transform = 'translateY(0px)';
		});
		await sleep(2000);
	}

	//Cambiamos al segundo estado del algoritmo.
	algoStat = []; //Eliminamos el primero
	//El segundo estado es con mitad izquierda ordenada y la mitad derecha 'desordenada'
	algoStat = left_parts[long-1].concat(rightAux);

	//Comenzamos a animar la mitad derecha del arreglo completo
	for(let i = m; i <= (long-1); i++){
		p.innerHTML = "Izquierda:"+left_parts[i]+" Derecha:"+right_parts[i]+" Arreglo Resultante:"+merge(left_parts[i],right_parts[i]);
		// console.log(`i=${i}`);
		left_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.backgroundColor = '#97CADB';
			my_div.style.transform = 'translateY(100px)';
		});
		right_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.backgroundColor = '#01BABE';
			my_div.style.transform = 'translateY(100px)';
		});
		await sleep(2000);
		let a = (3*(m/2)); //Variable auxiliar para saber cuando llegamos a los 3/4 del arreglo.
		//Hacemos cambios
		if(i<a){
			left_parts[i].forEach(e=>{updateDiv(e,algoStat)});
			right_parts[i].forEach(e=>{updateDiv(e,algoStat)});
		}else if(i==long-2){//Hemos llegado al tercer estado, mitades ordenadas ascendentemente
			left_parts[i].forEach(e=>{updateDiv(e,left_parts[long-1].concat(right_parts[long-1]))});
			right_parts[i].forEach(e=>{updateDiv(e,left_parts[long-1].concat(right_parts[long-1]))});
		}else if(i==long-1){//Hemos llegado al paso final, el arreglo completamente ordenado
			left_parts[i].forEach(e=>{updateDiv(e,new_data)});
			right_parts[i].forEach(e=>{updateDiv(e,new_data)});
		}else{
			left_parts[i].forEach(e=>{updateDiv(e,algoStat)});
			right_parts[i].forEach(e=>{updateDiv(e,algoStat)});
		}
		//Terminamos los cambios, subimos el arreglo
		left_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.transform = 'translateY(0px)';
		});
		right_parts[i].forEach(e => {
			my_div = document.getElementById(e);
			my_div.style.transform = 'translateY(0px)';
		});
		await sleep(2000);
	}
	
}

function init(){
	//vacia los arreglos si es que ya se usaron
	
	new_data = [];
	left_parts = [];
	right_parts = [];
	new_data = mergeSort(elements);

	animerge();
	
}