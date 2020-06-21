//
// Created by Hugo on 2020/6/21.
//


#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int f = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        f = 1;
        break;
    }
    if (f) printf("F\n");
    else printf("T");
    return 0;
}