#include <stdio.h>

int main() {
    int count = 100;
    int sum = 0;
    int n = (count + 7) / 8;
    printf(" n= %d\n",n);
    printf("余数=%d\n",count%8);



   //每次循环展开8次
    switch (count % 8) {
        case 0: do { sum++;
        case 7:      sum++;
        case 6:      sum++;
        case 5:      sum++;
        case 4:      sum++;
        case 3:      sum++;
        case 2:      sum++;
        case 1:      sum++;
                } while (--n > 0);
    }

    printf("sum: %d\n", sum);
    return 0;
}