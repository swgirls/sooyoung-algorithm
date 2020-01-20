#include<iostream>
#include<string.h>
#define MAX(a,b) ((a)>=(b)?(a):(b))


int getMaxAdding(int Triangle[502][502], int T) {

    int result = 0;

    int MaxAdd[502][502] = {0,};

    MaxAdd[1][1] = Triangle[1][1];

    for(int i = 1; i<=T; i++){
        for(int location=1; location<=i; location++){
            MaxAdd[i][location] = MAX(MaxAdd[i-1][location-1],MaxAdd[i-1][location]) + Triangle[i][location];
        }
    }

    for(int location = 1; location<=T; location++){
        if(result<MaxAdd[T][location]) result = MaxAdd[T][location];
    }

    
        // for (int i = T-1; i >=1; i--) {
        //     for (int location = 1; location <= i; location++) {
        //         Triangle[i][location] = MAX(Triangle[i + 1][location], Triangle[i + 1][location + 1]) + Triangle[i][location];
        //     }
        // }

    // return Triangle[1][1];
    return result;

}

int main() {
    int T;
    std::cin >> T;
    int Triangle[502][502];

    for (int i = 1; i < T + 1; i++) {
        for (int j = 1; j <= i; j++) {
            std::cin >> Triangle[i][j];
        }
    }
    std::cout << getMaxAdding(Triangle, T) << std::endl;

    return 0;

}