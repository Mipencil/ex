#include "Substrate.h"
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <sstream>
#include <android/log.h>

#include "ServerCommands.h"
#include "Minecraft.h"


void (*_Minecraft_hostMultiplayer)(Minecraft *,std::unique_ptr<Level,std::default_delete<Level>>&,std::unique_ptr<GameMode,std::default_delete<GameMode>>&,Player *,std::unique_ptr<NetEventCallback,std::default_delete<NetEventCallback>>&,int,bool,bool,std::string,int,int,int);
void Minecraft_hostMultiplayer(Minecraft *self,std::unique_ptr<Level,std::default_delete<Level>>&a,std::unique_ptr<GameMode,std::default_delete<GameMode>>&b,Player *c,std::unique_ptr<NetEventCallback,std::default_delete<NetEventCallback>>&d,int e,bool f,bool g,std::string h,int i,int j,int k){
	_Minecraft_hostMultiplayer(self,a,b,c,d,e,f,g,h,i,j,k);
	ServerCommands::setupStandardServer(*self->getCommandParser(),*self->getLevel());
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Minecraft::hostMultiplayer,(void*)&Minecraft_hostMultiplayer,(void**)&_Minecraft_hostMultiplayer);
	return JNI_VERSION_1_2;
}
