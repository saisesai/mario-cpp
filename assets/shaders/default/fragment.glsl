#version 430 core

in vec4 fColor;

out vec4 color;

uniform float uTime;

void main()
{
    float noise = fract(sin(dot(fColor.xy, vec2(12.9898, 73.233))) * 43758.5453);
    color = noise * fColor;
}