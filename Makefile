#-*- coding: utf-8 -*-
#Filename:	Makefile
#Porject	:	
#Author	:	zerozakiGeek
#Email	:	zerozakiGeek@gmail.com
#Date	:	2016-08-16
LOCAL_MODULE := sdat2img
LOCAL_SRC_FILES := \
	TransferList.cpp \
	OutPutImage.cpp \
	main.cpp
LOCAL_C_INCLUDES += \
	./include
LOCAL_CFLAGS := \
	-std=c++11 -Wall -Wextra -I$(LOCAL_C_INCLUDES)
LOCAL_OBJ_FILES := $(LOCAL_SRC_FILES:.cpp=.o)
LOCAL_CXX := g++
all:$(LOCAL_MODULE)
$(LOCAL_MODULE):$(LOCAL_OBJ_FILES)
	@$(LOCAL_CXX) $(LOCAL_OBJ_FILES) -o $(LOCAL_MODULE) $(LOCAL_CFLAGS)
	-@rm $(LOCAL_OBJ_FILES)
$(LOCAL_OBJ_FILES):$(LOCAL_SRC_FILES)
	@$(LOCAL_CXX) $(LOCAL_SRC_FILES) -c $(LOCAL_CFLAGS)
.PHONY:clean
clean:
	-@rm -rf $(LOCAL_MODULE)
