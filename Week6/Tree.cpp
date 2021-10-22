#include <iostream>
using namespace std;

class Node {
    int data;
    Node* fatherNode;
    Node* firstChild;
    Node* nextSibling;
public:
    Node() {
    }
    Node(int data) {
        this.data = data;
    }
    Node (int data, Node* father) {
        this.data = data;
        this->fatherNode = father;
    }
    friend class Tree;
};

class Tree {
private:
    Node* root;
    int count;
public:
    Tree() {
    }

    // Find a node with value data and return 
    Node* findNode( Node* root, int data) {
        if( root == NULL) return nullptr;
        if( root.data == data) return root;
        else {
            Node* loopTemp = root->firstChild;
            while(loopTemp) {
                if (loopTemp.data == data) return loopTemp;
                if (loopTemp->firstChild != NULL) {
                    Node* newNode = findNode(loopTemp->firstChild,data);
                    if( newNode != NULL) return newNode;
                }
                loopTemp = loopTemp->nextSibling;
            }
        }
    }

    // Insert a Node with value data into a linkedlist
    void insertToSortedLinkedList (node* head, int data) {
        if(!head) head = new Node(data);
        Node* newNode = new Node(data);
        Node* loopTemp = head;
            while (loopTemp->nextSibling.data < data) loopTemp = loopTemp->nextSibling;
            Node * temp = loopTemp;
            newNode->nextSibling = loopTemp->nextSibling;
            temp->nextSibling = newNode;
    }

    // Insert a Node with fatherNode and value data
    bool insert(int father, int data) {
        if (this->root && father == 0) {
            this->root = new Node(data);
            return true;
        }
        else {
            Node* temp = findNode(this->root, data);
            if(temp) {
                return false;
            }
            else {
                insertToSortedLinkedList(temp->fatherNode->firstChild,data);
                return true;
            }

        }
    }

    // Giai phong bo nho
    void deleteNode (Node* head) {
        return;
    }

    // Delete a Node with value data into a linkedlist
    void removeInSortedLinkedList( Node* head, int data) {
        Node* temp = head;
        while(temp->nextSibling.data < data) temp = temp->nextSibling;
        // Node* pointer = temp->nextSibling;
        temp->nextSibling = temp->nextSibling->nextSibling;
        // delete all Nodes
        // deleteNode(pointer);
    }

    // Remove a Node with value data
    int remove(int data) {
        Node* temp = findNode(root,data);
        if (temp == NULL) return 0;
        removeInSortedLinkedList(temp->fatherNode->firstChild,data);
        return 0;
    }

    // Preorder traversal
    void preorder( Node* root) {
        if(!root) return;
        cout << root.data << " ";
        if(root->nextSibling != NULL) {
            Node* temp = root->nextSibling;
            while(temp) {
                preorder(temp);
                temp = temp->next;
            }
        }
    }

    // Postorder traversal
    void postorder( Node* root) {
        if(!root) return;
        if(root->nextSibling != NULL) {
            Node* temp = root->nextSibling;
            while(temp) {
                preorder(temp);
                temp = temp->next;
            }
        }
        cout << root.data << " ";

    }

    // Cound Child Node
    int countChild (Node* root) {
        Node* temp = root->firstChild;
        int count=0;
        while(temp) {
            count++;
            temp = temp->nextSibling;
        }
        return count;
    }

    // Check is Binary Tree
    bool isBinaryTree( Node* root) {
        if(!root) return true;
        int x = countChild(root);
        if( x > 2) return false;
        else if (x == 0) return true;
        else if (x == 1) return isBinaryTree(root->firstChild);
        else return isBinaryTree(root->firstChild) && isBinaryTree(root->firstChild->nextSibling); 
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder( Node* root) {
        if(!root) return;
        if (isBinaryTree(root)) {
            Node* temp = root->firstChild;
            inorder(temp);
            cout << root.data << " ";
            inorder(temp->nextSibling);               
        }
    }

    // Hàm trả về độ cao của cây
    int height() {
        if (!root) return 0;
        
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}

// duyệt và in ra cây theo từng tầng
// có dùng đệ quy
// không dùng đệ quy