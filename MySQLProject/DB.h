#pragma once
#include"user.h"

bool fetch_user_info(user& user) {
    MYSQL mysql;
    MYSQL_RES* res; //查询结果集
    MYSQL_ROW row;  //记录结构体
    char sql[256];
    bool ret = false;


    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "select useName from user where phoneNum='%s' and passWord=md5('%s');", user.phoneNum, user.passWord);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库查询出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.获取结果
    res = mysql_store_result(&mysql);
    row = mysql_fetch_row(res);

    if (row == NULL) {//没有查找到记录
        mysql_free_result(res);
        mysql_close(&mysql);
        return false;
    }

    strcpy_s(user.useName,row[0]);
    cout << "userName: " << user.useName << endl;  //打印ID

    //4.返回结果

    //释放结果集
    mysql_free_result(res);

    //关闭数据库
    mysql_close(&mysql);

    return true;
}
bool insert_user_info(user &user){
    MYSQL mysql;
    char sql[256];
    bool ret = false;


    //1.连接到数据库
    if (connect_db(mysql) == false) {
        return false;
    }

    //2.根据用户名和密码获取用户信息(id, level_id)
    snprintf(sql, 256, "INSERT INTO user VALUES ('%s', MD5('%s'), '%s')",user.useName, user.passWord, user.phoneNum);
    ret = mysql_query(&mysql, sql); //成功返回0

    if (ret) {
        printf("数据库插入出错，%s 错误原因： %s\n", sql, mysql_error(&mysql));
        mysql_close(&mysql);
        return false;
    }

    //3.返回结果

    //关闭数据库
    mysql_close(&mysql);

    return true;
}




