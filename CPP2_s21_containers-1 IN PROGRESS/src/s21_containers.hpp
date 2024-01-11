#ifndef S21_CONTAINERS
#define S21_CONTAINERS

#include <iostream>
#include <exception>

template <typename T>//, class Alloc = std::allocator<T>>
class S21Vector {
    private:
        size_t size_, capacity_;
        T *arr;
        Alloc alloc;

    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;
        using traits= allocator_traits<Alloc>;
    
    private:
        void reserve_more_capacity(size_type size);
    public:

    // -----------------------К-О-Н-С-Т-Р-У-К-Т-О-Р-Ы------------------------------------------------------------------------------//
        S21Vector : size_(0U), capacity_(0U), arr(nullptr) {}                                              // дефолтный конструктор
        explicit S21Vector(size_type n) size_(n), capacity_(n), arr(n ? new T[n] : nullptr) {}   // параметризированный конструктор
        S21Vector(std::initializer_list<T>const &items);                                            // инициализируюший конструктор
        S21Vector(const S21Vector &v) : size_(v.size_), capacity_(v.capacity_), arr(v.arr) {};            // копирующий конструктор
        S21Vector(S21Vector &&v) : size_(v.size_), capacity_(v.capacity_), arr(v.arr)                           // move сonstructor
        {
            v.arr = nullptr;
            v.size_ = 0;
        }
        ~S21Vector(){ delete[] arr;}                                                                                  // деструктор

        S21Vector operator=(S21Vector &&v);                                                                    // присвоение с move
    // -----------------------------------------------------------------------------------------------------------------------------//


    // --------------------------VECTOR-ELEMENT-ACCESS------------------------------------------------------------------------------//
        T& at(size_t i);                                                              // доступ к элементу массива с проверкой границ
        T& operator[](size_t pos){return &arr[i]};                                                                   // перегрузка []
        const T& operator[](size_t pos)const {return &arr[i]};                                                       // перегрузка []                                    
        const T& front() const {return arr[0]};                                                          // доступ к первому элементу
        T& front(){return arr[0]};                                                                       // доступ к первому элементу
        const T& back()const{arr[size_ -1]};                                                          // доступ к последнему элементу
        T& back(){arr[size_ -1]};                                                                     // доступ к последнему элементу
        const T* data()const {return arr};                                                                        // доступ к массиву
        T* data(){return arr};                                                                                    // доступ к массиву
    // -----------------------------------------------------------------------------------------------------------------------------//

    
    // --------------------------VECTOR-CAPACITY------------------------------------------------------------------------------------//
        bool empty() const noexcept;
        size_t size()const noexcept {return size_};      //distance begin end
        size_t max_size()const noexcept{return std::numeric_limits<difference_type>::max()/ sizeof(value_type)};
        void reserve_more_capacity(size_t size);
        size_t capacity() const noexcept {return capacity_};
        void shrink_to_fit();
    // -----------------------------------------------------------------------------------------------------------------------------//

    
    // ---------------------------I-T-E-R-A-T-O-R-S---------------------------------------------------------------------------------//
        iteraror begin()noexcept{return arr}
        iterator end(){return arr + size_}
    // -----------------------------------------------------------------------------------------------------------------------------//

    
    // ---------------------------V-E-C-T-O-R---M-O-D-I-F-I-E-R-S-------------------------------------------------------------------//
        void clear() noexcept;
        interator insert(iterator pos, const_reference value);
        void erase(const_iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void swap(S21Vector& other) noexcept;
    // -----------------------------------------------------------------------------------------------------------------------------//

        template <typename T>
        bool S21Vector<T>::empty() const noexcept{
            if (begin() == end(){ //begin() == end()
                return true;
            } else {
                return false;
            }
        }

        template <typename T>
        void S21Vector<T>::shrink_to_fit(){
            if (capacity_ > size_){
                capacity_ = size_
            }
        }

        template <typename T>
        T& S21Vector<T>::at(size_t i){
            if (i => size_){
                throw std::out_of_range("element is out of the boundaries of the array")
            }
            return arr[i];
        }

        // const T& S21Vector<T>::front(){
        //     if(size_ == 0){
        //         return nullptr;
        //     } else {
        //         return arr[0];
        //     }
        // }

        // const T& S21Vector<T>::back(){
        //     if(size_ == 0){
        //         return nullptr;
        //     } else {
        //         return arr[size_ -1];
        //     }
        // }



        template <typename T>
        S21Vector S21Vector<T>::operator=(S21Vector &&v){
            this->~S21Vector(); ///переставить?
            if (&v != this){
                size_ = v.size_;
                capacity_ = v.capacity_;
                arr = v.arr; /// работает без перегрузки?
                v.size_ = 0;
                v.capacity_ = 0;
                v.arr = nullptr;
            }
            return *this
        }

        template <typename T>
        void S21Vector<T>::reserve_more_capacity(size_t size){
            if (size > capacity_){
                T *buff = new T [size];
                for (size_t i = 0; i < size_; ++i){
                    buff[i] = std:: move(arr[i]);
                }
                delete[arr];
                arr = buff;
                capacity_ = size_;
            }
        }

        template <typename T>
        S21Vector<T>::S21Vector(std::initializer_list<T>const &items) {
            arr = new T[items.size()];
            int i = 0;
            for (auto it = items.begin(); it != items.end(); it++){
                arr[i] = *it;
                i++;
            }
            size_ = items.size();
            capacity_ = items.size();

        };

        template <typename T>
        size_t S21Vector<T>::size(){
            return size_;
        }


        template <template T>
        void S21Vector<T>::push_back(const_reference x){
            if (size_==capacity_){
                reserve_more_capacity(size_ * 2);
            }
            arr[size_++] = x;
        }
    
        size_t size();
        
        // void push_back(T x);

        template <typename T>
        void S21Vector<T>::pop_back(){
            // arr[size_ - 1]->~T();
            size_--;
        }

        template <typename T>
        void S21Vector<T>::clear() noexcept{
            // for (int i = 0; i < size_; ++i){
            //     pop_back();
            // }
            size_ = 0;
        }

        template<typename T>
        void S21Vector<T>::erase(const_iterator pos){
            for (int i = pos; i < size_ - 1; ++i){
                T tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp; // какой тип данных сможет сломать  swap и удаление последнего
            }
            pop_back();
        }

        template<typename T>
        void S21Vector<T>::swap(S21Vector& other) noexcept {
            if(other.capacity_ > capacity_){
                reserve_more_capacity(other.capacity_);
            } else if (other.capacity_ < capacity_) {
                other.reserve_more_capacity(capacity_);
            }
            T* tmp = arr;
            arr = other.arr;
            other.arr = tmp;
            size_t tmp_size = size_;
            size_ = other.size_;
            other.size_ = tmp_size;
                // for(i = 0; i < other.size_; ++i){
                //     T tmp = arr[i];
                //     arr[i] = other.arr[i];
                //     other.arr[i] = T tmp;
                // }
        }

        template<typename T>
        iterator S21Vector<T>::insert(const_iterator pos, const_reference value){
            if (size_ == capacity_){
                reserve_more_capacity(size_ * 2);
            }
            for(int i = ++size_ - 1 ; i > pos; i--){
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            return begin() + pos;
        }
    /// reserve без аллокатора
        // void reserve(size_t new_capacity){ /// выделение памяти
        //     if (new_capacity <= capacity_){
        //         return;
        //     }

        //     T* newarr = reinterpret_cast<T*>(new char[new_capacity * sizeof(T)])
        //     size_t index = 0;
        //     try
        //     {
        //         for(; index < size_; ++index){
        //             new(newarr + index) T(arr_[index])
        //         }
        //     }
        //     catch(...)
        //     {
        //         for(size_t i = 0; i < index; ++i){
        //             (newarr + i)->~T();
        //         }
        //         delete [] reinterpret_cast<char*> (newarr);
        //         throw;
        //     }
        //     arr_ = newarr;
        //     capacity_ = new_capacity
            
        // }
 

        // push back с аллокатором
        // void push_back(const T& x){
        //     if (size_ == capacity_){
        //         reserve(capacity_ > 0 ? capacity_ * 2 : 1);
        //     }
        //     if (size_ < capacity_){
        //         traits::construct(alloc, arr + sz++, x);
        //         return;
        //     } else{
        //         T* new_arr = traits::allocate(alloc, capacity_ * 2);
        //         for (int i = 0; i < capacity_; ++i){
        //             traits::construct(alloc, new_arr + i, arr[i])
        //         }
        //         traits:construct(alloc, new_arr + capacity_, x);в
        //         for (int i = 0; i < capacity_; ++i){
        //              traits::destroy(alloc,arr + i)
        //         }
        //         traits:deallocate(arr, capacity_);
        //         arr = new_arr;
        //         capacity_*=2;//(cap<<=1)
        //     }
        // }
        

        /// конструктор копирования///
        // traits::select_on_container_copy_constraction(alloc)


        // // перегрузка []
        // T& operator[](size_t i){
        //     return arr[i]
        // }
        // const T& operator[](size_t i)const{
        //     return arr[i]
        // }



};



#endif

//https://en.cppreference.com/w/cpp/container/vector