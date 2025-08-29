

class Node{

    public :
        int data;
        Node* left;
        Node* right;
    public:
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    //traversing a tree


    return 0;

}