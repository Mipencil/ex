#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>

#include "Recipes.h"
#include "FurnaceRecipes.h"

void (*_Recipes_init)(Recipes*);
void Recipes_init(Recipes* _recipes) {
	_Recipes_init(_recipes);
	_recipes->clearRecipes();
}

void (*_FurnaceRecipes_addFurnaceRecipe)(FurnaceRecipes*);
void FurnaceRecipes_addFurnaceRecipe(FurnaceRecipes *_furnaceRecipes){}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Recipes::init,(void*)&Recipes_init,(void**)&_Recipes_init);
	MSHookFunction((void*)&FurnaceRecipes::addFurnaceRecipe,(void*)&FurnaceRecipes_addFurnaceRecipe,(void**)&_FurnaceRecipes_addFurnaceRecipe);
	return JNI_VERSION_1_2;
}
