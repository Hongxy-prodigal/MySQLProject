#include"DB.h"

int Add() {								//增
	
	return 0;
}
int Delete() {							//删
	return 0;
}
int Update() {							//改
	return 0;
}
int Check() {							//查
	return 0;
}
int Show() {							//显示所有
	return 0;
}
int MainPage() {
	while (1) {
		int n;
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "1.增加联系人			";
		cout << "2.删除联系人" << endl;
		cout << "3.修改联系人			";
		cout << "4.查询联系人" << endl;
		cout << "5.显示所有联系人		";
		cout << "6.退出" << endl;
		cout << "请输入操作:";
		cin >> n;
		switch (n)
		{
		case 1:Add(); system("pause"); system("cls"); break;
		case 2:Delete(); system("pause"); system("cls"); break;
		case 3:Update(); system("pause"); system("cls"); break;
		case 4:Check(); system("pause"); system("cls"); break;
		case 5:Show(); system("pause"); system("cls"); break;
		case 6:return 0; system("pause"); break;
		default:cout << "输入错误"; system("cls"); break;
		}
	}
}
int Login() {
	char useName[12], passWord[24], phoneNum[11];
	bool ret;
	int times=0;
	do {
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "请输入电话:";
		cin >> phoneNum;
		cout << "请输入密码:";
		cin >> passWord;
		//进行验证	
		user user1(NULL, passWord, phoneNum);
		ret = fetch_user_info(user1);
		times++;

		if (times >= 15) {
			break;
		}
		if (ret == false) {
			cout << "登陆失败，请重新输入!" << endl;
		}
		if (1) {}					//如果成功就进入主界面
		else {}						//如果失败就重新登录
	} while (!ret);
	
	return 0;
}
int Register() {
	char  useName[12], passWord[24], phoneNum[11];
	cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
	cout << "请输入电话:";
	cin >> phoneNum;
	cout << "请输入密码:";
	cin >> passWord;
	//进行注册
	if (1){}					//如果成功就登陆
	else{}						//如果失败就重新注册
	return 0;
}
