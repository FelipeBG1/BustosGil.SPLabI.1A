#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED
/** \brief Recorre la cadena validando que cada posicion sea una letra
     *
     * \param Cadena a cargar la letra validada
     * \return Retorna 0 si logra validar, o -1 si no
     *
     */
     int isLetras(char*pAux);

    /** \brief Valida que el usuario ingrese una cadena de caracteres.
     *
     * \param Puntero a variable char en la que cargar la cadena validada.
     * \param Limite de caracteres a ingresar
     * \param Numero de reintentos
     * \param Mensaje a mostrar
     * \param Mensaje de error
     * \return 0 si tuvo exito, y -1 si no.
     *
     */
     int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);


    /** \brief  Obtiene una cadena mediante getCadena y valida mediante isFLoat. Pasa la cadena validada a flotante.
     *
     * \param Puntero a flotante donde escribir el resultado de la validacion.
     * \return Retorna 0 si tuvo exito, -1 si no.
     *
     */
     int getFloat(float*pAux);


    /** \brief Recorre la cadena validando que cada posicion sea un numero (0 - 9)
     *
     * \param Cadena a cargar el numero validado
     * \return Retorna 0 si logra validar, o -1 si no.
     *
     */
     int isInt(char *pAux);


   /** \brief pide un valor entero y valida el ingreso
    *
    * \param	puntero a entero en donde se va a guardar el dato
    * \param	reintentos que se le dan al usuario para ingresar de manera correcta
    * \param	mensaje a mostrar para ingresar el dato
    * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
    * \param	minimo numero que se puede ingresar
    * \param	maximo numero que se puede ingresar
    *
    * \return	0 si logra tomar el dato, sino -1
    *
    */
   int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int minimo,int maximo);

   /** \brief	pide un valor tipo float y valida el ingreso
    *
    * \param	puntero a flotante en donde se va a guardar el dato
    * \param	reintentos que se le dan al usuario para ingresar de manera correcta
    * \param	mensaje a mostrar para ingresar el dato
    * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
    * \param	minimo numero que se puede ingresar
    * \param	maximo numero que se puede ingresar
    *
    * \return	0 si logra tomar el dato, sino -1
    *
    */
   int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float minimo,float maximo);

   /** \brief	toma la cadena que fue ingresada y le saca el '\n' al fgets
    *
    * \param	puntero a char en la que cargar la cadena ya validada}
    *
    * \return	0 si tuvo exito, sino -1
    *
    */
   int getCadena(char* pAux,int limite);

   /** \brief	llama a isInt y a isCadena para validar que sea un entero y pasa la cadana a integer
    *
    * \param	puntero a entero donde se va a cargar el numero validado
    *
    * \return	0 si logra validar, sino -1
    *
    */
   int getInt(int* pAux);

   /** \brief	valida que el parametro que se la pase sea flotante. Cuenta que solo haya un punto
    *
    * \param	cadena donde se carga el numero flotante validado
    *
    * \return	0 si la cadena es de numeros y tiene solo un punto, sino -1
    *
    */
   int isFloat(char* pAux);
