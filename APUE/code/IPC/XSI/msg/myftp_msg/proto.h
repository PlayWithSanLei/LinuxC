#ifndef PROTO_H___
#define PROTO_H___

#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

//协议文件
#define KEYPATH "/etc/services"
#define KEYPROJ 'g'
#define PATHMAX 1024
#define DATAMAX 1024

enum{
    MSG_PATH = 1,
    MSG_DATA,
    MSG_EOT
};

typedef struct msg_path_st{
    long datatype;//必须是路径包
    char path[PATHMAX];
}msg_path_t;

typedef struct msg_data_st{
    long datatype;//必须是数据包
    char data[DATAMAX];
    int datalen;
}msg_data_t;

typedef struct msg_eot_st{
    long datatype;
}msg_eot_t;

//
union msg_s2c_un{
    long datatype;
    msg_data_t datamsg;
    msg_eot_t eotmsg;
};



#endif