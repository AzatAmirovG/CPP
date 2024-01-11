#ifndef S21_RED_BLACK_TREE
#define S21_RED_BLACK_TREE

#include <iostream>
#include <exception>

// using namespace s21

namespace s21 {

template <typename Key, typename T>
struct Node{
    private:
        Key key;
        T value;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        bool isRed = 0;
    // Node(Key key, T value): key(key), isRed(false), parent(nullptr), left(nullptr), right(nullptr){}
    public:
        Node(Key key, T value): key(key), value(value) {}
        Node(){};
        ~Node(){};
        Node(const Node& other): key(other.key), value(other.value), isRed(other.isRed),
        parent(other.parent), left(other.left), right(other.right){};
    
    public:
        T& get_value() const noexcept;
        void set_value(T &val) noexcept;

    private:
        friend class S21Tree<Key, T>;

};

template <typename Key, typename T>
T& Node<Key, T>::get_value() const noexcept{
    return value;
}

template <typename Key, typename T>
void Node<Key, T>::set_value(T &val) noexcept{
    value = val;
};


template <typename Key, typename T>
class S21Tree{
    private:
        Node* root;
    // public:
    //     using value_type = T;
    //     using reference = T &;
    //     using const_reference = const T &;
    //     using iterator = T *;
    //     using const_iterator = const T *;
    //     using size_type = size_t;
    //     using traits= allocator_traits<Alloc>;

    public:
        S21Tree(): root(nullptr){};
        // void insert(Key key);

    public:
        class tree_iterator;
        using iterator = typename S21Tree<Key, T>::tree_iterator;

};

template <typename Key, typename T>
class S21Tree<Key, T>::tree_iterator {
    public:
        tree_iterator(): node_(nullptr), tree(nullptr) {};
        tree_iterator(S21Tree<Key, T> tree, Node<Key, T> node): node_(node), tree_(tree){};
        ~tree_iterator(){};
    
    public:
        bool operator==(const iterator& other);
        bool opetator!=(const iterator& other);
        iterator& operator++();
        iterator& operator++(int value);
        iterator& operator--();
        iterator& operator--(int value);

    private:
        Node<Key, T>* node_;
        S21Tree<Key, T>* tree_;
};

template<typename Key, typename T>
bool S21Tree<Key, T>::iterator::operator==(const iterator& other){
    ;
}



}



#endif