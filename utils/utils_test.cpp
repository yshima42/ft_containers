#include "avl_node.hpp"
#include <cassert>

template< class T >
void print(T t) {
    std::cout << t << std::endl;
}

template< class T >
void test_print(std::string case_name, T output) {
    std::cout << case_name << ": " << output << std::endl;
}


void test_node() {
    ft::avl_node<int> n0(0);
    ft::avl_node<int> n1(10);
    ft::avl_node<int> n2(20);
    ft::avl_node<int> n3(30);
    ft::avl_node<int> n4(40);
    ft::avl_node<int> n5(50);
    ft::avl_node<int> n6(60);

    //test_print("balance()", n1.balance());
    assert(n1.balance() == 0);

    n1.connect_left(&n2);
    //test_print("balance()", n1.balance());
    assert(n1.balance() == 1);

    // leftについてる
    assert(n1.left_->value_ == n2.value_);
    assert(n2.parent_->value_ == n1.value_);

    // right
    n1.connect_right(&n3);
    assert(n1.right_->value_ == n3.value_);

    // parent
    n1.connect_parent(&n0, true);
    assert(n1.parent_->value_ == n0.value_);
    assert(n0.left_->value_ == n1.value_);

    // disconnect_parent
    assert(n0.left_->value_ == n1.value_);
    assert(n0.left_ != NULL);
    n1.disconnect_parent();
    assert(n1.parent_ == NULL);
    assert(n0.left_ == NULL);

    n2.disconnect_parent();
    n3.disconnect_parent();

    n3.connect_left(&n1);
    n1.connect_left(&n0);
    n1.connect_right(&n2);
    n3.connect_right(&n5);
    n5.connect_left(&n4);
    n5.connect_right(&n6);

    assert(n1.next_node()->value_ == n2.value_);
    assert(n2.next_node()->value_ == n3.value_);
    assert(n3.next_node()->value_ == n4.value_);
    assert(n4.next_node()->value_ == n5.value_);


    print("[OK]");

}

int main() {
    test_node();
}