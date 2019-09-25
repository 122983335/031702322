#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <algorithm>
#include<typeinfo>
#include<string.h>
using namespace std;
int map[9][9];
bool isPlace3(int count) {
	int row = count / 3;
	int col = count % 3;
	//ͬһ��
	for (int j = 0; j < 3; j++) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 3; j++) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	return true;
}
bool isPlace5(int count) {
	int row = count / 5;
	int col = count % 5;
	//ͬһ��
	for (int j = 0; j < 5; ++j) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 5; ++j) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	return true;
}
bool isPlace7(int count) {
	int row = count / 7;
	int col = count % 7;
	//ͬһ��
	for (int j = 0; j < 7; ++j) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 7; ++j) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	return true;
}
bool isPlace4(int count) {
	int row = count / 4;
	int col = count % 4;
	//ͬһ��
	for (int j = 0; j < 4; ++j) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 4; ++j) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	//ͬһС��
	int tempRow = row / 2;
	int tempCol = col / 2;
	for (int j = tempRow; j < tempRow + 2; ++j) {
		for (int k = tempCol; k < tempCol + 2; ++k) {
			if (map[j][k] == map[row][col] && j != row && k != col) {
				return false;
			}
		}
	}
	return true;
}
bool isPlace6(int count) {
	int row = count / 6;
	int col = count % 6;
	//ͬһ��
	for (int j = 0; j < 6; ++j) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 6; ++j) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	//ͬһС��
	int tempRow = row / 2;
	int tempCol = col / 3;
	for (int j = tempRow; j < tempRow + 2; ++j) {
		for (int k = tempCol; k < tempCol + 3; ++k) {
			if (map[j][k] == map[row][col] && j != row && k != col) {
				return false;
			}
		}
	}
	return true;
}
bool isPlace8(int count) {
	int row = count / 8;
	int col = count % 8;
	//ͬһ��
	for (int j = 0; j < 8; ++j) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 8; ++j) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	//ͬһС��
	int tempRow = row / 4;
	int tempCol = col / 2;
	for (int j = tempRow; j < tempRow + 4; ++j) {
		for (int k = tempCol; k < tempCol + 2; ++k) {
			if (map[j][k] == map[row][col] && j != row && k != col) {
				return false;
			}
		}
	}
	return true;
}
bool isPlace9(int count) {
	int row = count / 9;
	int col = count % 9;
	//ͬһ��
	for (int j = 0; j < 9; j++) {
		if (map[row][j] == map[row][col] && j != col) {
			return false;
		}
	}
	//ͬһ��
	for (int j = 0; j < 9; j++) {
		if (map[j][col] == map[row][col] && j != row) {
			return false;
		}
	}
	//ͬһС��
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for (int j = tempRow; j < tempRow + 3; ++j) {
		for (int k = tempCol; k < tempCol + 3; ++k) {
			if (map[j][k] == map[row][col] && j != row && k != col) {
				return false;
			}
		}
	}
	return true;
}
void backtrace3(int count) {
	if (count == 9) {
		cout << "�����" << endl;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 3;
	int col = count % 3;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 3; ++i)
		{
			map[row][col] = i;//��ֵ
			if (isPlace3(count)) {//���Է�
				backtrace3(count + 1);//������һ��
			}
			else map[row][col] = 0;//����		
		}
	}
	else backtrace3(count + 1);
}
void backtrace4(int count) {
	if (count == 16) {
		cout << "�����" << endl;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 4;
	int col = count % 4;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 4; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace4(count)) {//���Է�
				backtrace4(count + 1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else {
		backtrace4(count + 1);
	}
}
void backtrace5(int count) {
	if (count == 25) {
		cout << "�����" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 5;
	int col = count % 5;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 5; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace5(count)) {//���Է�
				backtrace5(count + 1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else {
		backtrace5(count + 1);
	}
}
void backtrace6(int count) {
	if (count == 36) {
		cout << "�����" << endl;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 6;
	int col = count % 6;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 6; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace6(count)) {//���Է�
				backtrace6(count + 1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else {
		backtrace6(count + 1);
	}
}
void backtrace7(int count) {
	if (count == 49) {
		cout << "�����" << endl;
		for (int i = 0; i < 7; ++i) {
			for (int j = 0; j < 7; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 7;
	int col = count % 7;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 7; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace7(count)) {//���Է�
				backtrace7(count + 1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else {
		backtrace7(count + 1);
	}
}
void backtrace8(int count) {
	if (count == 64) {
		cout << "�����" << endl;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 8;
	int col = count % 8;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 8; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace8(count)) {//���Է�
				backtrace8(count + 1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else backtrace8(count + 1);
}
void backtrace9(int count) {
	if (count == 81) {
		cout << "�����" << endl;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int row = count / 9;
	int col = count % 9;
	if (map[row][col] == 0) {
		for (int i = 1; i <= 9; ++i) {
			map[row][col] = i;//��ֵ
			if (isPlace9(count)) {//���Է�
				backtrace9(count + 1);//������һ��
			}
			else map[row][col] = 0;//����
		}
	}
	else backtrace9(count + 1);
}
int main(int argc, char* argv[])
{
	int mark = 0;
	int m = 0, n = 0;
	int in, on;
	for (int i = 0; i < argc; i++)
	{
		if (strlen(argv[i]) == 1)
		{
			if (i == 2)
				m = atoi(argv[i]);
			if (i == 4)
				n = atoi(argv[i]);
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'i') {
			i++;
			in = i;
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'o') {
			i++;
			on = i;
		}
	}
	for (int k = 0; k < n; k++)
	{
		ifstream infile;
		infile.open(argv[in]);
		infile.seekg(mark);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				infile >> map[i][j];
			}
		}
		mark = long(infile.tellg());
		infile.close();
		if (m == 3)
			backtrace3(0);
		if (m == 4)
			backtrace4(0);
		if (m == 5)
			backtrace5(0);
		if (m == 6)
			backtrace6(0);
		if (m == 7)
			backtrace7(0);
		if (m == 8)
			backtrace8(0);
		if (m == 9)
			backtrace9(0);
		ofstream outfile;
		outfile.open(argv[on], ios::app);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				outfile << map[i][j];
				if (j == m - 1)
					outfile << endl;
				else
					outfile << " ";
			}
		}
		outfile << endl;
		outfile.close();
	}
	return 0;
}