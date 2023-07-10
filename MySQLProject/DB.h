#pragma once
#include"user.h"

#define DB_NAME  "contact"
#define DB_HOST  "127.0.0.1"
#define DB_PORT  3306
#define DB_USER  "root"
#define DB_USER_PASSWD  "mysql"

bool connect_db(MYSQL& mysql) {

    //1.��ʼ�����ݿ���
    mysql_init(&mysql);

    //2.�����ַ�����
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

    //3.�������ݿ�
    if (mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_USER_PASSWD, DB_NAME, DB_PORT, NULL, 0) == NULL) {
        cout << "���ݿ����ӳ��� ����ԭ��: " << mysql_error(&mysql) << endl;
        return false;
    }

    return true;
}

bool fetch_user_info(user& user) {
    MYSQL mysql;
    MYSQL_RES* res; //��ѯ�����
    MYSQL_ROW row;  //��¼�ṹ��
    char sql[256];
    bool ret = false;


    //1.���ӵ����ݿ�
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.�����û����������ȡ�û���Ϣ(id, level_id)
    snprintf(sql, 256, "select useName from user where phoneNum='%s' and passWord=md5('%s');", user.phoneNum, user.passWord);
    ret = mysql_query(&mysql, sql); //�ɹ�����0

    if (ret) {
        printf("���ݿ��ѯ����%s ����ԭ�� %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.��ȡ���
    res = mysql_store_result(&mysql);
    row = mysql_fetch_row(res);

    if (row == NULL) {//û�в��ҵ���¼
        mysql_free_result(res);
        mysql_close(&mysql);
        return false;
    }

    strcpy_s(user.useName,row[0]);
    cout << "userName: " << user.useName << endl;  //��ӡID

    //4.���ؽ��

    //�ͷŽ����
    mysql_free_result(res);

    //�ر����ݿ�
    mysql_close(&mysql);

    return true;
}
bool insert_user_info(user &user){
    MYSQL mysql;
    char sql[256];
    bool ret = false;


    //1.���ӵ����ݿ�
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.�����û����������ȡ�û���Ϣ(id, level_id)
    snprintf(sql, 256, "INSERT INTO user VALUES ('%s', MD5('%s'), '%s')",user.useName, user.passWord, user.phoneNum);
    ret = mysql_query(&mysql, sql); //�ɹ�����0

    if (ret) {
        printf("���ݿ�������%s ����ԭ�� %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.���ؽ��

    //�ر����ݿ�
    mysql_close(&mysql);

    return true;
}




