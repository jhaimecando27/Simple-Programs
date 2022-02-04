package Program;

public interface Figure {
    public abstract double perimeter();
}

class Triangle implements Figure {
    protected final double a, b, c;
    
    // Overload Triangle
    public Triangle() {
        a = b = c = 0;    
    }
    
    public Triangle(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    @Override
    public double perimeter() {
        return a + b + c;
    }
}

class Rectangle implements Figure {
    protected final double l, w;
    
    // Overload Rectangle
    public Rectangle() {
        l = w = 0;
    }
    
    public Rectangle(int l, int w) {
        this.l = l;
        this.w = w;
    }
    
    public Rectangle(double l, double w) {
        this.l = l;
        this.w = w;
    }
    
    @Override
    public double perimeter() {
        return 2 * (l + w);
    }
}
