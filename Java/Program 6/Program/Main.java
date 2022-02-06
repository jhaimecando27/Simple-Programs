package Program;

public class Main {
    static void Problem1() {
        double mile = 10.65;
        System.out.println("Enter mile: " + mile);
        
        System.out.printf("%f\n", mile * 5280);
    }
    
    static void Problem2() {
        double num = -9;
        System.out.println("Enter a number: " + num);
        
        if (num != 0)
            System.out.println(num + " is a" + ((num > 0)? " positive": " negative") + " number");
        else
            System.out.println(num + "is a zero");
        
        System.out.println(num + ((num % 5 == 0)? " is": " is not") + " not divisible by 5");
    }
    
    static void Problem3() {
        int temp = 0;
        
        double n = 28;
        System.out.println("Enter n: " + n);
        
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                temp += i;
        
        System.out.println(n + ((temp == n)? " is": " is not") + " a perfect number.");
    }
    
    static void Problem4() {
        int n = 3;
        System.out.println("Enter n: " + n);
        int total = 0;
        
        for (int i = 1; i < n; i++)
            total += ((i % 2) == 0)? (i * i - 1) * -1: (i * i - 1);
        
        System.out.println("The sum of the series is " + total);
    }
    
    static void Problem5() {
        // Method 1: With int[]
        int decimal = 9;
        
        int index = 0;
        int binary[] = new int[20];
        
        System.out.println("Enter n: " + decimal);
        
        System.out.print("The binary equivalent of " + decimal + " is ");
        
        while (decimal > 0) {
            binary[index++] = decimal % 2;
            decimal /= 2;
        }
        
        for (int i = index - 1; i >= 0; i--)
            System.out.print(binary[i]);
        System.out.print('\n');
        
        // Method 2: With string
        /*
        String binary = "";
        
        System.out.println("Enter n: " + decimal);
        
        for (int i = decimal; i > 0; i /= 2)
            binary += decimal % 2;
        
        System.out.println("The binary equivalent of " + decimal + " is " + binary);
        */
    }
    
    static void Problem6() {
        String word = "civic";
        System.out.println("Enter a word: ");
        
        for (int i = (word.length() / 2) - 1, j = 0; i > j; i--, j++)
            if (word.charAt(i) == word.charAt(j)) {
                System.out.println("The word " + word + " is not palindrome");
                System.exit(0);
            }
        
        System.out.println("The word " + word + " is palindrome");
    }
    
    static void Problem7() {
        int num = 5;
        System.out.println("Enter n: " + num);
        
        // A
        System.out.println("A) Output: ");
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= (num * 2) - i; j++)
                System.out.print((j <= (num - i) * 2)? ' ': '*');
            
            System.out.print('\n');
        }
        System.out.print('\n');
        
        // B
        System.out.println("B) Output: ");
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= (num * 2) - 1; j++)
                System.out.print((j <= (num - i) * 2)? ' ': '*');
            
            System.out.print('\n');
        }
    }
    
    public static void main(String[] args) {
        System.out.println("\nProblem 1:");
        Problem1();
        System.out.println("\nProblem 2:");
        Problem2();
        System.out.println("\nProblem 3:");
        Problem3();
        System.out.println("\nProblem 4:");
        Problem4();
        System.out.println("\nProblem 5:");
        Problem5();
        System.out.println("\nProblem 6:");
        Problem6();
        System.out.println("\nProblem 7:");
        Problem7();
    }
}
