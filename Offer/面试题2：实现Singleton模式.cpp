/*
*
* ������2��ʵ��Singletonģʽ
*
*/


//GoF ����ģʽ��һ��ʵ��
class Singleton 
{
private:
	Singleton() {}
	~Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton *instance;
public:
	static Singleton& get_instance() {
		if (instance == nullptr){
			instance = new Singleton();
		}
		return *instance;
	}
};

Singleton* Singleton::instance = nullptr;

//<<Effective C++>>�е�һ��ʵ�֣��̰߳�ȫ
class Singleton2
{
public:
	static Singleton2& Instance(){
		static Singleton2 instance;
		return instance;
	}
private:
	Singleton2(){}
	~Singleton2(){}
	Singleton2(const Singleton&) = delete;
	Singleton2& operator=(const Singleton&) = delete;
};