#include"DB.h"
//����ֻ�ǽ�����ƣ����庯����������
int Add() {								//��
	cout << "��    ����";
	cout << "�绰���룺";
	cout << "��    �䣺";
	cout << "��    ϵ��";
	//�ж��Ƿ����
	return 0;
}
int Delete() {							//ɾ
	cout << "��    ����";
	cout << "�绰���룺";
	//�ж��Ƿ����
	return 0;
}
int Update() {							//��
	cout << "��    ����";
	cout << "�绰���룺";
	cout << "��    �䣺";
	cout << "��    ϵ��";
	return 0;
}
int Check() {							//��
	cout << "��    ����";
	cout << "�绰���룺";
	cout << "��    �䣺";
	cout << "��    ϵ��";
	return 0;
}
int Show() {							//��ʾ����
	//ֱ����ʾ
	return 0;
}
int MainPage(user &user) {
	int n;
	while (1) {
		system("cls");
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "1.������ϵ��			";
		cout << "2.ɾ����ϵ��" << endl;
		cout << "3.�޸���ϵ��			";
		cout << "4.��ѯ��ϵ��" << endl;
		cout << "5.��ʾ������ϵ��		";
		cout << "6.�˳�" << endl;
		cout << "���������:";
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
		default:cout << "�������"; system("pause"); break;
		}
	}
}
int Login() {
	char  passWord[24], phoneNum[12];
	bool ret;
	int times=0;
	do {
		system("cls");
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "������绰:";
		cin >> phoneNum;
		cout << "����������:";
		cin >> passWord;
		//������֤	
		user user(passWord, phoneNum);
		ret = fetch_user_info(user);
		times++;

		if (times >= 15) {			//��ʱ������
			break;
		}
		if (ret == false) {
			cout << "��½ʧ��!" << endl;
			cout << "����0�˳�,������������" << endl;
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
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "�������û���:";
		cin >> useName;
		cout << "������绰:";
		cin >> phoneNum;
		cout << "����������:";
		cin >> passWord;
		//������֤	
		user user(useName, passWord, phoneNum);
		ret = insert_user_info(user);
		times++;

		if (times >= 15) {
			break;
		}
		if (ret == false) {
			cout << "ע��ʧ��!" << endl;
			cout << "����0�˳�,������������" << endl;
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
