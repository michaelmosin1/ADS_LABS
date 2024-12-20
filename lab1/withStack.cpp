#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

struct Stack{
    char* _massive;
    size_t _length;
    size_t _size;
    Stack(){
        _massive = nullptr;
        _size = 0;
        _length = 0;
    }
    Stack(size_t size){
        if (size != 0) _massive = new char[size];
        else _massive = nullptr;
        _size = size;
        _length = 0;
    }
    ~Stack(){
        delete[] _massive;
    }
    void push(char element){
        _massive[_length] = element;
        _length++;
    }
    void pop(){
        _length--;
    }
    bool isEmpty(){
        if ((_length == 0) || (_massive == nullptr)) return true;
        else return false;
    }
};

int main(){
    string inputLine;
    cout << "Введите строку" << endl;
    cin >> inputLine;
    Stack myStack(inputLine.length());
    char previous_symbol = '\0';
    bool isCorrect = true;
    for (size_t i = 0; i < inputLine.length() && isCorrect; i++){
        if ((inputLine[i] == '(') || (inputLine[i] == '[') || (inputLine[i] == '{')){
            myStack.push(inputLine[i]);
            previous_symbol = inputLine[i];
        }
        else if (inputLine[i] == ')'){
            if (previous_symbol == '(') myStack.pop();
            else isCorrect = false;
        }
        else if (inputLine[i] == ']'){
            if (previous_symbol == '[') myStack.pop();
            else isCorrect = false;
        }
        else if (inputLine[i] == '}'){
            if (previous_symbol == '{') myStack.pop();
            else isCorrect = false;
        }
        else isCorrect = false;
    }
    if (isCorrect && myStack.isEmpty()) cout << "Строка существует" << endl;
    else cout << "Строка не существует" << endl;
    return 0;
}