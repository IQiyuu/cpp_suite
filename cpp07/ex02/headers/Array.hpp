#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <cstdlib>

template<typename T>
class Array {

    private:
        T               *_array;
        unsigned int    _size;

    public:
        Array( void ): _size(0) {
            std::cout << "Array \033[32mcreated\033[0m" << std::endl;
            this->_array = new T[_size];
        }

        Array( unsigned int size ): _size(size) {
            std::cout << "Array \033[32mcreated\033[0m" << std::endl;
            this->_array = new T[_size];
        }

        Array( Array const &ref ): _size(ref._size) {
        	std::cout << "Copy Constuctor called" << std::endl;
			this->_array = NULL;
			*this = ref;
        }

		unsigned int size( void ) {
			return _size;
		}

        Array &operator=( Array const &ref ) {
			if (this->_array != NULL)
				delete[] this->_array;
			if (ref._size != 0)
			{
				this->_size = ref._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = ref._array[i];
			}
			return (*this);
		}

        T &operator[]( unsigned int index ) {
			if (index >= this->_size || this->_array == NULL) {
				throw Array<T>::InvalidIndexException();
			}
			return (this->_array[index]);
		}

        ~Array( void ) {
            std::cout << "Array \033[31mdeleted\033[0m" << std::endl;
            delete[] this->_array;
        }

        class	InvalidIndexException : public std::exception {
		    public:
			    virtual const char	*what() const throw();
		};
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw() {
	return ("Error: Invalid index");
}

#endif