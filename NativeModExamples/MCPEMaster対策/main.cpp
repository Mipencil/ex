#include <jni.h>

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	JNIEnv *env;
	int envStatus=vm->GetEnv((void**)&env,JNI_VERSION_1_6);
	if(envStatus==JNI_EDETACHED){
		vm->AttachCurrentThread(&env,nullptr);
	}
	jclass mainActivityClass=env->FindClass("com/mojang/minecraftpe/MainActivity");
	jfieldID currentMainField=env->GetStaticFieldID(mainActivityClass,"currentMainActivity","Ljava/lang/ref/WeakReference;");
	jobject mainInstanceWeak=env->GetStaticObjectField(mainActivityClass,currentMainField);
	jclass referenceClass=env->FindClass("java/lang/ref/Reference");
	jmethodID refGetID=env->GetMethodID(referenceClass,"get","()Ljava/lang/Object;");
	jobject mainInstance=env->CallObjectMethod(mainInstanceWeak,refGetID);
	jclass contextClass=env->FindClass("android/content/Context");
	jmethodID packageManagerGetID=env->GetMethodID(contextClass,"getPackageManager","()Landroid/content/pm/PackageManager;");
	jobject packageManager=env->CallObjectMethod(mainInstance, packageManagerGetID);
	jclass packageManagerClass=env->FindClass("android/content/pm/PackageManager");
	jmethodID intentGetID=env->GetMethodID(packageManagerClass,"getLaunchIntentForPackage","(Ljava/lang/String;)Landroid/content/Intent;");
	jobject intent=env->CallObjectMethod(packageManager, intentGetID,env->NewStringUTF("com.groundhog.mcpemaster"));
	if(intent==nullptr){
		//未インストール
	}else{
		//インストール時
	}
	if(envStatus==JNI_EDETACHED){
		vm->DetachCurrentThread();
	}
	return JNI_VERSION_1_2;
}
