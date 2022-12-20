#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x;    // Произвольное число для которого хотим получить результат
    cin >> x;
    int u;
    for(int k = 0; pow(3, k) < x; k++){
        for(int l = 0; pow(3, k)*pow(5, l) < x; l++){
            for(int m = 0; pow(3, k)*pow(5, l)*pow(7,m) < x; m++){
                u=pow(3, k)*pow(5, l)*pow(7,m);
                cout <<u << endl;
            }
        }
    }

    return 0;
}
