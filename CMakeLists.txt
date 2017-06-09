cmake_minimum_required(VERSION 3.7)
project(sentlog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  Sentlog.cpp Sentlog.h Tool.cpp Tool.h FileTool.cpp FileTool.h base64.cpp base64.h OutPut.cpp OutPut.h)
add_executable(sentlog ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(sentlog C:/Users/ai/Desktop/sentlog/sentlog/lib/hiredis/libhiredis.a)