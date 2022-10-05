#include <iostream>

class Singleton{
private:
    // construction must be private
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    // 


    static Singleton* m_instance_ptr;
    // Notice how to auto destruction! -- public/private are both ok.
    class GC{
        public:
            ~GC(){
                if (Singleton::m_instance_ptr != nullptr){
                    delete Singleton::m_instance_ptr;
                    Singleton::m_instance_ptr = nullptr;
                    std::cout<<"destructor called by class GC!"<<std::endl;
                }
            }
    };
    static GC gc;
    //
public:
    // ~Singleton(){
    //     std::cout<<"destructor called!"<<std::endl;
    // }

    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton* get_instance(){
        return m_instance_ptr;
    }
};

// 类外初始化
Singleton* Singleton::m_instance_ptr = new Singleton();
Singleton::GC Singleton::gc; // use gc to desconstruct!

int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();
    return 0;
}
