//
//  SceneRemap.cpp
//  TimeRemap
//
//  Created by Yi-Wen Lin on 2015/1/12.
//
//

#include "SceneRemap.h"


SceneRemap::SceneRemap(app::WindowRef window) : Scene(window) {
    initTextures();
    initViews();
}


void SceneRemap::initTextures() {
    _capture = Capture(640, 480);
    _capture.start();
}


void SceneRemap::initViews() {
    _vCopy = new ViewCopy();
    _vRemap = new ViewRemap();
}


void SceneRemap::render() {
    if(_capture.checkNewFrame()) {
        Surface surface( _capture.getSurface() );
        _textures.push_back(gl::Texture( surface ));
        _hasVisuals = true;
    }
    
    int maxSize = 72*1.5;
    
    if(!_hasVisuals) return;
    if(_textures.size() < maxSize) return;
    if(_textures.size() > maxSize) {
//        vector<gl::Texture>::iterator it = _textures.
        _textures.erase(_textures.begin());
    }
    
    gl::setMatrices(*_cameraOrtho);
    for(int i = 0; i<_textures.size(); i++) {
        if(i < _textures.size() - 1) {
            _vRemap->render(_textures[i], _textures[i+1], float(i), float(_textures.size()));
        } else {
            _vRemap->render(_textures[i], _textures[i], float(i), float(_textures.size()));
        }
    }

}