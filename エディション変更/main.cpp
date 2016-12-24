#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Substrate.h"
#include "Log.h"

std::string EduMode(void *self){
	return "pocket";
	return "win10";//Gui変更できるようになったからいらないよね
	return "osx";//バグあり
	return "edu";//よくわからん
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction(dlsym(RTLD_DEFAULT,"_ZNK11AppPlatform10getEditionEv"),(void*)&EduMode,NULL);
	return JNI_VERSION_1_2;
}
