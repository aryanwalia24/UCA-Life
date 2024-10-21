interface Shape {
    public double Area();

    public String ShapeName();

    public int NumberOfSides();
}

class Square implements Shape {
    int side;

    Square(int x) {
        this.side = x;
    }

    @Override
    public double Area() {
        return side * side;
    }

    @Override
    public String ShapeName() {
        return "Square";
    }

    @Override
    public int NumberOfSides() {
        return 4;
    }
}

class Rectangle implements Shape {
    int len, wid;

    Rectangle(int len, int wid) {
        this.len = len;
        this.wid = wid;
    }

    @Override
    public double Area() {
        return len * wid;
    }

    @Override
    public String ShapeName() {
        return "Rectangle";
    }

    @Override
    public int NumberOfSides() {
        return 4;
    }
}

class Circle implements Shape {
    int rad;

    Circle(int rad) {
        this.rad = rad;
    }

    @Override
    public double Area() {
        return Math.PI * rad * rad;
    }

    @Override
    public String ShapeName() {
        return "Circle";
    }

    @Override
    public int NumberOfSides() {
        return 0;
    }
}

class Triangle implements Shape {
    int s1, s2, s3;

    // Equilateral triangle
    Triangle(int side) {
        this.s1 = this.s2 = this.s3 = side;
    }

    // Scalene triangle
    Triangle(int s1, int s2, int s3) {
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }

    @Override
    public double Area() {
        double s = (s1 + s2 + s3) / 2.0;
        return Math.sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }

    @Override
    public String ShapeName() {
        if (s1 == s2 && s2 == s3) {
            return "Equilateral Triangle";
        } else {
            return "Scalene Triangle";
        }
    }

    @Override
    public int NumberOfSides() {
        return 3;
    }
}

public class AmazonTask {
    public static void main(String[] args) {
        Shape sq = new Square(4);
        Shape rect = new Rectangle(3, 4);
        Shape circ = new Circle(4);
        Shape tri1 = new Triangle(4);
        Shape tri2 = new Triangle(4, 5, 6);

        System.out.println(sq.ShapeName());
        System.out.println("Area of Square: " + sq.Area());
        System.out.println("Number of sides: " + sq.NumberOfSides());
        System.out.println();

        System.out.println(rect.ShapeName());
        System.out.println("Area of Rectangle: " + rect.Area());
        System.out.println("Number of sides: " + rect.NumberOfSides());
        System.out.println();

        System.out.println(circ.ShapeName());
        System.out.println("Area of Circle: " + circ.Area());
        System.out.println("Number of sides: " + circ.NumberOfSides());
        System.out.println();

        System.out.println(tri1.ShapeName());
        System.out.println("Area of Equilateral Triangle: " + tri1.Area());
        System.out.println("Number of sides: " + tri1.NumberOfSides());
        System.out.println();

        System.out.println(tri2.ShapeName());
        System.out.println("Area of Scalene Triangle: " + tri2.Area());
        System.out.println("Number of sides: " + tri2.NumberOfSides());
        System.out.println();
    }
}
