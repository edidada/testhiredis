# README

git submodule add -b v1.2.0 https://github.com/redis/hiredis.git third_party/hiredis
git submodule update --init --recursive

## doc

### 头文件


adapters

ae.h
glib.h
ivykis.h
libev.h
libevent.h
libhv.h
libsdevent.h
libuv.h
macosx.h
poll.h
qt.h
redismoduleapi.h

alloc.h
async.h
hiredis.h
read.h
sds.h
sockcompat.h


### 函数
redisConnect
redisConnectWithTimeout
redisFree
freeReplyObject
redisCommand

### 结构体
redisContext
redisContextFuncs
