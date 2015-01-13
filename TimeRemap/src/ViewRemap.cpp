//
//  ViewRemap.cpp
//  TimeRemap
//
//  Created by Yi-Wen Lin on 2015/1/12.
//
//

#include "ViewRemap.h"
#include "MeshUtils.h"

ViewRemap::ViewRemap() : View("shaders/copy.vert", "shaders/remap.frag") {
    _init();
}


void ViewRemap::_init() {
    mesh = bongiovi::MeshUtils::createPlane(2, 1);
}


void ViewRemap::render(gl::Texture texture, gl::Texture textureNext, float current, float total) {
    shader->bind();
    shader->uniform("texture", 0);
    shader->uniform("textureNext", 1);
    shader->uniform("current", current);
    shader->uniform("total", total);
    texture.bind(0);
    textureNext.bind(1);
    gl::draw(mesh);
    texture.unbind();
    textureNext.unbind();
    shader->unbind();
}