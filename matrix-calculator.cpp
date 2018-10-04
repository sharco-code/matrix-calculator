#include <iostream>

int main(void) {

    int a[2][2], b[2][2], c[2][2];
    char turn[2] = {'a', 'b'};
    int menu;
    bool is_operative;

    for (int x = 0; x < 2; x++) {
        std::cout << "Matrix " << turn[x] << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << (i+1) << "-" << (j+1) << ":";
                if(turn[x] == 'a') {
                    std::cin >> a[i][j];
                } else {
                    std::cin >> b[i][j];
                }
            }    
        }
    }

    for (int x = 0; x < 2; x++) {
        std::cout << "\nMatrix " << turn[x] << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if(turn[x] == 'a') {
                    std::cout << " " << a[i][j];
                } else {
                    std::cout << " " << b[i][j];
                }
            }    
            std::cout << std::endl;
        }
    }
    
    do {
        std::cout << "\nAdd(1), Substract(2), Multiply(3):";
        std::cin >> menu;
        switch (menu) {
            case 1:
                is_operative = true;
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {
                            c[i][j] = a[i][j] + b[i][j];
                        }    
                    }
                break;
            case 2:
                is_operative = false;
                std::cout << "coming soon..";
                //coming soon
                break;
            case 3:
                is_operative = false;
                std::cout << "coming soon..";
                //coming soon
                break;
            default:
                std::cout << "Incorrect option";
        }
    } while (menu != 1/* && menu != 2 && menu != 3 */);

    //show results
    if (is_operative) {
        std::cout << "\nResult " << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << " " << c[i][j];
            }    
            std::cout << std::endl;
        }
    }
    
    
    return 0;
}
// by sharco 
// https://github.com/sharco-code
