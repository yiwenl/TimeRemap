#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneRemap.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TimeRemapApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
private:
    SceneRemap*     _scene;
};

void TimeRemapApp::setup()
{
    setWindowSize(1280, 720);
    setWindowPos(0, 0);
    setFrameRate(60);
    srand (time(NULL));
    
    _scene = new SceneRemap(getWindow());
    enableAlphaBlending();
}

void TimeRemapApp::mouseDown( MouseEvent event )
{
}

void TimeRemapApp::update()
{
//    cout << getAverageFps() << endl;
}

void TimeRemapApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    _scene->render();
}

CINDER_APP_NATIVE( TimeRemapApp, RendererGl )
