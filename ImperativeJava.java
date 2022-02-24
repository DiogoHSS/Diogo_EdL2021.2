/**
 * Este programa vai realizar a ordenação da lista
 * sem usar nenhum recurso exclusivo da linguagem
 * mostrando os passos necessários como numa
 * programação imperativa.
 */

public class ImperativeJava {
    public static void main(String[] args) {
        int[] lista = { 8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5 };
        // varíavel para guardar um valor durante a troca de posições
        int aux = 0;

        System.out.print("antes: {" + lista[0]);
        for (int i = 1; i < lista.length; i++) {
            System.out.print(", " + lista[i]);
        }
        System.out.println("}");

        // realiza a ordenacao
        for (int i = 0; i < lista.length; i++) {
            for (int j = i + 1; j < lista.length; j++) {
                if (lista[i] > lista[j]) {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }

        System.out.print("depois: {" + lista[0]);
        for (int i = 1; i < lista.length; i++) {
            System.out.print(", " + lista[i]);
        }
        System.out.println("}");
    }
}
