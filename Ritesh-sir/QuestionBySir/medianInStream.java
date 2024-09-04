import java.util.*;

class medianInStream {

  static PriorityQueue<Integer> l = new PriorityQueue<>(
    Collections.reverseOrder()
  );
  static PriorityQueue<Integer> r = new PriorityQueue<>();

  public static void insertHeap(int x) {
    if (l.isEmpty()) {
      l.add(x);
    } else if (l.size() > r.size()) {
      r.add(x);
      balanceHeaps();
    } else {
      l.add(x);
      balanceHeaps();
    }
  }

  public static void balanceHeaps() {
    if (l.peek() > r.peek()) {
      int a = l.poll();
      int b = r.poll();
      l.add(b);
      r.add(a);
    }
  }

  public static double getMedian() {
    if (l.size() > r.size()) {
      return (double) l.peek();
    } else {
      int a = l.peek();
      int b = r.peek();
      double res = (a + b) / 2;
      return res;
    }
  }
}
