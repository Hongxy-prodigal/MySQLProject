#include"DB.h"

int Add() {								//��
	
	return 0;
}
int Delete() {							//ɾ
	return 0;
}
int Update() {							//��
	return 0;
}
int Check() {							//��
	return 0;
}
int Show() {							//��ʾ����
	return 0;
}
int MainPage() {
	while (1) {
		int n;
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "1.������ϵ��			";
		cout << "2.ɾ����ϵ��" << endl;
		cout << "3.�޸���ϵ��			";
		cout << "4.��ѯ��ϵ��" << endl;
		cout << "5.��ʾ������ϵ��		";
		cout << "6.�˳�" << endl;
		cout << "���������:";
		cin >> n;
		switch (n)
		{
		case 1:Add(); system("pause"); system("cls"); break;
		case 2:Delete(); system("pause"); system("cls"); break;
		case 3:Update(); system("pause"); system("cls"); break;
		case 4:Check(); system("pause"); system("cls"); break;
		case 5:Show(); system("pause"); system("cls"); break;
		case 6:return 0; system("pause"); break;
		default:cout << "�������"; system("cls"); break;
		}
	}
}
int Login() {
	char useName[12], passWord[24], phoneNum[11];
	bool ret;
	int times=0;
	do {
		cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
		cout << "������绰:";
		cin >> phoneNum;
		cout << "����������:";
		cin >> passWord;
		//������֤	
		user user1(NULL, passWord, phoneNum);
		ret = fetch_user_info(user1);
		times++;

		if (times >= 15) {
			break;
		}
		if (ret == false) {
			cout << "��½ʧ�ܣ�����������!" << endl;
		}
		if (1) {}					//����ɹ��ͽ���������
		else {}						//���ʧ�ܾ����µ�¼
	} while (!ret);
	
	return 0;
}
int Register() {
	char  useName[12], passWord[24], phoneNum[11];
	cout << "��ӭ����ͨѶ¼" << endl << "--------------------------------------" << endl;
	cout << "������绰:";
	cin >> phoneNum;
	cout << "����������:";
	cin >> passWord;
	//����ע��
	if (1){}					//����ɹ��͵�½
	else{}						//���ʧ�ܾ�����ע��
	return 0;
}
