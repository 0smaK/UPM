/**
* @author: Óscar Muñoz
*
*
**/

public interface IConjunto{
  /**
  * Establecemos el tamaño del array
  */
  static final int SIZE = 20;

  /**
  * Añade el valor posicion al conjunto
  * @param posicion Elemento a añadir o eliminar
  * @param valor true: añadir o false: eliminar
  **/
  void set(int posicion, boolean valor);

  /**
  * Indica si el elemento posicion pertenece al conjunto
  * @param posicion Elemento del cojunto
  */
  boolean get(int posicion);

  /**
  * Devuelve el conjunto completo
  */
  IConjunto get();

  /**
  * Hace la union matematica de los dos conjuntos
  * @param c Conjunto que se va a unir a nuestra instancia
  */
  IConjunto union(IConjunto c);

  /**
  * Indica numero de elementos del conjunto, siempre va a ser menor o igual a SIZE
  */
  int size();
}
