#ifndef JinH
#define JinH

#ifndef UsuarioH
#define UsuarioH

class Usuario{
	private:
		char nombre[50];
		int color; 
		int personaje;
	public:
		Usuario();
		Usuario(char nombre[],int color,int personaje);
		~Usuario();
		void cargarDatos();
		void mostrarDatos();
		void setnombre( char nombre[]);
		char * getnombre();
		void setcolor(int color);
		int getcolor();
		void setpersonaje(int personaje);
		int getpersonaje();
};
#endif

const int COL=8;
const int COLPE=18;
const int COLTO=6;	
/*	void imprimir(Tablero matriz[][COL],int X,int Y,int FIL,int COL);//cambiar Tablero por la clase*/
	int control(int restar());//controles
	void gotoxy(int x, int y);//ubica las cosas en la pantalla
	void cronometro();//un cronometro
	int ave();//personajes0 ave 
	int pacman();//personaje pacman 
	void movimiento0(int *X,int *Y);//movimiento estatico enviar la direccion en pantalla &X,&Y
	void movimiento1(int matriz[][COL],int *X,int *Y);//movimiento de teclado izquierdo enviar la direccion en pantalla &X,&Y
	void movimiento2(int matriz[][COL],int *X,int *Y);//movimiento de teclado derecho enviar la direccion en pantalla &X,&Y
	void imprimirpersonajes(int matriz[][COLPE],int X,int Y,int FIL,int COL,int vec[][COLTO]);//solo para personajes 
	void tono(int color);//pinta un mensaje
	void ordenarcolores(int color);//muestra el numero de color que estes usando
	int cuenta(int x);//cuenta los digitos 
	void burbuja(int &x,int &y);//metodo de la burbuja
	int factorial(int x);//calcula la factorial de un numero
	void primo(int x);//calcula un numero primo
	void ordenar(int x[]);//ordena los numero de mayor a menos o alreves para enviar el vector es ordenar(x);
	
#endif
