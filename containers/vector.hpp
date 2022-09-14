#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

#include "../utils/algorithm.hpp"
#include "../utils/iterator.hpp"
#include "../utils/random_access_iterator.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  // member types
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;

  // need to change later maybe
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  // constructor
  explicit vector(const Allocator& alloc = allocator_type())
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {}

  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator())
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {
    resize(count, value);
  }

  // need to add enable_if
  // template <typename InputIt>
  // vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
  //    : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {
  //  (void)first;
  //  (void)last;
  //  (void)alloc;
  // }

  // copy constructor
  vector(vector const& other)
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(other.alloc_) {
    reserve(other.size());
    for (pointer dest = first_, src = other.begin(), last = other.end();
         src != last; ++dest, ++src) {
      construct(dest, *src);
    }
    last_ = first_ + other.size();
  }

  // destructor
  ~vector() {
    clear();
    deallocate();
  }

  // assignment operator
  vector& operator=(vector const& other) {
    // 1.self assignment, do nothing
    if (this == &other) return *this;
    // 2.if the size is same, copy everything
    if (size() == other.size()) {
      std::copy(other.begin(), other.end(), begin());
    }
    // 3.other case
    else if (capacity() >= other.size()) {
      std::copy(other.begin(), other.begin() + other.size(), begin());
      // copy the remaining
      for (const_iterator src_iter = other.begin() + other.size(),
                          src_end = other.end();
           src_iter != src_end; ++src_iter, ++last_) {
        construct(last_, *src_iter);
      }
    }
    // not enough size
    else {
      // destroy all the elements
      destroy_until(rbegin());
      // reserve size
      reserve(other.size());
      // copy
      for (const_iterator src_iter = other.begin(), src_end = other.end(),
                          dest_iter = begin();
           src_iter != src_end; ++src_iter, ++dest_iter, ++last_) {
        construct(last_, *src_iter);
      }
    }
    return *this;
  }

  // check size and capacity
  size_type size() const { return end() - begin(); }
  bool empty() const { return begin() == end(); }
  size_type capacity() const { return reserved_last_ - first_; }

  void push_back(const_reference value) {
    if (size() + 1 > capacity()) {
      size_type c = size();
      if (c == 0)
        c = 1;
      else
        c *= 2;  // オーバーフロー処理
      reserve(c);
    }
    construct(last_, value);
    ++last_;
  }

  void pop_back() { destroy(--last_); }

  // iterator insert(iterator position, const value_type &val) {
  //   size_type offset = position - begin();
  //   insert(position, 1, val);
  //   return begin() + offset;
  // }

  // void insert(iterator position, size_type n, const value_type &val) {
  //   size_type new_size = size() + n;
  //   size_type offset = position - begin();

  // }

  // iterator access
  iterator begin() { return first_; }
  iterator end() { return last_; }
  iterator begin() const { return first_; }
  iterator end() const { return last_; }
  const_iterator cbegin() const { return first_; }
  const_iterator cend() const { return last_; }

  // この4つ意味わからないので後ほど検討->reverse_iteratorのconstructorを使っている
  reverse_iterator rbegin() { return reverse_iterator(last_); }
  reverse_iterator rend() { return reverse_iterator(first_); }
  const_reverse_iterator rbegin() const { return reverse_iterator(last_); }
  const_reverse_iterator rend() const { return reverse_iterator(first_); }

  void clear() { destroy_until(rend()); }

  void reserve(size_type sz) {
    if (sz <= capacity()) return;

    pointer ptr = allocate(sz);

    pointer old_first = first_;
    pointer old_last = last_;

    size_type old_capacity = capacity();

    first_ = ptr;
    last_ = first_;
    reserved_last_ = first_ + sz;

    for (pointer old_iter = old_first; old_iter != old_last;
         ++old_iter, ++last_) {
      //理解にはムーブセマンティクスを理解が必要
      construct(last_, *old_iter);
    }

    for (reverse_iterator riter = reverse_iterator(old_last),
                          rend = reverse_iterator(old_first);
         riter != rend; ++riter) {
      destroy(&*riter);
    }
    alloc_.deallocate(old_first, old_capacity);
  }

  void resize(size_type sz, const_reference value) {
    // smaller than current elems
    if (sz < size()) {
      difference_type diff = size() - sz;
      destroy_until(rbegin() + diff);
      last_ = first_ + sz;
    } else if (sz > size()) {
      // biger than current elems
      reserve(sz);
      for (; last_ != reserved_last_; ++last_) {
        construct(last_, value);
      }
    }
  }

 private:
  pointer first_;
  pointer last_;
  pointer reserved_last_;
  allocator_type alloc_;

  // helper functions
  pointer allocate(size_type n) { return alloc_.allocate(n); }
  void deallocate() { alloc_.deallocate(first_, capacity()); }
  void construct(pointer ptr) { alloc_.construct(ptr, 0); }
  void construct(pointer ptr, const_reference value) {
    alloc_.construct(ptr, value);
  }
  void destroy(pointer ptr) { alloc_.destroy(ptr); }
  void destroy_until(reverse_iterator rend) {
    for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last_)
      destroy(&*riter);
  }
};
}  // namespace ft

#endif
