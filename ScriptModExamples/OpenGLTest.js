/*
	描画できませんでした...
*/

var GLSurfaceView=android.opengl.GLSurfaceView;
var GL10=javax.microedition.khronos.opengles.GL10;

var gLSurfaceViewRenderer=new GLSurfaceView.Renderer({
	onDrawFrame:function(gl){
		gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
	},
	onSurfaceChanged:function(gl,width,height){
		gl.glViewport(0,0,width,height);
	},
	onSurfaceCreated:function(gl,config){
	}
});