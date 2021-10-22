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
        this->data = data;
    }
    Node (int data, Node* father) {
        this->data = data;
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
    	root = NULL;
    }

    // Find a node with value data and return 
    Node* findNode( Node* root, int data) {
        if( root == NULL) return NULL;
        if( root->data == data) return root;
        else {
            Node* loopTemp = root->firstChild;
            while(loopTemp) {
                if (loopTemp->data == data) return loopTemp;
                if (loopTemp->firstChild != NULL) {
                    Node* newNode = findNode(loopTemp->firstChild,data);
                    if( newNode != NULL) return newNode;
                }
                loopTemp = loopTemp->nextSibling;
            }
        }
    }

    // Insert a Node with value data into a linkedlist
    void insertToSortedLinkedList (Node* head, int data) {
        if(!head) head = new Node(data);
        Node* newNode = new Node(data);
        Node* loopTemp = head;
            while (loopTemp->nextSibling != NULL && loopTemp->nextSibling->data < data) loopTemp = loopTemp->nextSibling;
            Node * temp = loopTemp;
            newNode->nextSibling = loopTemp->nextSibling;
            temp->nextSibling = newNode;
    }

    // Insert a Node with fatherNode and value data
    bool insert(int father, int data) {
        if (!this->root && father == 0) {
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

    int countNodeDelete(Node* root) {
        if(!root) return 0;
        if(!root->firstChild) return 1;
        Node* temp = root->firstChild;
        int res=1;
        while(temp) {
            res += countNodeDelete(temp);
            temp->nextSibling;
        }
        return res;
    }
    // Delete a Node with value data into a linkedlist
    int removeInSortedLinkedList( Node* head, int data) {
        Node* temp = head;
        while(temp->nextSibling->data < data) temp = temp->nextSibling;
        // Node* pointer = temp->nextSibling;
        int res = countNodeDelete(temp->nextSibling);
        temp->nextSibling = temp->nextSibling->nextSibling;
        // delete all Nodes
        // deleteNode(pointer);
    }

    // Remove a Node with value data
    int remove(int data) {
        Node* temp = findNode(root,data);
        if (temp == NULL) return 0;
        return removeInSortedLinkedList(temp->fatherNode->firstChild,data);
    }

    // Preorder traversal
    void preorder( Node* root) {
        if(!root) return;
        cout << root->data << " ";
        if(root->nextSibling != NULL) {
            Node* temp = root->nextSibling;
            while(temp) {
                preorder(temp);
                temp = temp->nextSibling;
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
                temp = temp->nextSibling;
            }
        }
        cout << root->data << " ";

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

    bool isBinarySearchTree();

    bool isMaxHeapTree();

    void inorder( Node* root) {
        if(!root) return;
        if (isBinaryTree(root)) {
            Node* temp = root->firstChild;
            inorder(temp);
            cout << root->data << " ";
            inorder(temp->nextSibling);               
        }
    }

    int height(Node* root) {
        if (!root) return 0;
        Node* temp = root->firstChild;
        int h = height(temp);
        temp = temp->nextSibling;
        while(temp) {
            int x = height(temp);
            h = h > x ? h : x;
            temp = temp->nextSibling;
        }
    }

    int depth(int data) {
        Node* temp = findNode(this->root,data);
        int count=0;
        while(temp != this->root) {
            count++;
            temp = temp->fatherNode;
        }
        return count;
    }

    int numOfLeaves(Node* root) {
        if(!root->firstChild) return 1;
        int sum=0;
        Node* temp = root->firstChild;
        while(temp) {
            sum += numOfLeaves(temp);
            temp = temp->nextSibling;
        }
        return sum;
    }

    int findMax(Node* root, int max) {
        if(!root->firstChild) {
            return (root->data > max) ? root->data : max;
        }
        Node* temp = root->firstChild;
        while(temp) {
            max = findMax(temp,max);
            temp = temp->nextSibling;
        }
        return max;       
    }

    int findMaxChild() {

    }
};

int main(int argc, char const *argv[]) {
	Tree* tree = new Tree();
	tree->insert(0,1);
	tree->insert(1,3);
	tree->insert(1,2);
	tree->insert(1,4);
	tree->insert(1,5);
	tree->insert(3,19);
	tree->insert(3,25);
	tree->insert(3,9);
	tree->insert(2,12);
	tree->insert(2,13);
	tree->insert(2,14);
	tree->insert(2,15);
	tree->insert(4,99);
	tree->insert(4,95);
	tree->insert(4,43);
	tree->insert(5,55);
//	tree.insert(5,59);
//	tree.insert(19,1);
//	tree.insert(19,1);
//	tree.insert(25,1);
//	tree.insert(9,1);
//	tree.insert(12,1);
//	tree.insert(13,1);
//	tree.insert(13,1);
//	tree.insert(14,1);
//	tree.insert(15,1);
//	tree.insert(99,1);
//	tree.insert(43,1);
//	tree.insert(55,1);
//	tree.insert(59,1);
    return 0;
}

// duyệt và in ra cây theo từng tầng
// có dùng đệ quy
// không dùng đệ quy
