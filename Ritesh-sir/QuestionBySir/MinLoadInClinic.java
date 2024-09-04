import java.util.PriorityQueue;
import java.util.Scanner;

class MinLoadInClinic {

  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      int n = sc.nextInt();
      PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.first - a.first);

      for (int i = 0; i < n; i++) {
        int temp = sc.nextInt();
        pq.add(new Pair(temp, 1));
      }

      int m = sc.nextInt();
      m -= n;
      int clinics = 1;

      while (clinics <= m) {
        clinics++;
        Pair top = pq.poll();
        int popu = top.first;
        int clin = top.second;
        popu = popu * clin / (clin + 1);
        pq.add(new Pair(popu, clin + 1));
      }

      System.out.println(pq.peek().first);
    }
  }

  static class Pair {

    int first;
    int second;

    Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }
}
