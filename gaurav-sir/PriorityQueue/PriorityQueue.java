
public class PriorityQueue {

    private final Integer[] pq;
    private int n;

    PriorityQueue(int cap) {
        this.pq = new Integer[cap + 1];
    }

    public void insert(int x) {
        this.pq[++n] = x;
        swim(n);
    }

    public Integer delMax() {
        int maxEle = this.pq[1];
        exch(1, n--);
        sink(1);
        this.pq[n + 1] = null; // loitering
        return maxEle;
    }

    public boolean isEmpty() {
        return this.n == 0;
    }

    public Integer size() {
        return this.n;
    }

    private void swim(int k) {
        while (k > 1 && pq[k / 2] < pq[k]) {
            this.exch(k, k / 2);
            k = k / 2;
        }
    }

    private void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;

            if (j < n && this.pq[j] < this.pq[j + 1]) {
                j++;
            }

            if (this.pq[k] >= this.pq[j]) {
                break;
            }

            exch(k, j);

            k = j;
        }
    }

    private void exch(int i, int j) {
        int temp = this.pq[i];
        this.pq[i] = this.pq[j];
        this.pq[j] = temp;
    }

    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(10);

        pq.insert(5);
        pq.insert(11);
        pq.insert(7);

        int max1 = pq.delMax();
        assert max1 == 11;
        assert pq.size() == 2;

        pq.insert(15);
        pq.insert(11);
        pq.insert(19);

        int max = pq.delMax();
        assert max == 19;
        // use -ea flag while compiling (enable assert in java)
        System.out.print("All Test Cases Passed\n");
    }
}
