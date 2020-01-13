// #include<iostream>
// #include<string.h>
// #define min(a,b) a>b?b:a

// int resultCost = 0;
// int minTempx = 0;
// int minCost = 1000;
// int minTempy = 0;
// int minTempxx = 0;
// int minTempyy = 0;

// int getSmallCost(int** cost, int** found, int N, int I) {

//     found[0][0] = cost[0][0];
//     found[0][1] = cost[0][1];
//     found[0][2] = cost[0][2];


//     for (int i = 1; i < N + 1; i++)
//     {
//         found[i][0] = min(found[i - 1][1], found[i - 1][2]) + cost[i][0];
//         found[i][1] = min(found[i - 1][0], found[i - 1][2]) + cost[i][1];
//         found[i][2] = min(found[i - 1][0], found[i - 1][1]) + cost[i][2];
//     }
//     return  min(min(found[N][0], found[N][1]),found[N][2]);
   

//     if (N == 0) return 0;

//     if (I == N) {

//         for (int i = 0; i < I; i++) {
//             for (int j = 0; j < 3; j++) {
//                 if (minCost > cost[i][j]) {
//                     minCost = cost[i][j];
//                     minTempxx = i;
//                     minTempyy = j;
//                 }
//             }
//         }
//         resultCost += minCost;
//         //페인트 칠한 cost 값은 이미 거쳤다는 표시를 해줘야함.
//         found[minTempxx][minTempyy] = N;
//         getSmallCost(cost, found, N - 1, I);

//     }

//     else {
//         minCost = 1000;

//         for (int i = 0; i < I; i++) {
//             if (i != minTempxx) {
//                 for (int j = 0; j < 3; j++) {
//                     if (found[i][j] == 0 && minCost > cost[i][j]) {
//                         if (i - minTempxx == 1 || i - minTempxx == -1) {
//                             if (j != minTempyy) {
//                                 minCost = cost[i][j];
//                                 minTempx = i;
//                                 minTempy = j;
//                             }
//                         }
//                         else {
//                             minCost = cost[i][j];
//                             minTempx = i;
//                             minTempy = j;
//                         }
//                     }
//                 }
//             }
//         }
//         minTempxx = minTempx;
//         minTempyy = minTempy;

//         found[minTempxx][minTempyy] = N;
//         resultCost += minCost;

//         if(N>=2) getSmallCost(cost, found, N - 1, I);
       
//     }
//     return resultCost;
// }

// int main() {
//     int N;
//     std::cin >> N;
//     int** cost = new int* [N];
//     int** found = new int* [N];

//     for (int i = 0; i < N; ++i) {
//         cost[i] = new int[3];
//         // memcmp(cost[i], 0, sizeof(int) * N);
//     }//나중에 메모리 해제하는 거 알아야됨

//     for (int i = 0; i < N; ++i) {
//         found[i] = new int[3];
//         memset(found[i], 0, sizeof(int) * 3);

//     }
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < 3; j++) {
//             std::cin >> cost[i][j];
//         }
//     }

//     std::cout << getSmallCost(cost, found, N, N) << std::endl;
//     return 0;
// }

#include<iostream>
#include<string.h>
#define min(a,b) ((a)>(b)?(b):(a))


int getSmallCost(int** cost, int** found, int N) {

    found[0][0] = cost[0][0];
    found[0][1] = cost[0][1];
    found[0][2] = cost[0][2];


    for (int i = 1; i < N; i++)
    {
        found[i][0] = min(found[i - 1][1], found[i - 1][2]) + cost[i][0];
        found[i][1] = min(found[i - 1][0], found[i - 1][2]) + cost[i][1];
        found[i][2] = min(found[i - 1][0], found[i - 1][1]) + cost[i][2];
    }
    return  min(min(found[N-1][0], found[N-1][1]),found[N-1][2]);
   
}

int main() {
    int N;
    std::cin >> N;
    int** cost = new int* [N];
    int** found = new int* [N];

    for (int i = 0; i < N; ++i) {
        cost[i] = new int[3];
        // memcmp(cost[i], 0, sizeof(int) * N);
    }//나중에 메모리 해제하는 거 알아야됨

    for (int i = 0; i < N; ++i) {
        found[i] = new int[3];
        memset(found[i], 0, sizeof(int) * 3);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> cost[i][j];
        }
    }

    std::cout << getSmallCost(cost, found, N) << std::endl;
    return 0;
}