#ifndef S21_MAP
#define S21_MAP

#include <iostream>
#include <exception>
#include <limits>

namespace s21{
template<typename Key, typename T>
class map{
    public:
        class Node;
        class map_iterator;
    public:
      using key_type = Key;
      using mapped_type = T;
      using value_type = std::pair<const key_type, mapped_type>;
      using reference = value_type &;
      using const_reference = const value_type &;
      using iterator = map_iterator;
      using const_iterator = const map_iterator;
      using size_type = size_t;
    private:
        Node* node_;
        Node* begin_;
        int size_;

    class Node{
        private:
            Node* left;
            Node* right;
            Node* parent;
            bool red;
            value_type key_value_;
    };

    class map_iterator{
        public:
            Node* pos_;
        public:
            map_iterator():pos_(nullptr){}
            map_iterator(Node* pos): pos_(pos){}
            map_iterator(const map_iterator &other): pos_(other.pos_){}

            map_iterator operator++(){
                if (pos_->right === nullptr){
                    if(pos->parent_->right == pos_){
                        pos_ = pos_->parent_->parent_;
                    } else{
                        pos_ = pos_->parent_;
                    }
                }else{
                    pos_ = pos_->right_;
                }
                return pos_;
            }
            
            map_iterator operator--(){
                if(pos_ =! begin()){
                    if (pos_->left == nullptr){
                        if (pos_->parent_->left_ == pos_){
                            pos_= pos_->parent_->parent_;
                        } else{
                            pos_ = pos_->parent_; 
                        }
                    } else{
                        pos_ = pos_->left_;
                    }
                }
                return pos_;
            }

            map_iterator operator++(int){
                map_iterator tmp(*this);
                if (pos_->right === nullptr){
                    if(pos->parent_->right == pos_){
                        pos_ = pos_->parent_->parent_;
                    } else{
                        pos_ = pos_->parent_;
                    }
                }else{
                    pos_ = pos_->right_;
                }
                return tmp;
            }

            map_iterator operator--(int){
                map_iterator tmp(*this);
                if(pos_ =! begin()){
                    if (pos_->left == nullptr){
                        if (pos_->parent_->left_ == pos_){
                            pos_= pos_->parent_->parent_;
                        } else{
                            pos_ = pos_->parent_; 
                        }
                    } else{
                        pos_ = pos_->left_;
                    }
                }
                return tmp;
            }

            bool operator==(const map_iterator &other){
                return (pos_ == other.pos_);
            }

            bool operator!=(const map_iterator &other) {
                return (pos_ != other.pos_);
            }

            reference operator*() {return pos_->key_value_;}
            //begin возвращает указатель на наименьший элемент(самый левый сын)
            //end фейковая вершина декремент которой(left) дает самого правого сына,
                //increment(parent) дает самого левого?
                // end это парент у корня? 
            // обычный инкремент должен идти в правого сына и найти самого левого подсынаб если его нет то уйти в родителя и так далее 

    };



};
}

#endif