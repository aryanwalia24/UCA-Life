
import java.util.Scanner;

public class reverseNumber {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = scanner.nextInt();
        int reversedNumber = reverse(number);
        System.out.println("Reversed Number: " + reversedNumber);
    }

    public static int reverse(int number) {
        int flag = 1;
        if (number < 0) {
            flag = -1;
            number = number * -1;
        }
        int reversed = 0;
        while (number != 0) {
            int digit = number % 10;
            if (reversed > (Integer.MAX_VALUE - digit) / 10) {
                return 0;
            }
            reversed = reversed * 10 + digit;
            number /= 10;
        }
        return reversed * flag;
    }
}
