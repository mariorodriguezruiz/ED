#ifndef __REFRANES__H
#define __REFRANES__H
#include "ArbolGeneral.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
   @brief T.D.A.Refranes

   \b Definición:
   Una instancia \e a del tipo de dato abstracto Refranes es una
   colección de frases tipicas de un idioma, dispuestas de forma
   ordenada en las que no hay refranes repetidos.



   <tt>\#include Refranes.h</tt>



   @author Mario Rodríguez Ruiz
   @date Diciembre 2016
*/


class Refranes{
    /**
  * @page repRefranes Rep del TDA Refranes
  *
  * @section invRefranes Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faRefranes Función de abstracción
  *
  * Añadir la función de abstracción
  */
private:
    ArbolGeneral<string> ab;//arbol para almacenar los refranes
    int len_prefijo;//la longitud del prefijo para construir el arbol
    int n_ref;//numero de refranes
    int caracteres_totales ; //caracteres totales a lo largo de todos los refranes
    int caracteres_almacenados ; //caracteres almacenados en el árbol
    int numero_nodos ; //número de nodos creados en el árbol

    /**
     * @brief Incluye un refran en el árbol
     * La función mete una refran recursivamente en el árbol a partir de la raíz.
     * @param n Nodo a partir del que se va a insertar el string.
     * @param refran String que contiene el refrán a insertar
     * @pre n debe ser la raíz del árbol para que se inserte correctamente.
     */
    void InsertaRefran(ArbolGeneral<string>::Nodo n, string refran, int nivel);

    /** @brief Borra un refrán en el conjunto
     * @param n: nodo que compone el refrán a borrar
     * @pre n debe ser un nodo hoja
     * @note el numero de refranes se decrementa en uno
     */
    void BorrarRefran(ArbolGeneral<string>::Nodo n) ;

 public:
    /** @brief Constructor por defecto. Inicia len_prefijo a 3
     * */
    Refranes();

    /** @brief Constructor por defecto. Inicia len_prefijo a  un valor
     **/

    Refranes(int lpre);

    /** @brief Destructor
     **/
    ~Refranes() ;

    /** @brief devuelve el numero de refranes alamacenados
     */

    int size()const;

    /** @brief Inserta un refran en el conjunto
     * @param r: refran a insertar
     * @note el numero de refranes se incrementa en uno mas
     */
    void Insertar(const string & refran);

    /** @brief Borra un refrán en el conjunto
     * @param r: refran a borrar
     * @note el numero de refranes se decrementa en uno
     */

    void BorrarRefran(const string &refran);

    class iterator;
    class const_iterator; //declaracion adelantada de los iteradores de refranes

    /** @brief Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
     * @param r: refran a buscar
     * @return una pareja que contiene si el refran esta y en caso afirmativo un iterador a el
    */
    pair<bool, iterator> Esta(const string &refran);

    /** @brief Devuelve un refrán obtenido de forma aleatoria.
     */
    string ObtenerRefranAleatorio();

    /** @brief Elimina todos los refranes
     */

    void clear();

    /** @brief Lectura/Escritura de un conjunto de refranes
     */

    friend istream & operator>>(istream &is, Refranes &R);


    friend ostream & operator<<(ostream &is,const Refranes &R);

    /**@brief Devuelve el numero total de los caracteres en todos los refranes
     */

    int Caracteres_Refranes()const;

    /** @brief Devuelve el numero de caracteres usados
     *  @note que no tiene que conincide con el numero de caracteres de todos los refranes almancenados

     */
    int Caracteres_Almacenados();

    /** @brief Numero de nodos necesarios para la configuración
     */
    int Numero_Nodos()const;

    /****************************************/
    class iterator{
        private:
            ArbolGeneral<string>::iter_preorden it;
            string cad;
            int level ;
            int level_max ;
            bool primera ;
        public:
            iterator(){
                cad="";
                level = 0 ;
                level_max = 0 ;
                primera = true ;
            }
            string & operator *();
            bool operator==(const iterator &i)const;
            bool operator!=(const iterator &i)const;
            bool terminal();

            ArbolGeneral<string>::iter_preorden getIt() ;

            iterator &operator ++();

            friend class Refranes;
            friend class const_iterator;
    };


    class const_iterator{
        private:
            ArbolGeneral<string>::const_iter_preorden it;
            string cad;
            int level ;
            int level_max ;
            int primera ;
        public:
            const_iterator(){
                cad="";
                level = 0 ;
                level_max = 0 ;
                primera = true ;
            }
            const_iterator(const iterator  &i);
            string & operator *();
            bool operator==(const const_iterator &i)const;
            bool operator!=(const const_iterator &i)const;
            bool terminal();

            ArbolGeneral<string>::const_iter_preorden getIt() ;

            const_iterator &operator ++();
            friend class Refranes;

    };

    /***************BEGIN y END*************/

    iterator begin();

    iterator end();

    const_iterator begin()const;

    const_iterator end()const;
};

#include "refranes.cpp"

#endif
