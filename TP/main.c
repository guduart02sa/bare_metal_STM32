int test_bss = 0;

int fibo(int n){
    if(n == 1 || n == 2) return 1;
    else return fibo(n-1) + fibo(n-2);
}

int main(){
    fibo(8);
    test_bss = test_bss + 3;
    return 0;
}