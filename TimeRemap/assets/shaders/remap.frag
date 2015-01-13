uniform sampler2D   texture;
uniform sampler2D   textureNext;
uniform float total;
uniform float current;

void main(void) {
    vec2 uv  = gl_TexCoord[0].st;
    uv.y = 1.0 - uv.y;
    float offset = 1.0 / total;
    
    if(uv.y < current*offset) gl_FragColor = vec4(.0);
    else if(uv.y > (current+1.0)*offset) gl_FragColor = vec4(.0);
    else {
        float p = (uv.y - current*offset) / offset;
        vec4 current    = texture2D(texture, uv);
        vec4 next       = texture2D(textureNext, uv);
        gl_FragColor    = mix(current, next, p);
    }
}