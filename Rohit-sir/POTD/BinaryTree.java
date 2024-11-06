import java.util.*;

class Node {
    int val;
    Node left;
    Node right;

    Node() {
    }

    Node(int x) {
        val = x;
    }

    Node(int x, Node left, Node right) {
        val = x;
        this.left = left;
        this.right = right;
    }
}

class Pair<T, U> {
    T first;
    U second;

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
}

public class BinaryTree {

    public List<List<Integer>> verticalOrder(Node root) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }

        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(root, 0));
        int min = 0, max = 0;

        while (!q.isEmpty()) {
            Pair<Node, Integer> p = q.poll();
            Node curr = p.first;
            int hd = p.second;

            min = Math.min(min, hd);
            max = Math.max(max, hd);

            map.putIfAbsent(hd, new ArrayList<>());
            map.get(hd).add(curr.val);

            if (curr.left != null) {
                q.offer(new Pair<>(curr.left, hd - 1));
            }
            if (curr.right != null) {
                q.offer(new Pair<>(curr.right, hd + 1));
            }
        }

        for (int i = min; i <= max; i++) {
            if (map.containsKey(i)) {
                ans.add(map.get(i));
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Node root = new Node(3);
        root.left = new Node(9);
        root.right = new Node(20);
        root.right.left = new Node(15);
        root.right.right = new Node(7);

        BinaryTree obj = new BinaryTree();

        for (List<Integer> list : obj.verticalOrder(root)) {
            for (int i : list) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
