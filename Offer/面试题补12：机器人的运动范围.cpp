/*
*
* �����ⲹ13�������˵��˶���Χ
* ������һ��m�к�n�еķ���
* һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
* ���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
* ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
* ���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*
*/

//��������λ��֮��
int digitNum(int num)
{
	int count = 0;
	while (num > 0){
		count += num % 10;
		num /= 10;
	}
	return count;
}

int movingCountCore(int threshold, int rows, int cols, 
	int row, int col, bool *visited)
{
	int count = 0;
	//�жϴ�λ���Ƿ����
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& !visited[row * cols + col] &&
		(digitNum(row) + digitNum(col) <= threshold)) {
		visited[row * cols + col] = true; //�ѷ���
		//�����ĸ�������
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}

	return count;
}


int movingCount(int threshold, int rows, int cols)
{
	//����ֵ�ж�
	if (threshold < 0 || rows <= 0 || cols <= 0) {
		return 0;
	}

	//���÷�������
	bool *visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++) {
		visited[i] = false;
	}
	//�������
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}

