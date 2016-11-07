#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Log.h"

#include "minecraftpe/EnderpearlItem.h"

void (*_hook)();
void hook(){
	Item::mEnderpearl=new EnderpearlItem("enderPearl",368-0x100);
	Item::mEnderpearl->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[368]=Item::mEnderpearl;
	_hook();
}

void (*_hook2)();
void hook2(){
	_hook2();
	Item::mEnderpearl->setIcon("ender_pearl",0);
}

void (*_hook3)();
void hook3(){
	_hook3();
	Item::addCreativeItem(Item::mEnderpearl,0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Item::registerItems,(void*)&hook,(void**)&_hook);
	MSHookFunction((void*)&Item::initClientData,(void*)&hook2,(void**)&_hook2);
	MSHookFunction((void*)&Item::initCreativeItems,(void*)&hook3,(void**)&_hook3);
	return JNI_VERSION_1_2;
}
