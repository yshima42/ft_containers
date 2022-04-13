#ifndef VECTOR_HPP
#define VECTOR_HPP

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
      : first(NULL), last(NULL), reserved_last(NULL), alloc(alloc) {}

  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator())
      : first(NULL), last(NULL), reserved_last(NULL), alloc(alloc) {
    resize(count, value);
  }

  // need to add enable_if
  //template <class InputIt>
  //vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
  //    : first(NULL), last(NULL), reserved_last(NULL), alloc(alloc) {
  //  (void)first;
  //  (void)last;
  //  (void)alloc;
  //}

  // copy constructor
  vector(vector const& other) 
    : first(NULL), last(NULL), reserved_last(NULL), alloc(other.alloc) { 
    reserve(other.size());
    for (pointer dest = first, src = other.begin(), last = other.end(); src != last; ++dest, ++src) {
      construct(dest, *src);
    }
    last = first + other.size();
  }

  // destructor
  ~vector(){
    clear();
    deallocate();
  };

  vector& operator=(vector const& other) { (void)other; };

  // check size and capacity
  size_type size() const { return end() - begin(); }
  bool empty() const { return begin() == end(); }
  size_type capacity() const { return reserved_last - first; }

  // iterator access
  iterator begin() { return first; }
  iterator end() { return last; }
  iterator begin() const { return first; }
  iterator end() const { return last; }
  const_iterator cbegin() const { return first; }
  const_iterator cend() const { return last; }

  // この4つ意味わからないので後ほど検討->reverse_iteratorのconstructorを使っている
  reverse_iterator rbegin() { return reverse_iterator(last); }
  reverse_iterator rend() { return reverse_iterator(first); }
  const_reverse_iterator rbegin() const { return reverse_iterator(last); }
  const_reverse_iterator rend() const { return reverse_iterator(first); }

  void clear() { destroy_until(rend()); }

  void reserve(size_type sz) {
    if (sz <= capacity()) return;

    pointer ptr = allocate(sz);

    pointer old_first = first;
    pointer old_last = last;

    size_type old_capacity = capacity();

    first = ptr;
    last = first;
    reserved_last = first + sz;

    for (pointer old_iter = old_first; old_iter != old_last;
         ++old_iter, ++last) {
      //理解にはムーブセマンティクスを理解が必要
      construct(last, *old_iter);
    }

    for (reverse_iterator riter = reverse_iterator(old_last),
                          rend = reverse_iterator(old_first);
         riter != rend; ++riter) {
      destroy(&*riter);
    }
    alloc.deallocate(old_first, old_capacity);
  }

  void resize(size_type sz) {
    //smaller than current elems
    if (sz < size()) {
      difference_type diff = size() - sz;
      destroy_until(rbegin() + diff);
      last = first + sz;
    }
    //biger than current elems
  else if (sz > size()) {
      reserve(sz);
      for (; last != reserved_last; ++last) {
        construct(last);
      }
    }
  }

  void resize(size_type sz, const_reference value) {
    if (sz < size()) {
      difference_type diff = size() - sz;
      destroy_until(rbegin() + diff);
      last = first + sz;
    } else if (sz > size()) {
      reserve(sz);
      for (; last != reserved_last; ++last) {
        construct(last, value);
      }
    }
  }



 private:
  pointer first;
  pointer last;
  pointer reserved_last;
  allocator_type alloc;

  // helper functions
  pointer allocate(size_type n) { return alloc.allocate(n); }
  void deallocate() { alloc.deallocate(first, capacity()); }
  void construct(pointer ptr) { alloc.construct(ptr, 0); }
  void construct(pointer ptr, const_reference value) {
    alloc.construct(ptr, value);
  }
  void destroy(pointer ptr) { alloc.destroy(ptr); }
  void destroy_until(reverse_iterator rend) {
    for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last)
      destroy(&*riter);
  }
};
}  // namespace ft

#endif
