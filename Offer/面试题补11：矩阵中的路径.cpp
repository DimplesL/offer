/*
*
* �����ⲹ11�������е�·��
* �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
* ·�����ԴӾ����е�����һ�����ӿ�ʼ��
* ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
* ���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
* ���� a b c e s f c s a d e e �����а���һ���ַ�����bcced����·����
* ���Ǿ����в�������abcb��·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��
* ·�������ٴν���ø��ӡ�
*
*/

#include <cstring>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
	char* str, int& length, bool *visited)
{
	if (str[length] == '\0') {
		return true;
	}
	bool ishasPath = false;
	//�жϴ�λ���Ƿ�����
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[length] &&
		!visited[row * cols + col]) {
		//���㳢���ַ����е���һ��λ��
		length++;
		visited[row * cols + col] = true;

		ishasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, length, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, length, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, length, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, length, visited);
		//�ַ�����һ��λ�ö���ƥ��
		//���λ�ò�����ȷ·���ϵĽ⣬���Ի��ˣ�������һ��λ��
		if (!ishasPath) {
			length--;
			visited[row * cols + col] = false;
		}
	}
	return ishasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	//�߽��Լ�����ֵ���
	if (!matrix || rows <= 0 || cols <= 0 || !str) {
		return false;
	}

	//�Ƿ���ʹ�������
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int length = 0;
	//�ӵ�һ��λ�ÿ�ʼ����
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rows, cols, row, col, str, length, visited)) {
				return true;
			}
		}
	}
	return false;
}