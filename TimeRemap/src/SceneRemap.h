//
//  SceneRemap.h
//  TimeRemap
//
//  Created by Yi-Wen Lin on 2015/1/12.
//
//

#ifndef __TimeRemap__SceneRemap__
#define __TimeRemap__SceneRemap__

#include <stdio.h>
#include "cinder/gl/Texture.h"
#include "Scene.h"
#include "ViewCopy.h"
#include "ViewRemap.h"
#include "cinder/Capture.h"

using namespace ci;
using namespace gl;
using namespace ci::app;
using namespace bongiovi;

class SceneRemap : public Scene {
    public :
    SceneRemap(app::WindowRef);
    void render();
    void initTextures();
    void initViews();
    
    
    private :
    bool            _hasVisuals = false;
    gl::Texture     _currentFrame;
    gl::Texture     _lastFrame;
    ViewCopy*       _vCopy;
    ViewRemap*      _vRemap;
    Capture         _capture;
    
    vector<gl::Texture> _textures;
};

#endif /* defined(__TimeRemap__SceneRemap__) */
