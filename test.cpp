#include <stdio.h>

#if 1
#include "promise.hpp"

#define PTI do{printf("%d, %s\n", __LINE__, __func__);} while(0)
using namespace promise;

int main(int argc, char **argv) {
    //Defer d1;
    
    newPromise([argc](Defer d){
        PTI;
        //d1 = d;
        //return 
		d->resolve();
        //return 33;
        //d->reject();
	})->then([]() {
		printf("xxxx\n");
		return 555;
	})->then([](int n) {
		printf("n = %d\n", n);
    });
#if 0    
        printf("n = %d\n", n);
        PTI;
        Defer d2 = newPromise([](Defer d){
            PTI;
            d->resolve();
        });
        d2->resolve();
        //return d2;
    }, [&d1](){
        PTI;
        throw 3;
    })->then([](){
        PTI;
    })->then([](){
        PTI;
    })->fail([](){
        PTI;
    })->always([](){
        PTI;
    });
#endif    
    
    printf("later=================\n");
    //(d1)->resolve();
    
    return 0;
}
#endif

#if 0
e <functional>
#include <memory>

int test(int x){
    printf("2222\n");
}

short test2(){
    return 2;
}

template<class FUNC>
struct GetRetType {
    typedef decltype(&FUNC::operator()) func_type;
    typedef typename GetRetType<func_type>::ret_type ret_type;
};

template<class RET, class T, class ARG>
struct GetRetType< RET (T::*)(ARG) const > {
    typedef RET ret_type;
};

template<class RET, class ARG>
struct GetRetType< RET (*)(ARG) > {
    typedef RET ret_type;
};

template<class RET, class T>
struct GetRetType< RET (T::*)() const > {
    typedef RET ret_type;
};

template<class RET>
struct GetRetType< RET (*)() > {
    typedef RET ret_type;
};


template<class FUNC>
void dofunc(FUNC func){
    typedef typename GetRetType<FUNC>::ret_type ret_type;
    printf("size = %d\n", sizeof(ret_type));
}
    
int main() {
    dofunc([](const int *x){
        return '3';
    });
    
    dofunc(test);
    dofunc(&test2);
    
    return 0;
}
#endif