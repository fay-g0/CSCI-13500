#include<iostream>

int RecursionFibonacci(int n){
    if (n <= 1){
        return n;
    }
    n = RecursionFibonacci(n-1) + RecursionFibonacci(n-2);
    return n;
}

int main(){
    std::cout<< RecursionFibonacci(15) << std::endl;

}