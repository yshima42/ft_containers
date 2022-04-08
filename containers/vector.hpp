#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  // typedefs
  typedef size_t size_type;

  //constructor
  vector() {}

  explicit vector(const Allocator& alloc) {
    (void)alloc;
  }

  explicit vector(size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator()) {
    (void)count;
    (void)value;
    (void)alloc;
  }

  template< class InputIt >
  vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() ) {
    (void)first;
    (void)last;
    (void)alloc;
  }

  vector(vector const &other) { (void)other; };

  ~vector(){};
  vector &operator=(vector const &other) { (void)other; };

 private:

};
}  // namespace ft

#endif
