/**
 * @file test_c.c
 * @author wangguibao(wang_guibao@163.com)
 * @date 2020/11/10 16:50:13
 * @brief Print current date time in the form of YYYYMMDDhhmmss (example: 20201110165013)
 *  
 **/

#include <stdio.h>
#include <time.h>

int main()
{
    time_t time_buff = time(NULL);

    struct tm *tm_buff = localtime(&time_buff);

    printf("%04d%02d%02d%02d%02d%02d\n", 
            tm_buff->tm_year + 1900, 
            tm_buff->tm_mon + 1, 
            tm_buff->tm_mday, 
            tm_buff->tm_hour, 
            tm_buff->tm_min, 
            tm_buff->tm_sec);
    return 0;
}
