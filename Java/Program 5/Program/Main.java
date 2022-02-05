package Program;

public class Main {
    public static void main(String[] args) {
        // Volume Examples
        Solids ShapeV1 = new Cube(7);
        Solids ShapeV2 = new Cuboid(7, 7, 7);
        Solids ShapeV3 = new Sphere(7);
        Solids ShapeV4 = new Cylinder(7, 7);
        Solids ShapeV5 = new Cone(7, 17, 27);
        
        // Surface Area Examples
        Solids ShapeSA1 = new Cube(7);
        Solids ShapeSA2 = new Cuboid(7, 7, 7);
        Solids ShapeSA3 = new Sphere(7);
        Solids ShapeSA4 = new Cylinder(7, 7);
        Solids ShapeSA5 = new Cone(7, 17, 27);
        
        // Display Examples
        System.out.println("-- Volume");
        System.out.println("Volume of Cube: " + ShapeV1.Volume());
        System.out.println("Volume of Cuboid: " + ShapeV2.Volume());
        System.out.println("Volume of Sphere: " + ShapeV3.Volume());
        System.out.println("Volume of Cylinder: " + ShapeV4.Volume());
        System.out.println("Volume of Cone: " + ShapeV5.Volume());
        
        System.out.println('\n');
        
        System.out.println("-- Surface Area");
        System.out.println("Surface Area of Cube: " + ShapeSA1.SurfaceArea());
        System.out.println("Surface Area of Cuboid: " + ShapeSA2.SurfaceArea());
        System.out.println("Surface Area of Sphere: " + ShapeSA3.SurfaceArea());
        System.out.println("Surface Area of Cylinder: " + ShapeSA4.SurfaceArea());
        System.out.println("Surface Area of Cone: " + ShapeSA5.SurfaceArea());
    }
}
