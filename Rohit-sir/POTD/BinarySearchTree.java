class Node
{
    int data;
    Node left, right;
    Node(int val) {data = val; left = right = null;}
}

public class BinarySearchTree
{
    public boolean isBST(Node root)
    {
        if(root == null) return true;

        return helper(root, null, null);
    }
    public boolean helper(Node root, Integer min, Integer max)
    {
        if(root == null) return true;
        boolean mincheck = min == null || root.data > min;
        boolean maxcheck = max == null || root.data < max;

        return mincheck && maxcheck && helper(root.left, min, root.data) && helper(root.right, root.data, max);
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(5);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        BinarySearchTree bst =  new BinarySearchTree();
        System.out.println(bst.isBST(root));
    }
}