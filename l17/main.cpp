#include<iostream>
#include <string>
using namespace std;
class Tree
{
public:
    int value;
    Tree* parent;         // поле ссылка на родителя
    Tree* left;          // поле ссылка на левого потомка
    Tree* right;         // поле ссылка на правого потомка
    std::string string;                  // для линейно-скобочной записи.

    Tree(const int v, Tree* p){      // алгоритм, который позволяет положить значение в виде листа одного из узлов
        value = v;
        parent = p;
    }
    Tree(){}
    Tree(std::string str){
        string = str;
    }

    void add(const int v){             // Метод добавления значения в дерево
        if (v > value){                  // Если новое значение больше значения узла добавляем в правое поддерево, или создаем это поддерево если его нет
            if (right == nullptr){
                right = new Tree(v, this);
            }
            else{
                right->add(v);
            }
        }
        else{                             // иначе добавляем в левое поддерево, или создаем это поддерево если его нет
            if (right == nullptr){
            if (left == nullptr){
                left = new Tree(v, this);
            }
            else{
                left->add(v);
            }
        }
    }

    Tree* search(Tree* item, int v)         // поиск поддерева по элементу
    {
        if (item == nullptr && item->value == v)
        {
            return item;
        }
        if (item != nullptr && item->value > v)
        {
            return search(item->left, v);
        }
        if (item != nullptr && item->value < v)
        {
            return search(item->right, v);
        }
    }

    Tree* Search(int v){
        return search(this, v);
    }
//удаления элемента делится на несколько случаев:у узла нет дочерних узлов; у узла есть левый дочерних узлов;у узла есть правый дочерних узлов; у узла есть оба ребёнка.
//В первом просто удаляем узел.В случае 2 и 3 заменяем удаляемый узел на его потомка,на этом удаление заканчивается.
//Случай 4, для этого необходимо найти в правом поддереве минимальный элемент и переместить его на место удаляемого узла.
    void remove(int value){
        Tree* item = this->Search(value);
        if (item == nullptr) return;      // если такого элемента нет удалять не нужно
        Tree* currentTree = nullptr;
        // удаление корня
        if (this == item){
            if (item->right != nullptr){    // если есть правое поддерево, тогда ищем в нём самый наименьший элемент(левый)
                currentTree = item->right;
                while (currentTree->left != nullptr){
                    currentTree = currentTree->left;
                }

            }
            else if (item->left != nullptr){   // если есть только левое дерево, тогда ищем в нём самый наименьший элемент(правый)
                currentTree = item->left;
                while (currentTree->right != nullptr){
                    currentTree = currentTree->right;
                }
            }

            int val = currentTree->value;
            remove(val);
            item->value = val;

        }
        else if (item->left == nullptr && item->right == nullptr && item->parent != nullptr){         // удаление листьев
            if (item->parent->right == item){
                item->parent->right = nullptr;
            }
            else{
                item->parent->left = nullptr;
            }
        }
        else if (item->left != nullptr && item->right == nullptr && item->parent != nullptr){       // удаление узла, который имеет левого потомка
            item->left->parent = item->parent;
            if (item == item->parent->left){
                *item->parent->left = *item->left;
            }
            else if (item == item->parent->right){
                *item->parent->right = *item->left;
            }

        }
        else if (item->left == nullptr && item->right != nullptr && item->parent != nullptr){      // удаление узла, который имеет правого потомка.
            item->right->parent = item->parent;
            if (item == item->parent->left){
                *item->parent->left = *item->right;
            }
            else if (item == item->parent->right){
                *item->parent->right = *item->right;
            }

        }
        else if (item->left != nullptr && item->right != nullptr && item->parent != nullptr){       // удаление узла, который имеет оба потомка.
            currentTree = item->right;
            if (currentTree->left != nullptr){
                while (currentTree->left != nullptr){
                    currentTree = currentTree->left;
                }
                if (currentTree->right != nullptr){
                    currentTree->right->parent = currentTree->parent;
                    currentTree->parent->left = currentTree->right;
                }
                else{
                    currentTree->parent->left = nullptr;
                }
                item->left->parent = currentTree;
                currentTree->left = item->left;
                if (item->parent->right == item){
                    currentTree->parent = item->parent->right;
                    item->parent->right = currentTree;
                }
                else{
                    currentTree->parent = item->parent->left;
                    item->parent->left = currentTree;
                }
                currentTree->right = item->right;
                item->right->parent = currentTree;
            }
            else{
                item->left->parent = currentTree;
                currentTree->left = item->left;
                currentTree->parent = item->parent;
                if (item->parent->left == item){
                    item->parent->left = currentTree;
                }
                else{
                    item->parent->right = currentTree;
                }
            }

        }


    }
    std::string toString(int value)        // переводит число в строку
    {
        std::string result;

        if (value > 9){
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else{
            result += char(value + 48);
        }

        return result;
    }
    void print(Tree* tree)                // переводит дерево в линейно-скобочуню запись
    {
        string += toString(tree->value);
        if (tree->left != nullptr || tree->right != nullptr){
            string += '(';
            if (tree->left != nullptr){
                print(tree->left);
            }
            string += ',';
            if (tree->right != nullptr){
                print(tree->right);
            }
            string += ')';
        }

    }
    void Print(){print(this);}

    bool isDigital(const char elem){return (elem >= '0' && elem <= '9') ? true : false;}

    Tree parse(std::string str)
    {
        Tree result;
        int index;
        if (isDigital(str[0]) && isDigital(str[1])){
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isDigital(str[0]) && !isDigital(str[1])){
            int val = str[0] - 48;
            result.value = val;
            index = 1;
        }


        for (int i = index; i < str.size() - 1;){
            if (isDigital(str[i]) && isDigital(str[i + 1])){
                int value = (str[i] - 48) * 10 + str[i + 1] - 48;
                result.add(value);
                i += 2;
            }
            else if (isDigital(str[i]) && !isDigital(str[i + 1])){
                int value = str[i] - 48;
                result.add(value);
                i++;
            }
            else{
                i++;
            }
        }
        return result;
    }
};



int main()
{
    string str = "8(3(1,6(4,7)),10(,14(13,)))";
    Tree tree;
    tree = tree.parse(str);
    Tree newTree = tree;
    newTree.remove(10);
    newTree.Print();
    for (auto& value : newTree.string){cout << value;}
    return 0;
}
