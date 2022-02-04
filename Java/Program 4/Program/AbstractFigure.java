package Program;

public abstract class AbstractFigure {
    protected double a, b, c;
    protected double l, w;
    
    public AbstractFigure(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    public AbstractFigure(double l, double w) {
        this.l = l;
        this.w = w;
    }
    
    public abstract double perimeter();
}

class AbstractTriangle extends AbstractFigure {
    // Overload Constructors
    public AbstractTriangle() {
        super(0, 0, 0);
    }
    
    public AbstractTriangle(int a, int b, int c) {
        super(a, b, c);
    }

    public AbstractTriangle(double a, double b, double c) {
        super(a, b, c);
    }
    
    @Override
    public double perimeter() {
        return a + b + c;
    }
}

class AbstractRectangle extends AbstractFigure {
    // Overload
    public AbstractRectangle() {
        super(0, 0);
    }
    
    public AbstractRectangle(int l, int w) {
        super(l, w);
    }

    public AbstractRectangle(double l, double w) {
        super(l, w);
    }
    
    @Override
    public double perimeter() {
        return 2 * (l + w);
    }
}
