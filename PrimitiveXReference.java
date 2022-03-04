public class PrimitiveXReference {
    public static void main(String[] args) {
        primitive();
        reference();
    }

    private static void primitive() {
        double pi = 3.14; // o valor é guardado junto a variavel
        // assim, o valor dela é passado como argumento
        System.out.println(pi); // saída: 3.14
        double raio = pi; // apenas o valor de pi é passado para raio
        raio = 10; // assim esta mudança no valor não afeta pi
        double area = pi * (raio * raio);
        System.out.println(area); // saída: 314
    }

    private static void reference() {
        String[] nome = new String[2]; // o valor é guardado na memória Heap, a variavel é um endereço
        nome[0] = "Diogo";
        nome[1] = "Henriques";
        System.out.println(nome); // saída: @endereço
        String[] nomeCasado = nome; // o endereço de de ["Diogo", "Henriques"] é passado para nomeCasado
        nomeCasado[1] = "Rodrigues"; // a mudança então afeta tanto nomeCasado, quanto nome
        System.out.println(nome[1]); // saída: "Rodrigues"
    }

}
