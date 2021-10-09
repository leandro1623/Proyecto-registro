class Registro{
	public://------------------------------------------public-------------------------------------------------------
		Registro();//constructor1
		void get_nombre_archivo();//retorna el nombre del archivo
		bool set_nombre_archivo(char _nombre_archivo[]);//establecer nombre del archivo
		void registrar_persona(std::string _nombre,std::string _primer_apellido,std::string _segundo_apellido,int _edad,std::string _numero_de_telefono,std::string _cedula);//registra una persona
		void ver_datos_de_ultima_persona_registrada();//muestra los datos del la persona
		bool mostrar_archivo();//muestra el archivo
		void buscar_nombre_en_archivo(std::string _nombre);//busca una persona en el registro
		void eliminar_archivo();//elimina un archivo
		void eliminar_persona_del_archivo(std::string _nombre);//elimina los datos de una persona en el archivo
		void renombrar_archivo(char _nombre[]);//cambia el nombre del archivo
		bool crear_archivo();//crea un archivo .txt
		~Registro(){};//destructor
	//--------------------------------------------fin public---------------------------------------------------------
		private://----------------------------------------private----------------------------------------------------
	//funciones privadas
		void guardar_en_archivo();//creando y guardando archivo
	//fin funciones privadas
	//variables	privadas
		std::string nombre,primer_apellido,segundo_apellido,cedula,numero_de_telefono;
		int edad;
		char nombre_archivo[];
	//fin variables privadas
	//---------------------------------------------------fin private-------------------------------------------------
};