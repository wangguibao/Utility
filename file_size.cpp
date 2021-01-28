/**
 * @file file_size.c
 * @author wangguibao(wang_guibao@163.com)
 * @date 2021/01/28 11:38:38
 * @brief 
 *  
 **/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>

void help() {
    std::cout << "Usage: file_size FILE" << std::endl;
    std::cout << "This utility tries to determine the file size; if the given "
        << "file is a symbolic link, it gives the size of the real file, not the "
        << "symbolic link itself"
        << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        help();
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        std::cout << "Fail to open file: " << strerror(errno) << std::endl;
        return -1;
    }

    struct stat stat_buffer;
    if (fstat(fd, &stat_buffer) != 0) {
        std::cout << "Fail to stat file: " << strerror(errno) << std::endl;
        return -1;
    }

    std::cout << "File size as reported by fstat(): "
        << stat_buffer.st_size
        << std::endl;
    std::cout << "File size as reported by lseek(): "
        << lseek(fd, 0, SEEK_END)
        << std::endl;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
