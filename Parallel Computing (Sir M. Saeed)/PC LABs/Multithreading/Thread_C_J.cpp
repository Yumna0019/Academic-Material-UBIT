#include <iostream>
#include <pthread.h>

void* mythread(void* args) {
    std::cout << (char*) args << std::endl;
    return nullptr;
}

int main() {
    pthread_t p1, p2;
    std::cout << "main begin" << std::endl;

    pthread_create(&p1, nullptr, mythread, (void*)"A");
    pthread_create(&p2, nullptr, mythread, (void*)"B");

    pthread_join(p1, nullptr);
    pthread_join(p2, nullptr);

    std::cout << "main end" << std::endl;
    return 0;
}