#include <iostream>
#include <string>

using namespace std;

bool check_correct_line(string bracket_line, size_t start, size_t end){
    bool line_is_correct = true;
    if (end == start) return false;
    else for (size_t i = 0; i < end-1; i++){
        if (bracket_line[i] == '('){
            if (bracket_line[i+1] == ')') line_is_correct = true;
            else for (size_t j = i + 1; j < end; j++){
                if (bracket_line[j] == ')'){
                line_is_correct = check_correct_line(bracket_line, i, j);
                break;
                }
                line_is_correct = false;
            }
        }
        else if (bracket_line[i] == '['){
            if (bracket_line[i+1] == ']') line_is_correct = true;
            else for (size_t j = i + 1; j < end; j++){
                if (bracket_line[j] == ']'){
                    line_is_correct = check_correct_line(bracket_line, i, j);
                    break;
                }
                line_is_correct = false;
            }
        }
        else if (bracket_line[i] == '{'){
            if (bracket_line[i+1] == '}') line_is_correct = true;
            else for (size_t j = i + 1; j < end; j++){
                if (bracket_line[j] == '}'){
                    line_is_correct = check_correct_line(bracket_line, i, j);
                    break;
                }
                line_is_correct = false;
            }
        }
        else return line_is_correct;
    }
    return line_is_correct;
}
int main(){
    string input_line;
    cout << "Введите строку: ";
    cin >> input_line;
    if (check_correct_line(input_line, 0, input_line.length())){
        cout << "Строка существует" << endl;
    }
    else cout << "Строка не существует" << endl;
    return 0;
}