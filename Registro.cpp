#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"Registro.h"
using namespace std;

//funciones privadas

void Registro::guardar_en_archivo(){//creando y guardando archivo					-guardar_en_archivo
	std::ofstream archivo;
	archivo.open(nombre_archivo,std::ios::app);//creando archivo------*
	if(archivo.fail()){
		std::cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	archivo<<nombre<<"\n"<<primer_apellido<<"\n"<<segundo_apellido<<"\n"<<edad<<"\n"<<numero_de_telefono<<"\n"<<cedula<<"\n";
	archivo.close();
}

bool Registro::crear_archivo(){;//crea un archivo .txt
	std::ofstream archivo(nombre_archivo,std::ios::out);
	if(archivo.fail()){std::cerr<<"No se pudo abrir el archivo";return (archivo.good())? true:false; exit(1);}
	archivo.close();
}

//fin funciones privadas

Registro::Registro(){//constructor1
	nombre="\0";
	primer_apellido="\0";
	segundo_apellido="\0";
	cedula="\0";
	numero_de_telefono="\0";
	edad=0;
	
}

//establecer nombre del archivo
bool Registro::set_nombre_archivo(char _nombre_archivo[]){//establecer nombre del archivo
	for(int i=0;i<strlen(_nombre_archivo);i++){
		nombre_archivo[i]=_nombre_archivo[i];//												+set_nombre_archivo
	}
	
	std::ifstream archivo;
	archivo.open(nombre_archivo,std::ios::in);
	if(archivo.fail()){
		return false;
	}
	else{
		return true;
	}
	archivo.close();
}

void Registro::registrar_persona(std::string _nombre,std::string _primer_apellido,std::string _segundo_apellido,int _edad,std::string _numero_de_telefono,std::string _cedula){//registra una persona
	nombre=_nombre;//nombre 
	primer_apellido=_primer_apellido;
	segundo_apellido=_segundo_apellido;									// +registrar_persona
	cedula=_cedula;//cedula
	numero_de_telefono=_numero_de_telefono;//telefono \ celular
	edad=_edad;//edad
	guardar_en_archivo();//guardadndo en el archivo
}

void Registro::ver_datos_de_ultima_persona_registrada(){//muestra los datos del la persona
	std::cout<<"Datos guardados en el archivo: "<<nombre_archivo;
	std::cout<<"\nNombre completo: "<<nombre<<"\nPrimer apellido: "<<primer_apellido;
	std::cout<<"\nSegundo apellido: "<<segundo_apellido;
	std::cout<<"\nCedula: "<<cedula;
	std::cout<<"\nNumero de telefono: "<<numero_de_telefono<<"\nEdad: "<<edad<<"\n";
}

bool Registro::mostrar_archivo(){//muestra el archivo								+mostrar_archivo
	std::string nombre,nombretemp,primer_apellido,segundo_apellido,apellido,edad,numero,cedula;//variables
	std::ifstream archivo;
	archivo.open(nombre_archivo,std::ios::in);//abriendo archivo
	if(archivo.fail()){
		return false;
	}

	while(!archivo.eof()){
		archivo>>nombre>>primer_apellido>>segundo_apellido>>edad>>numero>>cedula;
		if(nombretemp == nombre){
			continue;
		}
		else{
			std::cout<<"Nombre: "<<nombre<<"\nApellidos: "<<primer_apellido<<" "<<segundo_apellido<<"\nEdad: "<<edad<<"\nNumero: "<<numero<<"\nCedula: "<<cedula<<"\n\n----------------\n";
		}
		nombretemp=nombre;
	}
	return true;	
	archivo.close();
}

void Registro::buscar_nombre_en_archivo(std::string _nombre){//busca una persona en el registro        +buscar_nombre_en_archivo
	std::string nombre,primer_apellido,segundo_apellido,edad,numero,cedula;
	bool band=false;
	std::ifstream archivo;
	archivo.open(nombre_archivo,std::ios::in);//abriendo archivo
	if(archivo.fail()){
		return;
	}
	
	while(!archivo.eof()){//while
		archivo>>nombre>>primer_apellido>>segundo_apellido>>edad>>numero>>cedula;
		if(nombre==_nombre){
			band=true;
			if(band==true){
				std::cout<<"\nLa persona que busca se encuentra registrada con los datos: \n\n";
				std::cout<<"Nombre: "<<nombre<<"\nApellidos: "<<primer_apellido<<" "<<segundo_apellido<<"\nEdad: "<<edad<<"\nNumero: "<<numero<<"\nCedula: "<<cedula<<"\n\n----------------\n";
				break;
			}
		}
		
	}//fin while
	
	if(band==false){
		std::cout<<"\nLa persona que busca no se encuentra registrada\n";
	}
}

void Registro::eliminar_archivo(){//eliminar archivo           +eliminar_archivo
	remove(nombre_archivo);
}

void Registro::eliminar_persona_del_archivo(std::string _nombre){//eliminar persona
	std::string nombre,nombretemp,primer_apellido,segundo_apellido,numero,cedula,nombre_archivo2="temp2.txt";
	int edad;
	std::ifstream archivo;//old archivo
	std::ofstream archivo2;//new archivo
	archivo.open(nombre_archivo,std::ios::in);//abriendo archivo 1
	archivo2.open(nombre_archivo2,std::ios::out);//abriendo archivo 2
	if(archivo.fail() || archivo2.fail()){
		return;
	}
	
	while(!archivo.eof()){//while
		archivo>>nombre>>primer_apellido>>segundo_apellido>>edad>>numero>>cedula;
		if(nombre==_nombre || nombretemp==nombre){
			continue;
		}
		else{
			archivo2<<nombre<<"\n"<<primer_apellido<<"\n"<<segundo_apellido<<"\n"<<edad<<"\n"<<numero<<"\n"<<cedula<<"\n";
		}
		nombretemp=nombre;
	}
	archivo.close();
	archivo2.close();
	remove(nombre_archivo);
	rename("temp2.txt",nombre_archivo);
	remove("temp2.txt");
}

void Registro::renombrar_archivo(char _nombre[]){
	rename(nombre_archivo,_nombre);//renombrando
	for(int i=0;i<strlen(_nombre);i++){//cambiando el nombre a la variable del objeto
		nombre_archivo[i]=_nombre[i];
	}
}

void Registro::get_nombre_archivo(){//retorna el nombre del archivo
	for(int i=0;i<strlen(nombre_archivo);i++){
		std:cout<<nombre_archivo[i];
	}
}



