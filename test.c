#include <stdio.h>

int main(void)
{
    int a = 114514;
    int *p = &a;
    int ** pp = &p;

    printf("a = %d, p = %p, pp = %p\n", a, p , pp);
    printf("*p = %d, *pp = %p\n", *p, *pp);
    printf("&a = %p, p = %p, &p = %p, pp = %p\n", &a, p, &p, pp);

    return 0;
}