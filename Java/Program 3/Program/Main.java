package Program;

public class Main {
    public static void main(String[] args) {
        // Declare all methods
        Private b1 = new Private();
        Public b2 = new Public();
        NGO b3 = new NGO();
        
        System.out.println("Business     Tax");
        System.out.println("-------------------");

        // Display
        System.out.println(b1.gross(1, 1.5));
        System.out.println(b2.gross(1, 1.5));
        System.out.println(b3.gross(1, 1.5));
    }
}
