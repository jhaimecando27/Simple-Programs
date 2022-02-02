public class Main {
    // In Recursion Way
    public static double fact_recur(double num) {
        // Base Condition
        if (num == 1) 
            return 0;
        
        // Calculate for ln
        return Math.log(num) + fact_recur(num - 1);   
    }
    
    // In Iterative Way
    public static double fact_Iter(double num) {
        double total = 0;
        
        // Caculate for ln
        for (double i = 1; i <= num; i++)
            total += Math.log(i);
        
        return total;
    }
    
    public static void main(String[] args) {
        System.out.println(fact_recur(3));
        System.out.println(fact_Iter(3));
    }
}
