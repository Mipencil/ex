#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Substrate.h"
#include "minecraftpe/Item.h"
#include "minecraftpe/BlockItem.h"
#include "minecraftpe/Block.h"
#include "minecraftpe/BlockGraphics.h"

void (*_Item$addBlockItems)();
void Item$addBlockItems(){
	_Item$addBlockItems();
	Item::mItems[220]=new BlockItem("testBlock",220-0x100);
	Item::mItemLookupMap.emplace("testblock",std::unique_ptr<Item>(Item::mItems[220]));
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems(){
	_Item$initCreativeItems();
	Item::addCreativeItem(Block::mBlocks[220],0);
}

void (*_Block$initBlocks)();
void Block$initBlocks(){
	_Block$initBlocks();
	Block::mBlocks[220]=new Block("testBlock",220,Material::getMaterial(MaterialType::DEFAULT));
	Block::mBlocks[220]->init();
	Block::mBlocks[220]->setCategory(CreativeItemCategory::BUILDINGS);
	Block::mBlocks[220]->setSolid(false);
	Block::mBlockLookupMap.emplace("testblock",Block::mBlocks[220]);
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(Block::mBlocks[220]));
}

void (*_BlockGraphics$initBlocks)();
void BlockGraphics$initBlocks(){
	_BlockGraphics$initBlocks();
	BlockGraphics::mBlocks[220]=new BlockGraphics(Block::mBlocks[220]->name);
	BlockGraphics::mBlockLookupMap.emplace("testblock",BlockGraphics::mBlocks[220]);
	BlockGraphics::mBlocks[220]->setTextureItem("stone");
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Item::addBlockItems,(void*)&Item$addBlockItems,(void**)&_Item$addBlockItems);
	MSHookFunction((void*)&Item::initCreativeItems,(void*)&Item$initCreativeItems,(void**)&_Item$initCreativeItems);
	MSHookFunction((void*)&Block::initBlocks,(void*)&Block$initBlocks,(void**)&_Block$initBlocks);
	MSHookFunction((void*)&BlockGraphics::initBlocks,(void*)&BlockGraphics$initBlocks,(void**)&_BlockGraphics$initBlocks);
	return JNI_VERSION_1_2;
}
