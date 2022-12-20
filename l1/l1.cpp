#include <iostream>
#include <stack>

int main() {

 std::stack<char> s_stack;                                //основной стек для работы с данной строкой 
 std::string s_string;
 std::cout << "start:" << std::endl;                                //ввод заданной строки
    std::getline(std::cin,s_string);

    bool flag = false;                                        //флаг наличия хотя бы одной открывающей скобки
    for(int i = 0; i < s_string.length(); i++){
        char stap = s_string[i];
        if(stap == '(' || stap == '{' || stap == '['){
 s_stack.push(stap);
 flag = true;
 }else{
            int modifier;
            if(stap == ')')
 modifier = 1;
            else
 modifier = 2;

            if(s_stack.empty() || s_stack.top() != char((int)stap - modifier)){    // проверка стека на пустоту и сравнения стека с текущей скобкой
 std::cout << "0 " << std::endl;                            // вывод на экран "0", если строка не существует
 stap = 0;
                break;
 }else{

 s_stack.pop();
            }
        }
        if(!stap)
            break;
    }
    if(flag && s_stack.empty())
 std::cout << "1" << std::endl;                           //вывод на экран "1", если такая строка существует
}
