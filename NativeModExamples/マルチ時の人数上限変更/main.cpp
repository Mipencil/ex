#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <android/log.h>

#include "RakNetInstance.h"

void (*_RakNetInstance_host)(RakNetInstance*,std::string const&,int,int);
void RakNetInstance_host(RakNetInstance *_rakNet,std::string const&_string,int _int_1,int _int_2){
	_RakNetInstance_host(_rakNet,_string,_int_1,20);
}

void (*_RakNetInstance__startupIfNeeded)(RakNetInstance*,unsigned short,int);
void RakNetInstance__startupIfNeeded(RakNetInstance *_rakNet,unsigned short _ushort,int _int){
	_RakNetInstance__startupIfNeeded(_rakNet,_ushort,20);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&RakNetInstance::host,(void*)&RakNetInstance_host,(void**)&_RakNetInstance_host);
	MSHookFunction((void*)&RakNetInstance::_startupIfNeeded,(void*)&RakNetInstance__startupIfNeeded,(void**)&_RakNetInstance__startupIfNeeded);
	return JNI_VERSION_1_2;
}
