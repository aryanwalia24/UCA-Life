
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class generateParenthesis {

    public static void main(String[] args) {
        int n;
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the value of n: ");
            n = scanner.nextInt();
        }

        List<String> result = generateParenthesis(n);
        System.out.println("Generated Parentheses: " + result);
    }

    public static List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generateParenthesisHelper(result, "", n, n);
        return result;
    }

    private static void generateParenthesisHelper(List<String> result, String current, int open, int close) {
        if (open == 0 && close == 0) {
            result.add(current);
            return;
        }

        if (open > 0) {
            generateParenthesisHelper(result, current + "(", open - 1, close);
        }
        if (close > open) {
            generateParenthesisHelper(result, current + ")", open, close - 1);
        }
    }
}
