var PackageManager=android.content.pm.PackageManager;

var activity=com.mojang.minecraftpe.MainActivity.currentMainActivity.get();

function checkApplication(packageName){
	try{
		packageManager=activity.getPackageManager();
		packageManager.getApplicationInfo(packageName,PackageManager.GET_META_DATA);
		return true;
	}catch(err){
		return false;
	}
}

if(checkApplication("jp.kuukai.tweet.mcpe")){
	//インストールされている時の処理
}else{
	//インストールされていない時の処理
}

