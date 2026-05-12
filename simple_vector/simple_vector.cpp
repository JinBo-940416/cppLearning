
template <typename T>
class SimpleVector {
private:
    T* data_;
    size_t capacity_;
    size_t size_;

public:
    // default constructor
    SimpleVector() : data_{std::nullptr}, capacity_{0}, size_{0} {

    }

    // copy constructor
    SimpleVector(const SimpleVector& other) : data_{std::null_ptr}, capacity_{0}, size_{0} {
        if (other.size > 0) {
            T* raw_memory = ::operator new(other.size * sizeof(T));
            for (int i = 0; i < other.size_; i++) {
                try {
                    new (&data_[i]) T(other[i]);
                    size_++;
                } catch (...) {

                    throw;
                }
            }
            capacity_ = other.capacity_;
        }
    }

private:
    T* allocate(int number) {
        return std::static_cast<T *> ::operator new(sizeof(T) * number);
    }

    void deallocate(T* memory) {
        ::operator delete(memory);
    }

    destroy_all() {
        for (int i = 0; i < size_; i++) {
            data[i].~T();
        }
    }
}