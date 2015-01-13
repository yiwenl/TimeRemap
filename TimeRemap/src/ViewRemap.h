//
//  ViewRemap.h
//  TimeRemap
//
//  Created by Yi-Wen Lin on 2015/1/12.
//
//

#ifndef __TimeRemap__ViewRemap__
#define __TimeRemap__ViewRemap__

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "View.h"

using namespace bongiovi;

class ViewRemap : public View {
    public :
    ViewRemap();
    void render(gl::Texture, gl::Texture, float, float);
    
    
    private :
    void        _init();
};

#endif /* defined(__TimeRemap__ViewRemap__) */
