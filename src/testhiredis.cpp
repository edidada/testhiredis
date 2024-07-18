#include "hiredis/hiredis.h"
#include <iostream>

int main() {
    redisContext* redis = redisConnect("127.0.0.1", 6379);
    if (redis == nullptr || redis->err) {
        std::cout << "redisConnect error" << std::endl;
        return 1;
    }

    // 设置会话键和过期时间
    std::string sessionKey = "session123";
    int expireTime = 60; // 会话过期时间为60秒

    // 读取会话数据
    redisReply* reply = (redisReply*)redisCommand(redis, "GET %s", sessionKey.c_str());
    if (reply == nullptr) {
        std::cout << "no data" << std::endl;
        return 1;
    }

    return 0;
}