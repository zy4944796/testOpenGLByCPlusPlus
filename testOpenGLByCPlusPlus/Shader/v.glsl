#version 330 core
layout (location = 0) in vec3 postion;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(postion.x,-postion.y,postion.z,1.0);
    ourColor = color;
    TexCoord = vec2(texCoord.x,texCoord.y);
}
