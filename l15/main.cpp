#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Tree
{
public:
	int value;
	Tree* parent;        // поле ссылка на родителя
	Tree* left;          // поле ссылка на левого потомка
	Tree* right;         // поле ссылка на правого потомка
	string string;                 // для линейно-скобочной записи.
    Tree(const int v, Tree* p) {    // это алгоритм, который позволяет положить значение в виде листа одного из узлов
        value = v;
        parent = p;
    }

    Tree(){}

    Tree(std::string str){string = str;}

    void add(const int v) {       // алгоритм добавления значения в дерево
        if (v > value) {                // Если новое значение больше значения узла добавляем в правое поддерево, или создаем это поддерево если его нет
            if (right == nullptr){
                right = new Tree(v, this);
            }
            else {
                right->add(v);
            }
        }
        else {
            if (left == nullptr){           //добавляем в левое поддерево, или создаем это поддерево если его нет
                left = new Tree(v, this);
            }
            else{
                left->add(v);
            }
        }
    }

    std::string toString(int value){            // переводит число в строку
        std::string result;
        if (value > 9) {
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else{
            result += char(value + 48);
        }

        return result;
    }


    void print(Tree* tree){                 // переводит дерево в линейно-скобочуню запись
        string += toString(tree->value);     // добавляем значение текущего узла
        if (tree->left != nullptr || tree->right != nullptr{
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

    bool isDigital(const char elem){return (elem >= '0' && elem <= '9') ? true : false;}    //проверка, является ли строка числом

    Tree parse(std::string str){
        Tree result;
        int index;
        if (isDigital(str[0]) && isDigital(str[1])){      // Если в числе 2 разряда переводим его в число
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isDigital(str[0]) && !isDigital(str[1])){    // иначе одноразрядное число переводим в цифру
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

void direct(vector <int>& v, const Tree* tree)            // прямой обход, здесь напрявляемся по левой ветке, а потом по правой рекурсивным образом
                                                          // т.е просто проходим по всем возможным развилкам, сначала влево, потом вправо
{
    if (tree != nullptr){
        v.push_back(tree->value);
        direct(v, tree->left);
        direct(v, tree->right);
    }
}

void center(vector<int>& v, const Tree* tree)                  //кольцевой обход, мы сначала обходим левое поддерево, а затем пишем в вектор значения листьев
                                                               //дальше совершаем правый обход и т.о.извлеченные данные будут отсортированными
{
    if (tree != nullptr){
        center(v, tree->left);
        v.push_back(tree->value);
        center(v, tree->right);
    }
}

void reverse(vector<int>& v, const Tree* tree)                   // алгоритм обратного обхода противоположный прямому, мы сначала проходим левое дерево, потом правое
                                                                 //и только потом пишем значения а данные получим соответственно в обратном порядке от прямого обхода
{
    if (tree != nullptr){
        reverse(v, tree->left);
        reverse(v, tree->right);
        v.push_back(tree->value);
    }
}

int main()
{
    vector <int> directValues;
    vector <int> centerValues;
    vector <int> reverseValues;
	int maxElem;
    string str = "8(3(1,6(4,7)),10(,14(13,)))";
    Tree tree;
    tree = tree.parse(str);
    Tree newTree = tree;
    newTree.Print();
    direct(directValues, &newTree);    //прямой обход
    center(centerValues, &newTree);     //кольцевой обход
    reverse(reverseValues, &newTree);   //обратный обход
    for (auto& value : reverseValues){cout << value<<"\t";}
    return 0;
}
