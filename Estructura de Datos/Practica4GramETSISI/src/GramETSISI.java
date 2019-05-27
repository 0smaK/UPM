public class GramETSISI {
    private int maxNodos;             // Tamaño máximo de la tabla.
    private int numVertices;          // Número de vértices.
    private boolean matrizAdy[][];    // Matriz de adyacencias del grafo.
    private Persona contactos[];


    public GramETSISI(int n) { //construye una matriz de nxn sin arcos
        maxNodos = n;
        numVertices = 0;
        matrizAdy = new boolean[n][n];
        contactos = new Persona[n];
    }

    public int getMaxNodos() {
        return maxNodos;
    }

    public int getNumVertices() {
        return numVertices;
    }

    // ------------------------------------

    // MÉTODOS PARA INSERTAR Y ELIMINAR VERTICES

    // ------------------------------------


    public void insertaVertice() {
        if (maxNodos == numVertices)
            System.out.println("Error, se supera el número de nodos máximo del grafo");
        else {
            for (int i = 0; i <= numVertices; i++) {
                //simplemento añado el valor false a las celdas
                matrizAdy[i][numVertices] = matrizAdy[numVertices][i] = false;
            }
            Persona nuevo = new Persona();
            nuevo.leerDatos();
            contactos[numVertices] = nuevo;
            numVertices++;
        }
    }

    public void insertaVertice(Persona a) {
        if (maxNodos == numVertices)
            System.out.println("Error, se supera el número de nodos máximo del grafo");
        else {
            for (int i = 0; i <= numVertices; i++) {
                matrizAdy[i][numVertices] = matrizAdy[numVertices][i] = false;
            }
            contactos[numVertices] = a;
            numVertices++;
        }
    }

    public void eliminarVertice(int v) {
        if (v < numVertices && v >= 0) {
            numVertices--;
            int i;
            for (i = 0; i < v; i++) {
                for (int j = v; j < numVertices; j++) {
                    matrizAdy[i][j] = matrizAdy[i][j + 1];
                }
            }
            for (i = v; i < numVertices; i++) {
                contactos[i] = contactos[i + 1];
                int j;
                for (j = 0; j < v; j++) {
                    matrizAdy[i][j] = matrizAdy[i + 1][j];
                }
                for (j = v; j < numVertices; j++) {
                    matrizAdy[i][j] = matrizAdy[i + 1][j + 1];
                }
            }
        } else System.out.println("Error, fuera de rango");
    }

    // ------------------------------------

    // MÉTODOS PARA INSERTAR Y ELIMINAR ARISTAS

    // ------------------------------------

    public void insertaArista(int i, int j) {
        if ((i >= numVertices) || (j >= numVertices))
            System.out.println("Error, los vertices no se encuentran en el grafo.");
        else {
            matrizAdy[i][j] = true;
            matrizAdy[j][i] = matrizAdy[i][j];
        }
    }

    public boolean existeArista(int i, int j) {
        if ((i >= numVertices) || (j >= numVertices)) {
            System.out.println("Error, los vertices no se encuentran en el grafo.");
            return false;
        }
        return matrizAdy[i][j];
    }


    public void imprimirGrafo() {
        System.out.println("Contenido de la matriz: ");
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrizAdy[i][j]) System.out.print("1 ");
                else System.out.print("0 ");
            }
            System.out.println();
        }
        if(contactos.length>0){
            System.out.println("Existen "+contactos.length+" contactos");
        }
        for(int i = 0; i < contactos.length ; i++){
            if(contactos[i]!=null){
                System.out.print(i+": ");
                System.out.println(contactos[i].getNombre()+ " ( "+ contactos[i].getTelefono()+ " ) "+ contactos[i].getDireccion());
            }
        }
        System.out.println("");
    }

    public int contarGrupos() {
        int ncontactos = 0;
        boolean tmp = false;
        for (int i = 0; i < numVertices; i++) {
            tmp = false;
            for (int j = 0; j < numVertices; j++) {
                if((existeArista(i,j)) && (j < i)) tmp = true;
                if((!tmp) && (j==i)){
                    ncontactos++;
                }
            }
        }
        return ncontactos;
    }

    public void mostrarAmigos(String nombre){
        boolean flag = false;
        for (int i = 0; i < numVertices; i++) {
            if(contactos[i].getNombre().equals(nombre)){
                flag = true;
                for (int j = 0; j < numVertices; j++) {
                    if(existeArista(i,j) && i!=j){
                        System.out.println(contactos[j].getNombre());
                    }
                }
            }

        }
        if(!flag){
            System.out.println("Persona no encontrada");
        }
    }

    public void mayorGrupo(){
        boolean tmp = false;
        int maxContacts = 0;
        int maxContactsAux = 0;
        int contactoEnMayorGrupo = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if((existeArista(i,j)) && (j < i)) tmp = true;
                if((!tmp) && (j==i)){
                    for(int k = 0; k < numVertices; k++){
                        if(existeArista(i,k) || i==k){
                            maxContactsAux++;
                        }
                    }
                    if(maxContactsAux > maxContacts){
                        maxContacts = maxContactsAux;
                        contactoEnMayorGrupo = i;
                    }
                    tmp = false;
                }
            }
        }
        for (int j = 0; j < numVertices; j++) {
            if(contactoEnMayorGrupo == j){
                System.out.println(contactos[contactoEnMayorGrupo].getNombre());
            }
            if(existeArista(contactoEnMayorGrupo, j)){
                System.out.println(contactos[j].getNombre());
            }
        }
    }
}
	  




