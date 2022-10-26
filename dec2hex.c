/**
 * @file dec2hex.c
 * @author wangguibao(com@baidu.com)
 * @date 2014/02/08 14:55:00
 * @brief convert a decimal integer to hex
 *
 **/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stdout, "USAGE: dec2hex DECIMAL\n");
        return -1;
    }
    unsigned long long x = strtoull(argv[1], NULL, 10);
    printf("0x%llx\n", x);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
