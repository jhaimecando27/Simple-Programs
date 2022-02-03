package Program;

abstract class Business {
    String business_type = null;
    
    // Constructor
    Business(String business_type) {
        this.business_type = business_type;
    }

    public void business_type() {
        System.out.print(business_type);
    }; 
    abstract double gross(int income, double expenses);
    abstract double gross(double income, int expenses);
}

class Private extends Business {
    Private() {
        super("Private      ");
    }
    
    // Overload
    public double gross(int income, double expenses) {
        business_type();
        return income * 0.25 - expenses;
    };
    public double gross(double income, int expenses) {
        business_type();
        return income * 0.25 - expenses;
    };
}

class Public extends Business {
    Public() {
        super("Public       ");
    } 
    // Overload
    public double gross(int income, double expenses) {
        business_type();
        return income * 0.2 - expenses;
    };
    public double gross(double income, int expenses) {
        business_type();
        return income * 0.2 - expenses;
    };
}

class NGO extends Business {
    NGO() {
        super("NGO          ");
    }

    // Overload
    public double gross(int income, double expenses) {
        business_type();
        return income * 0.1 - expenses;
    };
    public double gross(double income, int expenses) {
        business_type();
        return income * 0.1 - expenses;
    };
}
