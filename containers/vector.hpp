#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {

template <class T>
class vector
{
    public:
        vector(T a, T b){
      (void)a;
      (void)b;
    };

        ~vector() {};
        vector(vector const &other){(void)other;};
        vector &operator=(vector const &other){(void)other;};

    private:
};
}

#endif
