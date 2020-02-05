#include<iostream>
#include<algorithm>
int quantity[10001] = { 0, };
int changable[10001] = { 0, };


int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> quantity[i];
         changable[i] = quantity[i];
    }

    changable[1] = quantity[0] + quantity[1];
    changable[2] = std::max({changable[0]+quantity[2], quantity[1]+ quantity[2], changable[1]});
    //changable[1] 를 max 값에서 비교대상이 되는것이 포인트
    //무조건적으로 그 위치에 해당하는 값이 플러스 되지는 않음!

    for (int i = 3; i < n; i++) {
        changable[i] = std::max({changable[i-1],changable[i-2]+quantity[i],changable[i-3]+quantity[i-1]+quantity[i]});
        //changable[i-1] 를 max 값에서 비교대상이 되는것이 포인트
    }

    std::cout << changable[n-1] << std::endl;

    return 0;
}

// #include<iostream>
// #define MAX(a,b) ((a)>=(b)?(a):(b))
// int quantity[10001] = { 0, };
// int changable[10001] = { 0, };


// int main() {
//     int n;
//     std::cin >> n;

//     for (int i = 0; i < n; i++) {
//         std::cin >> quantity[i];
//          changable[i] = quantity[i];
//     }

//     changable[1] = quantity[0] + quantity[1];
//     changable[2] = MAX(changable[0], quantity[1]) + quantity[2]; 

//     for (int i = 3; i < n; i++) {
//         if (changable[i - 1] != quantity[i - 1] + changable[i - 3]) {
//             if(i==3)  changable[i] = MAX(changable[i - 2], quantity[i - 1] + changable[i - 3]) + quantity[i];
//             else changable[i] = MAX(changable[i - 2], quantity[i - 1] + MAX(changable[i - 4], changable[i - 3])) + quantity[i];
//         }
//         else
//             changable[i] = changable[i - 1] + quantity[i]; 
//     }

//     int max = 0;

//     if (n >= 3) max = MAX(changable[n - 1], changable[n - 2]);
//     else max = changable[n - 1];

//     std::cout << max << std::endl;

//     return 0;
// }