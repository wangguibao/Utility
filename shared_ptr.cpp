/**
 * @file test_c.c
 * @author wangguibao(com@baidu.com)
 * @date 2019/11/21 19:50:13
 * @brief 
 *  
 **/
#include <iostream>
#include <memory>


std::shared_ptr<int> get_ptr() {
    std::shared_ptr<int> x = std::make_shared<int>();
    std::cout << "1: ref 1 = " << x.use_count() << std::endl;
    *x = 1;

    std::cout << "1: ref 2 = " << x.use_count() << std::endl;

    return x;
}

class SharedPtrWrapper {
public:
    void set_ptr(std::shared_ptr<int> ptr) {
        _ptr = ptr;
        std::cout << "4: ref 2(1) = " << ptr.use_count()
            << ", ref 2(2) = " << _ptr.use_count()
            << std::endl;
    }

    std::shared_ptr<int> ptr() {return _ptr;}

    int use_count() {return _ptr.use_count();}

    ~SharedPtrWrapper() {
        std::cout << "4: ref 8 = " << _ptr.use_count() << std::endl;
    }

private:
    std::shared_ptr<int> _ptr;
};

struct Storage {
    std::shared_ptr<int> ptr {nullptr};
};

int main(int argc, char **argv) {
    std::cout << "shared_ptr: function returning a shared_ptr:" << std::endl;
    auto a = get_ptr();
    std::cout << "1: ref 3 = " << a.use_count() << std::endl;

    std::cout << "shared_ptr: Returning a copy of shared_ptr to a reference:" << std::endl;
    const std::shared_ptr<int>& b = get_ptr();
    std::cout << "2: ref 3 = " << b.use_count() << std::endl; 

    std::shared_ptr<int> c = std::make_shared<int>();

    std::cout << "Storing a shared_ptr to an new() allocated storage" << std::endl;
    {
        Storage* storage = new Storage();
        storage->ptr = c;

        std::cout << "3: ref 1 = " << c.use_count()
           << ", ref 2 = " << storage->ptr.use_count() << std::endl;

        delete storage;
        std::cout << "3: ref = " << c.use_count() << std::endl;
    }

    std::cout << "shared_ptr: passing a copy of shared_ptr to class:" << std::endl;
    std::cout << "4: ref 1 = " << c.use_count() << std::endl;

    SharedPtrWrapper wrapper;
    wrapper.set_ptr(c);
    std::cout << "4: ref 3 = " << c.use_count() << std::endl;

    {
        std::shared_ptr<int> d = wrapper.ptr();
        std::cout << "4: ref 4(1) = " << wrapper.use_count()
            << ", ref 4(2) = " << d.use_count()
            << std::endl;
        std::cout << "4: ref 5(1) = " << wrapper.use_count() << std::endl;
        std::cout << "4: ref 5(2) = " << d.use_count() << std::endl;
    }

    {
        const std::shared_ptr<int>& e = wrapper.ptr();
        std::cout << "4: ref 6(1) = " << wrapper.use_count() << std::endl;
        std::cout << "4: ref 6(2) = " << e.use_count() << std::endl;
    }

    std::cout << "Dereference shared_ptr by calling reset()" << std::endl;
    c.reset();
    std::cout << "4: ref 7 = " << wrapper.use_count() << std::endl;

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
