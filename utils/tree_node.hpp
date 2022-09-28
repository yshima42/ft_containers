#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>

namespace ft {

template <class T>
class tree_node {
 public:
  typedef tree_node* node_ptr;
  typedef T value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  node_ptr parent_;
  node_ptr left_;
  node_ptr right_;
  value_type value_;
  size_type height_;

  tree_node() {}

  explicit tree_node(const value_type& val)
      : parent_(NULL), left_(NULL), right_(NULL), value_(val), height_(1) {}

  tree_node(const tree_node& other)
      : parent_(other.parent_),
        left_(other.left_),
        right_(other.right_),
        value_(other.value_),
        height_(other.height_) {}

  // 左が重ければ+、右が重ければ-
  difference_type balance() const {
    size_type left_height = left_ ? left_->height_ : 0;
    size_type right_height = right_ ? right_->height_ : 0;
    return (left_height - right_height);
  }

  void update_height() {
    size_type left_height = left_ ? left_->height_ : 0;
    size_type right_height = right_ ? right_->height_ : 0;
    height_ = 1 + std::max(left_height, right_height);
  }

  bool is_left() const { return (this == parent_->left_); }
  bool is_right() const { return (this == parent_->right_); }

  void connect_left(node_ptr new_left_node) {
    left_ = new_left_node;
    if (new_left_node) {
      new_left_node->parent_ = this;
    }
  }

  void connect_right(node_ptr new_right_node) {
    right_ = new_right_node;
    if (new_right_node) {
      new_right_node->parent_ = this;
    }
  }

  void connect_parent(node_ptr new_parent_node, bool is_left) {
    parent_ = new_parent_node;
    if (is_left) {
      new_parent_node->left_ = this;
    } else {
      new_parent_node->right_ = this;
    }
  }

  void disconnect_parent() {
    if (is_left()) {
      parent_->left_ = NULL;
    } else {
      parent_->right_ = NULL;
    }
    parent_ = NULL;
  }

  node_ptr max_node() {
    node_ptr node = this;
    while (node->right_) {
      node = node->right_;
    }
    return node;
  }

  node_ptr min_node() {
    node_ptr node = this;
    while (node->left_) {
      node = node->left_;
    }
    return node;
  }

  // constも必要？
  node_ptr next_node() {
    if (right_) {
      return (right_->min_node());
    } else {
      node_ptr node = this;
      while (node->is_right()) {
        node = node->parent_;
      }
      return node->parent_;
    }
  }

  node_ptr next_node() const {
    if (right_)
      return (right_->min_node());
    else {
      const tree_node* node = this;
      while (node->is_right()) node = node->parent_;
      return (node->parent_);
    }
  }

  // constも必要?
  node_ptr prev_node() {
    if (left_) {
      return (left_->max_node());
    } else {
      node_ptr node = this;
      while (node->is_left()) {
        node = node->parent_;
      }
      return node->parent_;
    }
  }

  node_ptr prev_node() const {
    if (left_)
      return (left_->max_node());
    else {
      const tree_node* node = this;
      while (node->is_left()) node = node->parent_;
      return (node->parent_);
    }
  }

  void print_node() {
    std::cout << "  " << value_ << "   " << std::endl;
    std::cout << " /  \\ " << std::endl;
    std::cout << (left_ ? left_->value_ : NULL) << "    " << (right_ ? right_->value_ : NULL) << std::endl;
  }
};

}  // namespace ft

#endif
