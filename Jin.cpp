#include <iostream>//libreria basica
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "Jin.h"

using namespace std;//espacio de nombre(namespace) std(estandar)

//////////////////Inicio de la clase usuario//////////////////////////////////////////////

Usuario::Usuario(){
	strcpy(nombre," ");
	color=0;
	personaje=rand()%9+0;
}

Usuario::Usuario(char nombre[],int color,int personaje){
	strcpy(this->nombre,nombre);
	this->color=color;
	this->personaje=personaje;
}

Usuario::~Usuario(){
	cout<<"Usuario destrido"<<endl;//muestra en pantalla
}

void Usuario::cargarDatos(){
	cin.sync();
	cout<<"Nombre: ";
	cin.getline(nombre,49);
	cout<<"los colores van de 0 a 15"<<endl;
	cout<<"color: ";
	cin>>color;
	cout<<"Personaje: ";
	cin>>personaje;
}

void Usuario::mostrarDatos(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Color: ";
	ordenarcolores(color);
	cout<<"Personaje: "<<personaje<<endl;
}

void Usuario::setnombre(char nombre[]){
	strcpy(this->nombre,nombre);
}

char* Usuario::getnombre(){
	return nombre;
} 

void Usuario::setcolor(int color){
	this->color=color;
}

int Usuario::getcolor(){
	return color;
}

void Usuario::setpersonaje(int personaje){
	this->personaje=personaje;
}

int Usuario::getpersonaje(){
	return personaje;
}

///////////////Final de la clase usuario///////////////////////////////////////////////////////////////

//-----------controles del jugador 1----------------
const int DERECHA=100;
const int IZQUIERDA=97;
const int ARRIBA=119;
const int ABAJO=115;
//---------------------------------------------------
//------------controles del jugador 2----------------
const int RIGHT=77;
const int LEFT=75;
const int UP=72;
const int DOWN=80;
//---------------------------------------------------
const int TIME=1000;
const int TIMEP=100;

/*void imprimir(Tablero matriz[][COL],int X,int Y,int FIL,int COL){
    int x=X,y=0;    
    
    cout<<("\n");
    //encuadre(I.carton);
    for(int i=0;i<FIL;i++){
        y=Y;
        for(int j=0;j<COL;j++){
            gotoxy(x,y);
            matriz[i][j].mostrarCuadro(i,j,x,y);//depende del mostrarDatos de la clase 
            y+=6;
        }
    x+=3;
    }
    //control();
}*/

int control(int restar()){
	cout<<"\n\n\t\t";
	if(GetAsyncKeyState(VK_SHIFT)){
        restar();
    }
    if(GetAsyncKeyState(VK_SPACE)){
		cin.get();
    }
	if(GetAsyncKeyState(VK_ESCAPE)){
		return 1;
    }
    if(GetAsyncKeyState(VK_TAB)){
	    exit(0);
    }
    system("cls");
}

void gotoxy(int y,int x){

    HANDLE Cons;
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    Cons = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Cons,Pos);
}

void escribir(){
	
	ofstream ave;
	string  nombre;
	ave.open("ave.txt",ios::out);//abriendo el archivo
//	ave.open(nombre.c_str(),ios::out);//abriendo el archivo
	if (ave.fail()){
		cout<<"error";
		exit(0);
	}
	else{
		cout<<"nombre: ";
		getline(cin,nombre);
		ave<<nombre;
		ave.close();//cerrar archivos 
	}
}

void lectura(){
	ifstream ave;
	ave.open("ave.txt");
}

void cronometro(){
	
	int i=1000;
	
	for(int x=0; x<24; x++) {
		for(int y=0; y<=59; y++) {
			for(int z=0; z<=59; z++) {
				printf("Game over %02d:%02d:%02d\r",x,y,z);
				Sleep(i);
			}
		}
	}
	exit(0);
}

int ave(){
	int FIL=16,COL=18,x=0,y=0;
	int vec[2][6]={
		{177,4,179,16,219,178},
		{ 11,8, 14,14, 15, 11},
	};
	int ave0[FIL][COLPE]= {
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',177,177,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',177,178,178,178,177,' ',' ',' '},
		{' ',177,177,177,177,177,' ',' ',' ',177,178,178,' ',' ',' ',177,' ',' '},
		{' ',177,178,178,178,178,177,177,' ',177,178,178,' ', 4 ,' ',177,' ',' '}, 
		{' ',177,178,178,178,178,178,177,177,178,178,178,' ',' ',' ',179, 16,219},
		{' ',' ',177,178,178,178,178,177,178,178,178,178,' ',' ',177,' ',' ',' '},
		{' ',' ',' ',177,178,178,177,177,178,178,178,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',177,177,177,177,178,178,178,178,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',177,178,178,178,178,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',177,178,178,178,178,178,178,177,' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',177,178,178,177,177,177,177,' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',177,177,' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	}; 					  
	int ave1[FIL][COLPE]={
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
 		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',177,177,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',177,178,178,178,177,' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',177,178,178,' ',' ',' ',177,' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',177,178,178,' ', 4 ,' ',177,' ',' '}, 
		{' ',' ',' ',' ',' ',' ',' ',' ',177,178,178,178,' ',' ',' ',179, 16,219},
		{' ',' ',' ',' ',' ',' ',' ',177,177,177,178,178,' ',' ',177,' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',177,178,178,178,177,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',177,178,178,178,178,177,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',177,178,178,178,177,178,178,178,177,' ',' ',' ',' '},
		{' ',' ',' ',' ',177,178,178,178,178,177,178,178,177,' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',177,178,178,178,177,177,177,177,' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',177,178,178,177,' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',177,177,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
	do{
		system("cls");
		imprimirpersonajes(ave0,x,y,FIL,COL,vec);
		Sleep(TIMEP);
		system("cls");
		imprimirpersonajes(ave1,x,y,FIL,COL,vec);
		Sleep(TIMEP);
		
	/*	if(a==0){
			
		}else{
			if(a==1){
			}
		}*/
		movimiento0(&x,&y);	
	}while(x!='0');
}

pacman(){
	int FIL=11,COL=12,x=0,y=0;
	int vec[2][COLTO]={
		{176,178},
		{  9, 14},
	};
	int pacman1[FIL][COLPE]= {
		{' ',' ',' ',176,176,176,176,176,' ',' '},
		{' ',' ',176,178,178,178,178,178,176,' '},
		{' ',176,178,178,178,176,178,178,178,176},
		{176,178,178,178,178,178,178,178,176,' '},
		{176,178,178,178,178,178,178,176,' ',' '},
		{176,178,178,178,178,178,176,' ',' ',' '},
		{176,178,178,178,178,178,178,176,' ',' '},
		{176,178,178,178,178,178,178,178,176,' '},
		{' ',176,178,178,178,178,178,178,178,176},
		{' ',' ',176,178,178,178,178,178,176,' '},
		{' ',' ',' ',176,176,176,176,176,' ',' '},
	}; 		  
	int pacman2[FIL][COLPE]= {
		{' ',' ',' ',176,176,176,176,176,' ',' '},
		{' ',' ',176,178,178,178,178,178,176,' '},
		{' ',176,178,178,178,176,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,176,176,176,' '},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{' ',176,178,178,178,178,178,178,178,176},
		{' ',' ',176,178,178,178,178,178,176,' '},
		{' ',' ',' ',176,176,176,176,176,' ',' '},
	};				  
	int pacman3[FIL][COL]= {
		{' ',' ',176,176,176,176,176,' ',' ',' '},
		{' ',176,178,178,178,178,178,176,' ',' '},
		{176,178,178,178,176,178,178,178,176,' '},
		{' ',176,178,178,178,178,178,178,178,176},
		{' ',' ',176,178,178,178,178,178,178,176},
		{' ',' ',' ',176,178,178,178,178,178,176},
		{' ',' ',176,178,178,178,178,178,178,176},
		{' ',176,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,176,' '},
		{' ',176,178,178,178,178,178,176,' ',' '},
		{' ',' ',176,176,176,176,176,' ',' ',' '},
	};					  
	int pacman4[FIL][COL]= {
		{' ',' ',176,176,176,176,176,' ',' ',' '},
		{' ',176,178,178,178,178,178,176,' ',' '},
		{176,178,178,178,176,178,178,178,176,' '},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{' ',176,176,176,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,178,176},
		{176,178,178,178,178,178,178,178,176,' '},
		{' ',176,178,178,178,178,178,176,' ',' '},
		{' ',' ',176,176,176,176,176,' ',' ',' '}, 
	};					  
	int bol[FIL][COL]= {
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',178,178,' ',' ',' ',' '},
		{' ',' ',' ',178,178,178,178,' ',' ',' '},
		{' ',' ',' ',178,178,178,178,' ',' ',' '},
		{' ',' ',' ',178,178,178,178,' ',' ',' '},
		{' ',' ',' ',' ',178,178,' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
	do{
		system("cls");
		imprimirpersonajes(pacman1,x,y,FIL,COL,vec);
		Sleep(TIMEP);
		system("cls");
		imprimirpersonajes(pacman2,x,y,FIL,COL,vec);
		Sleep(TIMEP);
		
	/*	if(a==0){
			
		}else{
			if(a==1){
			}
		}*/
		movimiento0(&x,&y);	
	}while(x!='0');
}

void movimiento0(int *X,int *Y){
	
	char tecla=0;
	if(kbhit()){
		cin.sync();
		tecla=getch();
	}
	switch(tecla){
		default:
			int b=control(ave);
			if(b==1){
				system("cls");
				*X='0';
			}
			if(*Y<72){	
				*Y+=6;
			}
			else{
				*X='0';
			}
		break;
	}	
}

void movimiento1(int matriz[][COL],int *X,int *Y){
/*//----------controles----------------------------------------------------------------------------------------
	char tecla=0;
	if(kbhit()){//movimiento de jugador 1
			cin.sync();
			tecla=getch();
		if(tecla==ARRIBA||tecla==ABAJO||tecla==IZQUIERDA||tecla==DERECHA){
//----------ARRIBA jugador 1---------------------------------------------------------------------------------			
			if(tecla==ARRIBA){
				if(matriz[*X-1][*Y] == 32){					
					matriz[*X][*Y] = 32;
					cf=*X;
					*X-=1;
					cc=*Y;
					direccion=2;
					//if(direccion == 2){//arriba
					matriz[cf+x][cc]=matriz[cf][cc];
				}
				else{
					if(direccion == 3 && matriz[*X-1][*Y] == 111 && matriz[*X+1][*Y] == 32){
						cf=*X;
						*X+=1;
						cc=*Y;
					}
					else{
						if(matriz[sf-1][sc] == 42){
							*X-=1;
							rf=0;
							puntos++;
						}
						else{
							cronometro();
						}
					}
					
				}
			}
//---------ABAJO jugador 1-----------------------------------------------------------------------------------------------
 			if(tecla==ABAJO){
 				if(matriz[*X+1][*Y] == 32){
	 				matriz[*X][*Y] = 32;
	 				cf=*X;
					*X+=1;
					cc=*Y;
					direccion=3;
				}
				else{
					if(direccion == 2 && matriz[*X+1][*Y] == 111 && matriz[*X-1][*Y] == 32){
						cf=*X;
						*X-=1;
						cc=*Y;
					}
					else{
						if(matriz[*X+1][*Y] == 42){
							*x+=1;
							rf=0;
							puntos++;
						}
						else{
							cronometro();
						}
					}
					
				}
			}
//----------IZQUIERDA	 jugador 1-----------------------------------------------------------------------------------------		
			if(tecla==IZQUIERDA){
				if(matriz[*X][*Y-1] == 32){
	 					matriz[*X][*Y] = 32;
	 					cc=*Y;
						*Y-=1;
						cf=*X;
						direccion=1;
				}
				else{
					if(direccion==0 && matriz[*X][*Y-1] == 111 && matriz[*X][*Y+1] == 32){
						cc=*Y;
						*Y++;
						cf=*X;
					}
					else{
						if(matriz[*X][*Y-1] == 42){
							*Y--;
							rf=0;
							puntos++;
						}
						else{
							cronometro();
						}
					}
				}
			}
//----------DERECHA jugador 1-----------------------------------------------------------------------------------------------
 			if(tecla==DERECHA){
 				if(matriz[*X][*Y+1] == 32){
	 					matriz[*X][*Y] = 32;
	 					cc=*Y;
						*Y++;
						cf=*X;
						direccion=0;
						//if(direccion == 0 ){//derecha
						pmatriz[cf][cc-x]=matriz[cf][cc];						
				}
				else{
					if(direccion==1 && matriz[*X][*Y+1] == 111 && matriz[*X][*Y-1] == 32){
						cc=*Y;
						*Y--;
						cf=*X;
					}
					else{
						if(matriz[*X][*Y+1] == 42){
							*Y++;
							rf=0;
							puntos++;
						}
						else{
							cronometro();
						}
					}
				}
			}
		}
	}*/
}

void movimiento2(int matriz[][COL],int *X,int *Y){//ubicacion del muñeco 2
	char tecla=0;
	cin.sync();
//----------arriba jugador 2--------------------------------------------------------------------------------------------
	if(GetAsyncKeyState(VK_UP) ||	tecla==UP ){
		tecla=UP;
		if(matriz[*X-1][*Y] == 32){
			matriz[*X][*Y] = 32;
			*X-=1;
		}
		else{
			cronometro();
		}
	}
//----------abajo jugador 2---------------------------------------------------------------------------------------------			
	if(GetAsyncKeyState(VK_DOWN) || tecla==DOWN ){
		tecla=DOWN;
 		if(matriz[*X+1][*Y] == 32){
	 		matriz[*X][*Y] = 32;
			*X+=1;
		}
		else{
			cronometro();
		}
	}
//----------izquierda jugador 2--------------------------------------------------------------------------------------------
	if(GetAsyncKeyState(VK_LEFT) || tecla==LEFT ){
		tecla=LEFT;
		if(matriz[*X][*Y-1] == 32){
	 		matriz[*X][*Y] = 32;
			*Y-=1;
		}
		else{
			cronometro();
		}
	}
//----------derecha jugador 2--------------------------------------------------------------------------------------------
	if(GetAsyncKeyState(VK_RIGHT) || tecla==RIGHT ){
		tecla=RIGHT;
 		if(matriz[*X][*Y+1] == 32){
	 		matriz[*X][*Y] = 32;
			*Y+=1;
		}
		else{
			cronometro();
		}
	}
}

void imprimirpersonajes(int matriz[][COLPE],int X,int Y,int FIL,int COL,int vec[][COLTO]){
	
	for(int i=0,x=X;i<FIL;i++){
		for(int j=0,y=Y;j<COL;j++){
			for(int k=0;k<6;k++){
				if(matriz[i][j]==vec[0][k]){
					int l=vec[1][k];
					tono(l);
				}
			}
			gotoxy(x,y);	
			cout<<char(matriz[i][j]);
			y++;
		}
		x++;
	}
}

void tono(int color){
	
	int p=color;
	int tono[255] = {
		0x00128, //0  Negro             
    	0x001, //1  Azul              
    	0x002, //2  Verde             
    	0x003, //3  Aguamarina        
      	0x004, //4  Rojo              
     	0x005, //5  Purpura           
    	0x006, //6  Amarillo          
		0x007, //7  Blanco            
		0x008, //8  Gris              
		0x009, //9  Azul Claro        
    	0x00A, //10 Verde Claro       
    	0x00B, //11 Aguamarina Claro  
    	0x00C, //12 Rojo Claro        
    	0x00D, //13 Purpura Claro     
		0x00E, //14 Amarillo Claro    
    	0x00F, //15 Blanco Brillante  
   	};
	for(int i=0;i<255;i++){
		tono[i]=i;	
	}
   	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),tono[p]); 
}

void ordenarcolores(int color){
	
	switch (color){
		case 0:
			cout<<"Negro"<<endl;
		break;
		case 1:
			cout<<"Azul"<<endl;
		break;
		case 2:
			cout<<"Verde"<<endl;
		break;
		case 3:
			cout<<"Aguamarina"<<endl;
		break;
		case 4:
			cout<<"Rojo"<<endl;
		break;
		case 5:
			cout<<"Purpura"<<endl;
		break;
		case 6:
			cout<<"Amarillo"<<endl;
		break;
		case 7:
			cout<<"Blanco"<<endl;
		break;
		case 8:
			cout<<"Gris"<<endl;
		break;
		case 9:
			cout<<"Azul claro"<<endl;
		break;
		case 10:
			cout<<"Verde claro"<<endl;
		break;
		case 11:
			cout<<"Aguamarina claro"<<endl;
		break;
		case 12:
			cout<<"Rojo claro"<<endl;
		break;
		case 13:
			cout<<"Purpura claro"<<endl;
		break;
		case 14:
      		cout<<"Amarillo claro"<<endl;
		break; 
		case 15:
			cout<<"Blanco claro"<<endl;     
		break;
	};
}

int cuenta(int x) {
	int i=0; 
	
	for(int v[100];x!=0; i++) {
		v[i]=x%10;
		x/=10;
	}
	i--;
	return i;
}

void burbuja(int *x,int *y){
	
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}

int factorial(int x) {
	int j=1;
	for(int i=1; i<=x; i++) {
		j*=i;
	}
	return j;
}

void primo(int x) { 

	for(int i=2; i<x; i++) {
		if(x%i==0) {
			cout<<"El numero "<<x<<" es primo"<<endl;
		}
	}
}

void ordenar(int x[]){
	
	for(int i=0,aux=0; i<10; i++) {
		for(int j=i; j<10; j++) {
			if(x[i]<x[j]) {//para cambiar de menor a mayor solo cambia el signo a >
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
			}
		}
	}
}
