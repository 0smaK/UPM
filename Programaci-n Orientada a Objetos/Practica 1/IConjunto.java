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
   * Indica si el elemento 'posicion' pertenece al conjunto.
   * @param posicion Elemento que se consulta.
   * @return 'true' si el elemento pertenece al conjunto; 'false' si el elemento no pertenece al conjunto.
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
  * Realiza la intersección matemática de conjuntos.
  * @param c Conjunto con el que se va a realizar la intersección a nuestra instancia.
  * @return Intersección del conjunto c con la instancia de la clase.
  */
  IConjunto intersection(IConjunto c);

  /**
  * Indica numero de elementos del conjunto, siempre va a ser menor o igual a SIZE
  */
  int size();

  @Override
  String toString();
}
