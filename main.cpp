#include <iostream>
#include<string>
#include<cstdlib>
#include"Registro.h"
									//proyecto sin terminar
 //prototipos de funcion
 void menu();//menu principal
 bool crear_abrir();
 
 //variables globales
 Registro registro;//objeto de Registro global
 
int main() {//main
	system("color 70");//dando color a la consola de fondo blanco con letras negras
	char x;
	bool band;
	do{
		system("cls");
		band=crear_abrir();
		if(band==true){
			system("cls");
			menu();
		}
		else if(band==false){
			std::cerr<<"\nEl archivo no existe\n\n";
			system("pause");
		}
		
	}while(1);
	
	registro.~Registro();//destruyendo el objeto 'registro' de la clase 'Registro'
	return 0;
}//fin main

void menu(){//menu principal
	
	char *opc=new char;
	char nombre[20],primer_apellido[99],segundo_apellido[99],cedula[20],numero_de_telefono[20];
	int edad;
	char *nombre_archivo=new char[99];
	
	do{
		std::cout<<"\nEl archivo abierto actualmete es: ";registro.get_nombre_archivo();//muestra el nombre del archivo
		std::cout<<"\n\nMenu del archivo\n";
		std::cout<<"\n1. registrar una persona";
		std::cout<<"\n2. buscar una persona";
		std::cout<<"\n3. ver datos de la ultima persona registrada";
		std::cout<<"\n4. eliminar una persona";
		std::cout<<"\n5. cambiar nombre del archivo";
		std::cout<<"\n6. mostrar archivo";
		std::cout<<"\n7. eliminar el archivo";
		std::cout<<"\n8. Cerrar archivo";
		std::cout<<"\nOpcion: ";std::cin>>opc;
		std::cout<<"\n\n";
		
		switch(*opc){
			case '1'://            1
				fflush(stdin);//limpiando buffer
				std::cout<<"\nDigite los datos de la persona\n";
				std::cout<<"\nNombre: ";std::cin.getline(nombre,20,'\n');//nombre
				std::cout<<"\nPrimer apellido *~Sin espacios en lugar de espacios ponga '_' ejemplo: 'de_la_rosa'~*: ";std::cin.getline(primer_apellido,10,'\n');//primer apellido
				fflush(stdin);//limpiando buffer
				std::cout<<"\nSegundo apellido *~Sin espacios en lugar de espacios ponga '_' ejemplo: 'de_la_rosa'~*\n(si no tiene digite una x): ";std::cin.getline(segundo_apellido,10,'\n');//segu. apellido
				std::cout<<"\nEdad: ";std::cin>>edad;//edad
				fflush(stdin);//limpiando buffer
				if(edad>17){//si es mayor de edad
					std::cout<<"\nNumero de cedula: ";std::cin.getline(cedula,15,'\n');//pide su numero de cedula
				}
				else{//si no es mayor de edad
					strcpy(cedula,"Es_menor_de_edad");//llena el campo de cedula con 'no tiene'
				}
				std::cout<<"\nNumero de telefono (si no tiene digite una x): ";std::cin.getline(numero_de_telefono,15,'\n');//numero de telefono
				if(segundo_apellido[0]=='x' || segundo_apellido[0]=='X'){//si no tiene segundo apellido
					strcpy(segundo_apellido,".");//llena el campo de segu. apellido con 'no tiene'
				}
				if(numero_de_telefono[0]=='x' || numero_de_telefono[0]=='X'){
					strcpy(numero_de_telefono,"no_tiene");
				}
				registro.registrar_persona(nombre,primer_apellido,segundo_apellido,edad,numero_de_telefono,cedula);
				break;
			case '2'://                      2
				fflush(stdin);//limpiando buffer
				std::cout<<"Digite el nombre a buscar: ";std::cin.getline(nombre,20,'\n');
				registro.buscar_nombre_en_archivo(nombre);
				break;
			case '3':
				registro.ver_datos_de_ultima_persona_registrada();
				break;
			case '4':
				fflush(stdin);//limpiando buffer
				std::cout<<"\nDigite el nombre: ";std::cin.getline(nombre,20,'\n');
				registro.eliminar_persona_del_archivo(nombre);
				break;
			case '5':
				fflush(stdin);//limpiando buffer
				std::cout<<"\nDigite el nuevo nombre, \n(con la misma direccion si no pone una direccion diferente el archivo se mover a esa direccion): ";std::cin.getline(nombre,20,'\n');
				registro.renombrar_archivo(nombre);
				break;
			case '6':
				if(registro.mostrar_archivo()==false){
					std::cerr<<"\nEl archivo no existe\n";
				}
				break;
			case '7':
				fflush(stdin);//limpiando buffer
				registro.eliminar_archivo();
				*opc='8';
				break;
			case '8': return; break;
			default:std::cerr<<"OPCION INVALIDA";break;
		}
		system("pause");
		system("cls");
	}while(*opc!='8');
	
}

bool crear_abrir(){
	char opc;
	std::cout<<"\n\t\t\tMenu principal\n";
	std::cerr<<"\n1. Crear un registro | 2. Abrir un registro | 3. Salir: ";std::cin>>opc;
	fflush(stdin);
	
	if(opc=='1'){
		char nombre[999];
		std::cout<<"\nDigite la direcion donde lo desea crear ejemplo(c://users//Public//Desktop//nombre del archivo.txt),\n si solo pone el nombre del archivo se creara en la misma direcion que se encuentra la aplicacion: ";std::cin.getline(nombre,999,'\n');
		registro.set_nombre_archivo(nombre);
		registro.crear_archivo();
		return true;
	}
	else if(opc=='2'){
		char nm[999];
		std::cout<<"\nDigite la direccion del archivo ejemplo(c://users//Public//Desktop//nombre del archivo.txt): ";std::cin.getline(nm,999,'\n');
		if(registro.set_nombre_archivo(nm)){
			return true;
		}
		else{
			return false;
		}
	}
	else if(opc=='3'){
		exit(1);
	}
	else{
		std::cerr<<"OPCION INVALIDA\n\n";
	}
}