/*
*
* ������48�����ܱ��̳е���
*
*/

//˽�еĹ�������������
class Sealed
{
public:
	static Sealed *get_instance() {
		new Sealed();
	}
	static void delete_intance(Sealed *instance) {
		delete instance;
	}
//�����͹��캯������˽�е�
private:
	Sealed() {}
	~Sealed(){}
};