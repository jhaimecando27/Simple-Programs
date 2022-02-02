import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in); // Scanner Object
        
        // Prompt user
        System.out.print("Enter mass in kilograms: ");
        double mass = input.nextDouble();
        System.out.print("Enter velocity in meter per second: ");
        double velocity = input.nextDouble();
        
        // Calculate for Kinetic Energy (KE)
        double KE = 0.5 * (mass * (velocity * velocity));
        
        // Display Result
        System.out.printf("The object's kinetic energy is %.2f J.\n", KE);
        
        input.close();
    }
}
