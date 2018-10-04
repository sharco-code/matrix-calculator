#include <iostream>

void *add(int a[][2], int b[][2]) {
    int (*res)[2] = new int[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }    
    }

    return res;
}

void *substract(int a[][2], int b[][2]) {
    int (*res)[2] = new int[2][2];

    std::cout << "comming soon.." << std::endl;

    return res;
}

void *multiply(int a[][2], int b[][2]) {
    int (*res)[2] = new int[2][2];

    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(j==0) {
                if(i==0) {
                    res[i][j] = (a[i][j] * b[i][j]) + (a[i][j+1] * b[i+1][j]);
                } else {
                    res[i][j] = (a[i][j] * b[i-1][j]) + (a[i][j+1] * b[i][j]);
                }   
            } else {
                if (i==1) {
                    res[i][j] = (a[i][j-1] * b[i-1][j]) + (a[i][j] * b[i][j]);
                } else {
                    res[i][j] = (a[i][j] * b[i][j]) + (a[i+1][j] * b[i+1][j]);
                }
            }
        }
    }

    return res;
}

void print(int result[][2], bool x) {
    
    //show results
    if (x) {
        std::cout << "\nResult " << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << " " << result[i][j];
            }    
            std::cout << std::endl;
        }
    }

}

int main(void) {

    int a[2][2], b[2][2];
    int (*c)[2] = new int[2][2];
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
                c = (int (*)[2]) add(a, b);
                break;
            case 2:
                is_operative = false;
                std::cout << "Comming soon.." << std::endl;
                break;
            case 3:
                is_operative = true;
                c = (int (*)[2]) multiply(a, b);
                break;
            default:
                std::cout << "Incorrect option";
        }
    } while (menu < 1 || menu > 3);
    print(c, is_operative);

    return 0;
}
// by sharco 
// https://github.com/sharco-code
