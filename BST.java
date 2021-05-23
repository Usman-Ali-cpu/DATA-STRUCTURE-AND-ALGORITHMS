class Student {
    int studentID; // member to store id  
    String firstName; // string member to store firstname
    String lastName; // string member to store lastname
    String emailAddress; // string member to store email

    // default constructor 
    public Student() {
        // defualt placing value unknown
        this.firstName = "Unknown"; 
        this.lastName = "Unknown";
        this.emailAddress = "Unkown@unkown.com";
        this.studentID = 0;
    }
    // parameterize constructor
    public Student(int id, String first, String last, String email) {
        // assigning values to this members
        this.firstName = first; 
        this.lastName = last;
        this.emailAddress = email;
        this.studentID = id;
    }

    // public member function to print data of Student
    public void printStudent() {
        System.out.println("First name :" + this.firstName);
        System.out.println("Last name :" + this.lastName);
        System.out.println("Email Address :" + this.emailAddress);
        System.out.println("Student ID :" + this.studentID + "\n"); 
    }
}  
class BST_class {
    
    //node class that defines BST node
    class Node {
        int key; // to store key for BST
        Student stData;  // object of Student in each node
        Node left, right; // to point left and right of node

        // defualt constructor 
        public Node() {
            left = right = null;
             
        }
        // parameterize constructor
        public Node(Student data) {
            key = data.studentID;
            this.stData = data;
            left = right = null;
        } 
}



    // Each Student must have, first name, last name, and email address fields. 

    // BST root node 
    Node root; 
  
   // Constructor for BST =>initial empty tree
    BST_class(){
        root = null; 
    } 
    //delete a node from BST
    void deleteKey(int key) { 
        root = delete_Recursive(root, key); 
    } 
   
    //recursive delete function
    Node delete_Recursive(Node root, int key)  { 
        //tree is empty
        if (root == null)  return root; 
   
        //traverse the tree
        if (key < root.key)     //traverse left subtree 
            root.left = delete_Recursive(root.left, key); 
        else if (key > root.key)  //traverse right subtree
            root.right = delete_Recursive(root.right, key); 
        else  { 
            // node contains only one child
            if (root.left == null) 
                return root.right; 
            else if (root.right == null) 
                return root.left; 
   
            // node has two children; 
            //get inorder successor (min value in the right subtree) 
            root.key = minIDValue(root.right); 
   
            // Delete the inorder successor 
            root.right = delete_Recursive(root.right, root.key); 
        } 
        return root; 
    } 

    int minIDValue(Node root)  { 
        //initially minval = root
        int minval = root.key; 
        //find minval
        while (root.left != null)  { 
            minval = root.left.key; 
            root = root.left; 
        } 
        return minval; 
    } 

    // insert a node in BST 
    void insert(int key, Student s)  { 
        root = insert_Recursive(root, key, s); 
    } 

    //recursive insert function
    Node insert_Recursive(Node root, int key, Student s) { 
          //tree is empty
        if (root == null) {
            s.studentID = key; 
            root = new Node(s); 
            return root; 
        } 
        //traverse the tree
        if (key < root.key)     //insert in the left subtree
            root.left = insert_Recursive(root.left, key, s); 
        else if (key > root.key)    //insert in the right subtree
            root.right = insert_Recursive(root.right, key, s); 
          // return pointer
        return root; 
    } 
 
// method for inorder traversal of BST 
    void inorder() { 
        inorder_Recursive(root);  // call to function for print in in-order
    } 

    // recursively traverse the BST  
    void inorder_Recursive(Node root) {
        if (root != null) { // recursive call while not null
            inorder_Recursive(root.left); // recursive call to inorder for left node 
            root.stData.printStudent(); // to print data of that node 

            inorder_Recursive(root.right);  // recursive call to inorder for right node 
        }
    }
    void postorder() { 
        postorder_Recursive(root);  // call to function for print in post-order
    } 

    void postorder_Recursive(Node root) {
        if (root != null) { // recursive call while not null
            postorder_Recursive(root.left); // recursive call to postorder for left node
            postorder_Recursive(root.right);  // recursive call to postorder for right node
            root.stData.printStudent();  // to print data of that node 
        }
    }
    void preorder() { 
        preorder_Recursive(root);  // call to function for print in pre-order
    } 
    void preorder_Recursive(Node root) {
        if (root != null) { // recursive call while not null
            root.stData.printStudent();  // to print data of that node 
            preorder_Recursive(root.left); // recursive call to preorder for left node
            preorder_Recursive(root.right);  // recursive call to preorder for right node
        }
    }

     
    Student find(int key)  { 
        root = search_Recursive(root, key); // get node with this key
        // root.stData.printStudent(); // print data of that node 
        if (root!= null) 
            return root.stData; // return student object 
        else
            return null; // return null
    } 
   
    //recursive insert function
    Node search_Recursive(Node root, int a_key)  { 
        // Base Cases: root is null or key is present at root 
        if (root==null || root.key== a_key) 
            return root; 
        // val is greater than root's key 
        if (root.key > a_key) 
            return search_Recursive(root.left, a_key); 
        // val is less than root's key 
        return search_Recursive(root.right, a_key); 
    } 
}
class Main{
    public static void main(String[] args)  { 
       //create a BST object
       BST_class bst = new BST_class();
        
        
       Student st1 = new Student(45, "John", "Werd", "john@gmail.com");
       Student st2 = new Student(56, "virat", "shane", "virat@gmail.com");
       Student st3 = new Student(9, "david", "warner", "david@gmail.com");
       Student st4 = new Student(3, "Clark", "rick", "clark@gmail.com");
       Student st5 = new Student();
       Student st6 = new Student(50, "Bret", "lee", "bret@gmail.com");

        /* BST tree example
              45 
            /    \ 
           9      56 
         /       /   
        3       50   */
        //insert data into BST
        bst.insert(st1.studentID, st1);  // insert node with key as student ID
        bst.insert(st2.studentID, st2); // insert node with key as student ID
        bst.insert(st3.studentID, st3); // insert node with key as student ID
        bst.insert(st4.studentID, st4);  // insert node with key as student ID
        bst.insert(st5.studentID, st5); // insert node with key as student ID
        bst.insert(st6.studentID, st6); // insert node with key as student ID
        //print the BST
        System.out.println("The BST Created with input data(Left-root-right):");
        System.out.println("********************* Inorder ! ******************************\n"); 
        bst.inorder(); // print in in-order
        System.out.println("*************************** End Inorder ! ****************************\n"); 
        System.out.println("*************************** pre order! ****************************\n");
        bst.preorder(); // print in pre-order
        System.out.println("*************************** End Pre-order ! ****************************\n"); 
        System.out.println("*************************** Post order! *****************************\n");
        bst.postorder(); // print in post-order
        System.out.println("*************************** End Post-order ! ****************************\n"); 
        
        
        try {
            System.out.println("***************  The key You Find is : **************");
            Student retval = bst.find(3);
            retval.printStudent();
            System.out.println("***************  ********************* **************");
        } 
        catch (NullPointerException e) {
            System.out.println("***************  Problem in Finding Student: **************");
            //TODO: handle exception
            System.out.println("You don't have Student with this ID ! \n");
            System.out.println("***************  ********************* **************");
        }
    } 
}

// This is the project: 
// Implement a Binary Tree that has an id of type of integer and a data field of type of Student. 
// Each Student must have, first name, last name, and email address fields. 
// Student ID must be stored in the Binary Tree id filed, 
// so you don't need to have a field in Student class for ID. 
// Then implement following methods for the Binary Tree:

// find(int key): This method will receive a student id (key) and will return a Student info with the same id. 
// If there was no student found for the given key, this method will return null. 

// insert(int key, Student s): this method will insert a student node with 
// the id equals to the key in a proper place for the id field in the binary tree.