#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "pair.hpp"
#include "tree_iterator.hpp"
#include "tree_node.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class avl_tree {
 public:
  typedef Key key_type;
  typedef T value_type;
  typedef Compare map_value_compare;
  typedef Allocator allocator_type;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

 private:
  typedef tree_node<T> node_type;

 public:
  typedef node_type* node_pointer;
  // ここ確認
  typedef
      typename Allocator::template rebind<node_type>::other node_allocator_type;

  typedef tree_iterator<value_type, node_type> iterator;
  typedef tree_iterator<const value_type, const node_type> const_iterator;

 private:
  map_value_compare comp_;
  node_allocator_type node_alloc_;
  size_type size_;
  node_pointer begin_;
  node_pointer end_;

 public:
  avl_tree(map_value_compare comp, allocator_type alloc)
      : comp_(comp), node_alloc_(alloc), size_(0) {
    end_ = create_node();
    end_->left_ = NULL;
    begin_ = end_;
  }

  avl_tree(const avl_tree& other)
      : comp_(other.comp_), node_alloc_(other.node_alloc_), size_(0) {
    end_ = create_node();
    end_->left_ = NULL;
    begin_ = end_;
    insert(other.begin(), other.end());
  }

  ~avl_tree() {
    delete_tree();
    delete_node(end_);
  }

  avl_tree& operator=(const avl_tree& other) {
    if (this != &other) {
      clear();
      comp_ = other.comp_;
      node_alloc_ = other.node_alloc_;
      insert(other.begin(), other.end());
    }
    return (*this);
  }

  node_pointer create_node() {
    node_pointer new_node = node_alloc_.allocate(1);
    node_alloc_.construct(new_node);
    return new_node;
  }

  node_pointer create_node(const value_type& val) {
    node_pointer new_node = node_alloc_.allocate(1);
    node_alloc_.construct(new_node, node_type(val));
    return new_node;
  }

  node_pointer create_node_at(const value_type& val, node_pointer parent_node) {
    node_pointer new_node = create_node(val);

    bool is_left = (parent_node == end_ || comp_(val, parent_node->value_));
    new_node->connect_parent(parent_node, is_left);

    if (is_left && parent_node == begin_) {
      begin_ = new_node;
    }
    ++size_;
    return new_node;
  }

  node_pointer root() const { return end_->left_; }

  void delete_node(node_pointer node) {
    node_alloc_.destroy(node);
    node_alloc_.deallocate(node, 1);
  }

  void delete_tree() {
    node_pointer node = root();
    if (node == NULL) {
      return;
    }
    while (node != end_) {
      if (node->left_) {
        node = node->left_;
      } else if (node->right_) {
        node = node->right_;
      } else {
        node_pointer parent_node = node->parent_;
        node->disconnect_parent();
        delete_node(node);
        node = parent_node;
      }
    }
  }

  iterator begin() { return (iterator(begin_)); }
  const_iterator begin() const { return (const_iterator(begin_)); }
  iterator end() { return (iterator(end_)); }
  const_iterator end() const { return (const_iterator(end_)); }

  size_type size() const { return size_; }

  size_type max_size() const {
    return (std::min<size_type>(node_alloc_.max_size(),
                                std::numeric_limits<difference_type>::max()));
  }

  ft::pair<iterator, bool> insert(const value_type& val) {
    node_pointer parent_node = end_;
    node_pointer node = root();

    while (node) {
      parent_node = node;
      if (comp_(val, parent_node->value_)) {
        node = parent_node->left_;
      } else if (comp_(parent_node->value_, val)) {
        node = parent_node->right_;
      } else {
        return (ft::make_pair(iterator(parent_node), false));
      }
    }

    node_pointer new_node = create_node_at(val, parent_node);
    rebalance_tree(new_node);
    return ft::make_pair(iterator(new_node), true);
  }

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for (InputIterator p = first; p != last; ++p) {
      insert(*p);
    }
  }

  void swap(avl_tree& other) {
    std::swap(node_alloc_, other.node_alloc_);
    std::swap(comp_, other.comp_);
    std::swap(size_, other.size_);
    std::swap(begin_, other.begin_);
    std::swap(end_, other.end_);
  }

  void clear() {
    delete_tree();
    size_ = 0;
    end_->left_ = NULL;
    begin_ = end_;
  }

  void rotate_left(node_pointer node) {
    node_pointer right_node = node->right_;

    right_node->connect_parent(node->parent_, node->is_left());
    node->connect_right(right_node->left_);
    right_node->connect_left(node);

    node->update_height();
    right_node->update_height();
  }

  void rotate_right(node_pointer node) {
    node_pointer left_node = node->left_;

    left_node->connect_parent(node->parent_, node->is_left());
    node->connect_left(left_node->right_);
    left_node->connect_right(node);

    node->update_height();
    left_node->update_height();
  }

  // verifyする関数をどこかに入れる

  void rebalance_tree(node_pointer bottom_node) {
    node_pointer node = bottom_node;
    node_pointer parent_node;

    while (node != end_) {
      parent_node = node->parent_;
      difference_type balance = node->balance();
      if (balance == 2) {
        if (node->left_->balance() == -1) {
          rotate_left(node->left_);
        }
        rotate_right(node);
      } else if (balance == -2) {
        if (node->right_->balance() == 1) {
          rotate_right(node->right_);
        }
        rotate_left(node);
      } else {
        node->update_height();
      }
      node = parent_node;
    }
  }

};

}  // namespace ft

#endif
