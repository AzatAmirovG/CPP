#include <vector>
// #include "s21_array.h"
#include "s21_list_no_allocators copy.h"

int main() {
// ---------ARRAY--------------------------------------------------------------------------------------------------------------------//
    // s21::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // s21::array<int, 10> arr2{1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    // s21::array<int, 0> arr1;

    // for (auto num : arr) {
    //     std::cout << num << ' ';
    // }
    // std::cout<<'\n'<< arr.at(9);
    // std::cout<<'\n'<< arr[9];
    // std::cout<<'\n'<< arr[11];
    // std::cout<<'\n'<< arr.front();
    // std::cout<<'\n'<< arr.back();
    // std::cout<<'\n'<< arr.distance(arr.begin(), arr.end());
    // std::cout<<'\n'<< arr.size();
    // std::cout<<'\n'<< arr.max_size();
    // std::cout<<'\n'<< arr.empty();
    // std::cout<<'\n'<< arr1.empty();
    // arr.swap(arr2);
    // for (auto num : arr) {
    //     std::cout << num << ' ';
    // }

// ---------LIST--------------------------------------------------------------------------------------------------------------------//
    s21::list<int> l{1, 2, 3, 4, 5, 6, 7};
    s21::list<int> l3{7, 6, 5, 4, 3};
    // s21::list<int> l();
    s21::list<int> l2;
    for (auto num : l) {
        std::cout << num << ' ';
    }
    // s21::list<int>();
    std::cout<<"back is  " <<l.back()<< '\n';
    std::cout<<"front is  " <<l.front()<< '\n';
    std::cout<<"empty is  " <<l.empty()<< '\n';
    std::cout<<"empty of l2 is " <<l2.empty()<< '\n';
    std::cout<<"size is  " <<l.size()<< '\n';
    std::cout<<"maxsize is  " <<l.max_size()<< '\n';
    l.pop_back();
    for (auto num : l) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    l.push_back(7);
    for (auto num : l) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    // l.clear();
    // std::cout <<"size after clear is " <<l.size()<<'\n';
    auto it = l.begin();
    ++it;
    l.insert(l.begin(), 1);
    for (auto num : l) {
        std::cout << num << ' ';
    }
    // std::cout << typeid(l.begin()).name() << '\n';
    std::cout << '\n';

    // l.swap(l);
    // for (auto num : l) {
    //     std::cout << num << ' ';
    // }

    // l.merge(l3);
    l.reverse();
    for (auto num : l) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    l.unique();
    l.sort();
    for (auto num : l) {
        std::cout << num << ' ';
    }
    return 0;

}