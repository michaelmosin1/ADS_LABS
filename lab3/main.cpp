#include <iostream>
#include <set>


void print_all_required_numbers(size_t current_point, size_t end_point, std::set<size_t> &massive){
    if (current_point < end_point){
        massive.insert(current_point);
        print_all_required_numbers(current_point*3, end_point, massive);
        print_all_required_numbers(current_point*5, end_point, massive);
        print_all_required_numbers(current_point*7, end_point, massive);
    }
    return;
}

int main(){
    size_t x;
    std::cout << "Введите X: ";
    std::cin >> x;
    std::set<size_t> massive;
    if (x >= 1){
        print_all_required_numbers(1, x, massive);
        for (size_t i : massive) std::cout << i << ' ';
        std::cout << std::endl;
    }
    else std::cout << "Ошибка ввода! X должен быть больше или равен 1" << std::endl;
    return 0;
}