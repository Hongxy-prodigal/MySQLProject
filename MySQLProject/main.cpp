#include"Contact.h"
int main() {
	//�������
	int n;
	while (1) {
		system("cls");
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "1.��¼					2.ע��" << endl;
		cout << "������:";
		cin >> n;
		switch (n)
		{
		case 1:system("cls"); Login();  break;
		case 2:system("cls"); Register();  break;
		default:cout << "�������" << endl; system("pause");  break;
		}
	}
	return 0;
}