#include"Contact.h"
int main() {
	//�������
	int n;
	while (1) {
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "1.��¼					2.ע��" << endl;
		cout << "������:";
		cin >> n;
		switch (n)
		{
		case 1:Login(); system("pause"); system("cls"); break;
		case 2:Register(); system("pause"); system("cls"); break;
		default:cout << "�������" << endl; system("pause"); system("cls"); break;
		}
	}
	return 0;
}