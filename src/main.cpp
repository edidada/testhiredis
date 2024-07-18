#include "hiredis/hiredis.h"
#include <iostream>

int main() {
    // 建立 Redis 连接
    redisContext* redis = redisConnect("127.0.0.1", 6379);
    if (redis == nullptr || redis->err) {
        std::cout << "无法连接到 Redis 服务器" << std::endl;
        return 1;
    }

    // 设置会话键和过期时间
    std::string sessionKey = "session123";
    int expireTime = 60; // 会话过期时间为60秒

    // 读取会话数据
    redisReply* reply = (redisReply*)redisCommand(redis, "GET %s", sessionKey.c_str());
    if (reply == nullptr) {
        std::cout << "无法读取会话数据" << std::endl;
        return 1;
    }

    if (reply->type == REDIS_REPLY_STRING) {
        std::string sessionData = reply->str;
        std::cout << "会话数据：" << sessionData << std::endl;
    } else if (reply->type == REDIS_REPLY_NIL) {
        std::cout << "会话不存在" << std::endl;
    } else {
        std::cout << "无效的回复类型" << std::endl;
    }

    freeReplyObject(reply);

    // 设置会话过期时间
    reply = (redisReply*)redisCommand(redis, "EXPIRE %s %d", sessionKey.c_str(), expireTime);
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        std::cout << "设置会话过期时间失败" << std::endl;
        return 1;
    }

    int result = reply->integer;
    if (result == 1) {
        std::cout << "会话过期时间设置成功" << std::endl;
    } else if (result == 0) {
        std::cout << "会话不存在" << std::endl;
    } else {
        std::cout << "设置会话过期时间失败" << std::endl;
    }

    freeReplyObject(reply);

    // 关闭 Redis 连接
    redisFree(redis);

    return 0;
}