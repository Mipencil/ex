#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "minecraftpe/Item.h"

void (*_Item$registerItems)();
void Item$registerItems(){
	Item::mItems[511]=new Item("enderApple",511-0x100);
	Item::mItemLookupMap.emplace("enderapple",std::unique_ptr<Item>(Item::mItems[511]));
	_Item$registerItems();
}

void (*_Item$initClientData)();
void Item$initClientData(){
	_Item$initClientData();
	Item::mItems[511]->setIcon("apple",0);
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems(){
	_Item$initCreativeItems();
	Item::addCreativeItem(Item::mItems[511],0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Item::registerItems,(void*)&Item$registerItems,(void**)&_Item$registerItems);
	MSHookFunction((void*)&Item::initClientData,(void*)&Item$initClientData,(void**)&_Item$initClientData);
	MSHookFunction((void*)&Item::initCreativeItems,(void*)&Item$initCreativeItems,(void**)&_Item$initCreativeItems);
	return JNI_VERSION_1_2;
}
