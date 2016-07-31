#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>

#include "Particle.h"

void (*_hook1)(Particle*,Tessellator &,float,float,float,float,float,float);
void (*_hook2)(Particle*,Tessellator &,float,float,float,float,float,float);
void (*_hook3)(Particle*,Tessellator &,float,float,float,float,float,float);

void hook1(Particle* a,Tessellator &b,float c,float d,float e,float f,float g,float h){
}
void hook2(Particle* a,Tessellator &b,float c,float d,float e,float f,float g,float h){
}
void hook3(Particle* a,Tessellator &b,float c,float d,float e,float f,float g,float h){
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&Particle::render,(void*)&hook1,(void**)&_hook1);
	MSHookFunction((void*)&BreakingItemParticle::render,(void*)&hook2,(void**)&_hook2);
	MSHookFunction((void*)&TerrainParticle::render,(void*)&hook3,(void**)&_hook3);
	return JNI_VERSION_1_2;
}
