import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

/**
 * Este programa vai realizar a ordenação da lista de inteiros utilizando
 * a interface Comparator escrita em lambda. Mostrando um exemplo
 * de programação funcional.
 */

public class FunctionalJava {
    private static ArrayList<Integer> lista = new ArrayList<>(
            Arrays.asList(8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5));
    // a função que realiza a comparação escrita usando lambda
    private static Comparator<Integer> crescenteC = (i, j) -> i.compareTo(j);

    public static void main(String[] args) {
        System.out.println("antes: " + lista);
        Collections.sort(lista, crescenteC);
        System.out.println("depois: " + lista);
    }
}