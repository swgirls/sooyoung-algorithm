// #include <iostream>

// int each[40][2];


// int fibonacci(int n) {
//     if (n == 0) {
//         each[n][0]++;
//         return 0;
//     } else if (n == 1) {
//         each[n][1]++;
//         return 1;
//     } else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }
  

// void initialize(int *array){
//     array[0]= 0;
//     array[1]= 0;
// }

// int main(){
//     int T, input;
//     std::cin>>T;

//     for(int i =0; i<T; i++){
//         std::cin>>input;
//         initialize(each[input]);
//         fibonacci(input);

//         std::cout<<each[input][0]<<" "<<each[input][1];
//     }

//     return 0;
// }

// #include <iostream>

// __int64 zero = 0;
// __int64 one = 0;

// __int64 fibonacci(int n){
//     if(n==0){
//         zero++;
//         return 0;
//     }
//     else if(n==1){
//         one++;
//         return 1;
//     }
//     else{
//         return fibonacci(n-1)+fibonacci(n-2);
//     }
// }
// int main(){
//     int T, input;
//     std::cin>>T;
//     for(int i =0; i<T; i++){
//         std::cin>>input;
//         zero = 0;
//         one = 0;
//         fibonacci(input);
//         std::cout<<zero<<" "<<one;
//     }

//     return 0;
// }

#include <iostream>

int each[41][2];
int found[41] = { 0, };

int fibonacci(int n, int I) {

    int result = 0;

    if (found[n] != 0) {
        return found[n];
    }
    else {
        if (n == 0) {
            each[n][0] = 1;
            found[n] = 0;
            return 0;
        }
        else if (n == 1) {
            each[n][1] = 1;
            found[n] = 1;
            return 1;
        }
        else {
            result = fibonacci(n - 1, I) + fibonacci(n - 2, I);
            each[n][0] = each[n][0]+ each[n - 1][0] + each[n-2][0];
            each[n][1] = each[n][1]+ each[n - 1][1] + each[n-2][1];

            found[n] = result;
            return result;
        }

    }

}

void initialize(int* array) {
    array[0] = 0;
    array[1] = 0;
  
}

void initialize_found(int number) {
    found[number] = 0;
}

int main_1003() {
    int T, input;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> input;

        for (int j = 0; j <= input; j++) {
            initialize(each[j]);
            initialize_found(j);
        }

        fibonacci(input, input);

        std::cout << each[input][0] << " " << each[input][1]<<std::endl;
    }

    return 0;
}