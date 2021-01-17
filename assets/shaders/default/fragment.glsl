#version 430 core

in vec4 fColor;
in vec2 fTextureCoods;

out vec4 color;

uniform float uTime;
uniform sampler2D tex1;

void main()
{
    color = texture(tex1, fTextureCoods) * fColor;
}