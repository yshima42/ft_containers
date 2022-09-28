#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

#include "../utils/algorithm.hpp"
#include "../utils/iterator.hpp"
#include "../utils/random_access_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/utils.hpp"

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
  typedef typename ft::random_access_iterator<value_type> iterator;
  typedef typename ft::random_access_iterator<const value_type> const_iterator;
  typedef typename ft::reverse_iterator<iterator> reverse_iterator;
  typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

  // constructor
  vector()
      : first_(NULL),
        last_(NULL),
        reserved_last_(NULL),
        alloc_(allocator_type()) {}

  explicit vector(const Allocator& alloc)
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {}

  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator())
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {
    resize(count, value);
  }

  template <typename InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
         typename ft::enable_if<!ft::is_integral<InputIt>::value,
                                InputIt>::type* = NULL)
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {
    reserve(ft::distance(first, last));
    for (InputIt i = first; i != last; ++i) {
      push_back(*i);
    }
  }

  // copy constructor
  vector(vector const& other)
      : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(other.alloc_) {
    reserve(other.size());

    pointer dest = first_;
    for (const_iterator src = other.begin(), last = other.end(); src != last;
         ++dest, ++src) {
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
      // destroy_until(rbegin());
      clear();
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
  // ok
  size_type size() const { return end() - begin(); }

  // ok
  bool empty() const { return begin() == end(); }

  // ok
  size_type capacity() const { return reserved_last_ - first_; }

  // macの実装に合わせた
  size_type max_size() const {
    return std::min<size_type>(alloc_.max_size(),
                               std::numeric_limits<difference_type>::max());
  }

  void assign(size_type count, const T& value) {
    if (count > capacity()) {
      clear();
      deallocate();

      first_ = allocate(count);
      last_ = first_;
      reserved_last_ = first_ + count;
      for (size_type i = 0; i < count; ++i) {
        construct(last_++, value);
      }
    } else if (count > size()) {
      pointer ptr = first_;
      for (size_type i = 0; i < count; ++i) {
        if (i < size()) {
          *(ptr++) = value;
        } else {
          construct(last_++, value);
        }
      }
    } else {
      clear();
      for (size_type i = 0; i < count; ++i) {
        construct(last_++, value);
      }
    }
  }

  template <class InputIt>
  void assign(InputIt first, InputIt last,
              typename ft::enable_if<!ft::is_integral<InputIt>::value,
                                     InputIt>::type* = NULL) {
    size_type count = std::distance(first, last);
    if (count > capacity()) {
      clear();
      deallocate();

      first_ = allocate(count);
      last_ = first_;
      reserved_last_ = first_ + count;
      for (InputIt head = first; head != last; ++head) {
        construct(last_++, *head);
      }
    } else if (count > size()) {
      pointer ptr = first_;
      for (size_type i = 0; i < count; ++i) {
        if (i < size()) {
          *(ptr++) = *first++;
        } else {
          construct(last_++, *first++);
        }
      }
    } else {
      clear();
      for (InputIt head = first; head != last; ++head) {
        construct(last_++, *head);
      }
    }
  }

  reference at(size_type i) {
    if (i >= size()) {
      throw std::out_of_range("vector");
    }
    return first_[i];
  }

  const_reference at(size_type i) const {
    if (i >= size()) {
      throw std::out_of_range("vector");
    }
    return first_[i];
  }

  reference operator[](size_type i) { return first_[i]; }
  const_reference operator[](size_type i) const { return first_[i]; }
  reference front() { return *begin(); }
  const_reference front() const { return *begin(); }
  reference back() { return *(end() - 1); }
  const_reference back() const { return *(end() - 1); }
  pointer data() { return first_; }
  const_pointer data() const { return first_; }

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

  iterator insert(iterator pos, const value_type& val) {
    size_type offset = pos - begin();
    insert(pos, 1, val);
    return begin() + offset;
  }

  void insert(iterator pos, size_type n, const value_type& val) {
    if (n == 0) return;
    difference_type pos_dist = std::distance(begin(), pos);
    size_type new_size = size() + n;
    if (capacity() < new_size) {
      reserve(recommend_size(new_size));
      pos = begin() + pos_dist;
    }
    pointer new_last = last_ + n;
    construct_range(last_, new_last);
    std::copy_backward(pos, end(), new_last);
    std::fill(pos, pos + n, val);
    last_ = new_last;
  }

  template <class InputIt>
  void insert(iterator pos, InputIt first, InputIt last,
              typename ft::enable_if<!ft::is_integral<InputIt>::value,
                                     InputIt>::type* = NULL) {
    size_type n = std::distance(first, last);
    difference_type pos_dist = std::distance(begin(), pos);
    size_type new_size = size() + n;
    if (capacity() < new_size) {
      reserve(recommend_size(new_size));
      pos = begin() + pos_dist;
    }
    pointer new_last = last_ + n;
    construct_range(last_, new_last);
    std::copy_backward(pos, end(), new_last);
    std::copy(first, last, pos);
    last_ = new_last;
  }

  size_type recommend_size(size_type new_size) {
    size_type maxsize = max_size();
    if (maxsize < new_size) {
      throw std::length_error("vector");
    }
    size_type cap = capacity();
    if (maxsize / 2 <= cap) {
      return (maxsize);
    }
    return (std::max<size_type>(new_size, cap * 2));
  }

  iterator erase(iterator pos) { return (erase(pos, pos + 1)); }

  iterator erase(iterator first, iterator last) {
    size_type erase_size = std::distance(first, last);
    pointer new_last = last_ - erase_size;
    // ポインタにした方がめちゃ早い
    std::copy(last.base(), last_, first.base());
    destroy_range(new_last, last_);
    last_ = new_last;
    return first;
  }

  void swap(vector& other) {
    pointer tmp_first = other.first_;
    pointer tmp_last = other.last_;
    pointer tmp_reserved_last = other.reserved_last_;

    other.first_ = first_;
    other.last_ = last_;
    other.reserved_last_ = reserved_last_;
    first_ = tmp_first;
    last_ = tmp_last;
    reserved_last_ = tmp_reserved_last;
  }

  // iterator access
  iterator begin() { return first_; }
  iterator end() { return last_; }
  iterator begin() const { return first_; }
  iterator end() const { return last_; }

  // この4つ意味わからないので後ほど検討->reverse_iteratorのconstructorを使っている
  reverse_iterator rbegin() { return reverse_iterator(last_); }
  reverse_iterator rend() { return reverse_iterator(first_); }
  const_reverse_iterator rbegin() const { return reverse_iterator(last_); }
  const_reverse_iterator rend() const { return reverse_iterator(first_); }

  // ok
  void clear() {
    destroy_range(first_, last_);
    last_ = first_;
  }

  void reserve(size_type sz) {
    if (sz <= capacity()) return;
    if (sz > max_size()) {
      throw std::length_error(
          "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported "
          "size");
    }

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
      erase(begin() + sz, end());
    } else if (sz > size()) {
      // biger than current elems
      insert(end(), sz - size(), value);
    }
  }

  allocator_type get_allocator() const { return alloc_; }

 private:
  pointer first_;
  pointer last_;
  pointer reserved_last_;
  allocator_type alloc_;

  // helper functions
  pointer allocate(size_type n) {
    if (n > max_size()) {
      throw std::length_error("vector");
    }
    return alloc_.allocate(n);
  }

  void deallocate() { alloc_.deallocate(first_, capacity()); }

  void construct(pointer ptr) { alloc_.construct(ptr, T()); }

  void construct(pointer ptr, const_reference value) {
    alloc_.construct(ptr, value);
  }

  void construct_range(pointer first, pointer last) {
    for (pointer p = first; p < last; p++) {
      alloc_.construct(p);
    }
  }

  void destroy(pointer ptr) { alloc_.destroy(ptr); }

  void destroy_range(pointer first, pointer last) {
    for (pointer p = first; p < last; p++) {
      alloc_.destroy(p);
    }
  }
  // 最初使っていたが使うのやめた 一応コメントアウトで残しとく
  // void destroy_until(reverse_iterator rend) {
  //   for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last_)
  //     destroy(&*riter);
  // }
};

template <class T, class Alloc>
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (lhs.size() == rhs.size() &&
          ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end()));
}

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
  return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
  lhs.swap(rhs);
}

}  // namespace ft

#endif
