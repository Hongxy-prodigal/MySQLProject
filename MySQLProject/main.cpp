#include"Contact.h"
int main() {
	//进入界面
	int n;
	while (1) {
		system("cls");
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "1.登录					2.注册" << endl;
		cout << "请输入:";
		cin >> n;
		switch (n)
		{
		case 1:system("cls"); Login();  break;
		case 2:system("cls"); Register();  break;
		default:cout << "输入错误！" << endl; system("pause");  break;
		}
	}
	return 0;
}