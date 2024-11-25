#include <iostream>

//intr un pointer se stocheaza o adresa &
//deferentiem cu * pentru a accesa valoarea variabilei spre care pointeaza

static void sum(int* a, int* b, int* res){
    int s=0;
    s=*a+*b;

    *res = *a + *b;
    std::cout<<*res<<std::endl;
}

static void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    std::cout<<*a<<" "<<*b<<std::endl;
}

static void working_with_ptr(int *p){
    std::cout<<p<<std::endl;

    if(p)
        std::cout<<*p<<std::endl;
    else std::cout<< "nullptr"<< std::endl;
}

static void working_with_num(int a){
    std::cout<<&a<<std::endl;
}

static void fact(int* a, int* res){
    for(int i=*a; i>1; i--){
        *res *=i;
    }

    std::cout<<*res<<std::endl;
}

static void ref_swap(int &a, int &b){
    int temp;

    temp = a;
    a = b;
    b = temp;

    std::cout<<a<<" "<<b<<std::endl;
}

int main() {
    int *a,b = 35;
    a = &b;

    int *megas = a;
    int *ben = nullptr;

    megas = &b;

    working_with_ptr(a);

    working_with_num(b);

    int levin = 11;
    int & kevin = levin;

    std::cout<<kevin<<std::endl;

    int jumper1 = 30, jumper2 = 4, main_res, f = 5, g = 6;

    int& alias_f = f, &mixers = g;

    int* gwen = &alias_f, *vilgax;

    sum(&jumper1, &jumper2, &main_res);

    swap(&jumper1, &jumper2);

    int x = 5, y=1, *px = &x, *py = &y;

    fact(px, py);

    int* pf = &mixers;
    std::cout<<*pf<<std::endl;

    int fa, xlr, &hum = fa, &fast = xlr;

    hum = 10;
    fast = 12;

    ref_swap(hum, fast);

    return 0;
}

