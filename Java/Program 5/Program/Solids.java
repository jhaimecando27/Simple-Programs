package Program;

/* 
 * Base Class */
public interface Solids {
    abstract double Volume();
    abstract double SurfaceArea();
}


/*
 * Child Classes */

// Shape #1
class Cube implements Solids {
    private final double a;
    
    // Constructor
    /**
     *
     * @param a Edge of the Cube.
     */
    public Cube(double a ) {
        this.a = a;
    }
    
    @Override
    public double Volume() {
        return Math.pow(a, 3);
    }
    
    @Override
    public double SurfaceArea() {
        return 6 * Math.pow(a, 2);
    }
}

// Shape #2
class Cuboid implements Solids {
    private final double l, b, h;
    
    // Constructor
    /**
     *
     * @param l Length of the Cuboid.
     * @param b Base/Width of the Cuboid.
     * @param h Height of the Cuboid.
     */
    public Cuboid(double l, double b, double h) {
        this.l = l;
        this.b = b;
        this.h = h;
    }

    @Override
    public double Volume() {
        return l * b * h;
    }
    
    @Override
    public double SurfaceArea() {
        return 2 * ((l * b) + (l * h) + (h * b));
    }
}

// Shape #3
class Sphere implements Solids {
    private final double r;
    
    // Constructor
    /**
     *
     * @param r Radius of the Sphere.
     */
    public Sphere(double r) {
        this.r = r;
    }
    
    @Override 
    public double Volume() {
        return (4/3) * Math.PI * Math.pow(r, 3);
    }
    
    @Override
    public double SurfaceArea() {
        return 4 * Math.PI * Math.pow(r, 2);
    }
}

// Shape #4
class Cylinder implements Solids{
    private final double r, h;
    
    // Constructor
    /**
     *
     * @param r Radius of the Cylinder.
     * @param h Height of the Cylinder.
     */
    public Cylinder(double r, double h) {
        this.r = r;
        this.h = h;
    }
    
    @Override
    public double Volume() {
        return Math.PI * Math.pow(r, 2) * h;
    }
    
    @Override
    public double SurfaceArea() {
        return 2 * Math.PI * (r + h);
    }
}

// Shape #5
class Cone implements Solids{
    private final double r, h, l;
    
    // Constructor
    /**
     *
     * @param r Radius of the Cone.
     * @param h Height of the Cone.
     * @param l Length of the Cone.
     */
    public Cone(double r, double h, double l) {
        this.r = r;
        this.h = h;
        this.l = l;
    }
    
    @Override
    public double Volume() {
        return 0.5 * Math.PI * Math.pow(r, 2) * h;
    }
    
    @Override
    public double SurfaceArea() {
        return Math.PI * (r + l);
    }
}
