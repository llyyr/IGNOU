import java.util.Scanner;

public class AgeComparison {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        try {
            System.out.print("Age of person 1: ");
            int a = s.nextInt();
            System.out.print("Age of person 2: ");
            int b = s.nextInt();
            if (a < 0 || a > 150 || b < 0 || b > 150) throw new IllegalArgumentException("Invalid age");
            System.out.println(a == b ? "Same age" : (a > b ? "Person 1 older" : "Person 2 older"));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } finally {
            s.close();
        }
    }
}
