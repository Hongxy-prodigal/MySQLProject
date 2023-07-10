#include"DB.h"
//仅仅只是界面设计，具体函数在类里面
int Add() {								//增
	cout << "姓    名：";
	cout << "电话号码：";
	cout << "邮    箱：";
	cout << "关    系：";
	//判断是否存在
	return 0;
}
int Delete() {							//删
	cout << "姓    名：";
	cout << "电话号码：";
	//判断是否存在
	return 0;
}
int Update() {							//改
	cout << "姓    名：";
	cout << "电话号码：";
	cout << "邮    箱：";
	cout << "关    系：";
	return 0;
}
int Check() {							//查
	cout << "姓    名：";
	cout << "电话号码：";
	cout << "邮    箱：";
	cout << "关    系：";
	return 0;
}
int Show() {							//显示所有
	//直接显示
	return 0;
}
int MainPage(user &user) {
	int n;
	while (1) {
		system("cls");
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "1.增加联系人			";
		cout << "2.删除联系人" << endl;
		cout << "3.修改联系人			";
		cout << "4.查询联系人" << endl;
		cout << "5.显示所有联系人		";
		cout << "6.退出" << endl;
		cout << "请输入操作:";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1: Add();  break;
		case 2:Delete();  break;
		case 3:Update();  break;
		case 4:Check();  break;
		case 5:Show();  break;
		case 6:return 0; break;
		default:cout << "输入错误"; system("pause"); break;
		}
	}
}
int Login() {
	char  passWord[24], phoneNum[12];
	bool ret;
	int times=0;
	do {
		system("cls");
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "请输入电话:";
		cin >> phoneNum;
		cout << "请输入密码:";
		cin >> passWord;
		//进行验证	
		user user(passWord, phoneNum);
		ret = fetch_user_info(user);
		times++;

		if (times >= 15) {			//暂时不处理
			break;
		}
		if (ret == false) {
			cout << "登陆失败!" << endl;
			cout << "输入0退出,输入其他继续" << endl;
			int n;
			cin >> n;
			if (n==0)
				return 0;				
		}
		else {
			MainPage(user);
		}
	} while (!ret);
	return 0;
}
int Register() {
	char useName[12], passWord[24], phoneNum[12];
	bool ret;
	int times = 0;
	do {
		system("cls");
		cout << "欢迎来到通讯录" << endl << "--------------------------------------" << endl;
		cout << "请输入用户名:";
		cin >> useName;
		cout << "请输入电话:";
		cin >> phoneNum;
		cout << "请输入密码:";
		cin >> passWord;
		//进行验证	
		user user(useName, passWord, phoneNum);
		ret = insert_user_info(user);
		times++;

		if (times >= 15) {
			break;
		}
		if (ret == false) {
			cout << "注册失败!" << endl;
			cout << "输入0退出,输入其他继续" << endl;
			int n;
			cin >> n;
			system("cls");
			if (n == 0)
				return 0;
		}
		else {
			Login();
		}
	} while (!ret);
	return 0;
}
