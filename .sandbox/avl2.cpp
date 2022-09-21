#include <algorithm>

using namespace std;

template<typename T>
class AVLTree {
    struct Node {
        Node *left, *right, *ptr;
        T key;
        int height, size;

        Node(T x) {
            left = right = ptr = nullptr;
            height = 1;
            key = x;
            size = 1;
        }

        inline int factor() const {
            int lv = (this->left ? this->left->height : 0);
            int rv = (this->right ? this->right->height: 0);
            return rv - lv;
        }

        inline int update_height() {
            return this->height = max(
                (this->left ? this->left->height : 0),
                (this->right ? this->right->height : 0)
            ) + 1;
        }
        
        inline bool is_left(Node *node) const {
            return left == node;
        }

        inline void assign(Node *node) {
            this->key = node->key;
        }

        inline Node * rotate_left() {
            Node *r = this->right;
            Node *m = r->left;
            Node *p = this->ptr;

            if (r->ptr = p) {
                if (p->left == this) {
                    p->left = r;
                } else {
                    p->right = r;
                }
            }
            if (this->right = m)
        }


    };

    Node * root;



};

