package Program;

public class App {
    public static void main(String[] args) {
        // Abstract Test
        AbstractFigure num1 = new AbstractTriangle(3, 5, 7);
        AbstractFigure num2 = new AbstractRectangle(3, 5);
        
        System.out.println("Abstract Triangle: " + num1.perimeter());
        System.out.println("Abstract Triangle: " + num2.perimeter());
        
        System.out.print('\n');
        
        // Interface Test
        Triangle num3 = new Triangle(3, 5, 7);
        Rectangle num4 = new Rectangle(3, 5);

        System.out.println("Interface Triangle: " + num3.perimeter());
        System.out.println("Interface Triangle: " + num4.perimeter());
    }
}
