//他modとの連携について...
//BLの関数は各modに関数を適応させる仕組みになっています
//他modの連携には関数を適応させる関数を使用し登録します
//使用するJavaのクラスは以下の2つです
var ScriptManager=net.zhuoweizhang.mcpelauncher.ScriptManager;
var ScriptableObject=org.mozilla.javascript.ScriptableObject;

//テスト用クラス
var TestClass={
	view:function(){
		print("関数が実行されました"); //実行の確認
	},
};

//関数適用のための関数です
function initClass(){
	//まず、modの一覧を取得します(javaのListで帰ってきます)
	var scripts=ScriptManager.scripts;
	//全てのmodに適応させるためにforを書きます
	for(var loop=0;loop<scripts.size();loop++){
		//１つのmodを取得します
		var script=scripts.get(loop);
		//modはすべて読み込まれてしまうので自身のmodのみ適応させないようにします
		if(script.name=="TestClass.js"){
			continue;
		}
		//読み込まれているmodのscriptableを用意します
		var scriptable=script.scope;
		//用意したscriptableとクラス名、関数の内容を読み込んだmodに適応させて完成です
		ScriptableObject.putProperty(scriptable,"TestClass",TestClass);
		//他modでは関数を呼び出すだけで実行することができます
	}
}

//他modで実行する際は[TestClass.view();]とかく