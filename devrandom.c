/**
 * @file devrandom.c
 * @author wangguibao(wang_guibao@163.com)
 * @date 2017/09/14 16:56:46
 * @brief Random number from /dev/random
 *
 **/
#include <stdio.h>
int main()
{
    FILE *fp = fopen("/dev/urandom", "r");
    int x = 0;
    int ret = 0;

    if (fp == NULL) {
        return -1;
    }

    ret = fread(&x, sizeof(x), 1, fp);

    if (ret != 1) {
        fprintf(stderr, "fread fail\n");
        return -1;
    }

    fprintf(stdout, "0x%x\n", x);
    return 0;
}
