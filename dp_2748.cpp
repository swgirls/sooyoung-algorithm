#include <iostream>

//backjoon ���� �������� __int64 �� �ƴ϶� __int64_t��
//�ٲ㼭 �ؾߵ�

__int64 found[90] = {0,};

__int64 fivonachi(int num){
   
    __int64 result = 0;

    if(found[num]!=0){
        return found[num];
    }
    else{
        if(num==0 ||num==1) {
            found[num] = num;
            return num;
        }
        else{
            result = fivonachi(num-1) + fivonachi(num-2);
            found[num] = result;
            return result;
        } 
    }
}

int main(){
    int num;
    std::cin>>num; 
    std::cout<<fivonachi(num);

    return 0;
}