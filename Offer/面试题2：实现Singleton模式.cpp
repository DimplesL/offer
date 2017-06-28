/*
*
* ������2��ʵ��Singletonģʽ
*
*/


//GoF ����ģʽ��һ��ʵ��
class Singleton
{
private:
	//��������������˽�е�
	Singleton() {}
	~Singleton() {}
	//û�п�������Ϳ��������
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	//��̬��ʵ��ָ��
	static Singleton *instance;
public:
	//��̬���ʵ������ķ���
	static Singleton& get_instance() {
		if (instance == nullptr) { //Ϊ�գ��Ŵ���
			instance = new Singleton();
		}
		return *instance; //���ض��������
	}
};

Singleton* Singleton::instance = nullptr;

//<<Effective C++>>�е�һ��ʵ�֣��̰߳�ȫ
class Singleton2
{
public:
	static Singleton2& Instance(){
		//��һ�������ڲ���staticʵ��
		static Singleton2 instance;
		return instance;
	}
private:
	Singleton2(){}
	~Singleton2(){}
	Singleton2(const Singleton&) = delete;
	Singleton2& operator=(const Singleton&) = delete;
};