#version 330 core
layout (location = 0) in vec3 positions;
//layout (location = 1) in vec3 colors;
//layout (location = 2) in vec3 aNormal;

//out vec3 Colors;
uniform mat4 model;
//uniform mat4 view;
uniform mat4 projection;
//
//uniform vec3 color;
//
//out vec3 FragPos;
//out vec3 Normal;
void main()
{
    //FragPos = vec3(model * vec4(positions, 1.0));
    //Normal = mat3(transpose(inverse(model))) * aNormal;  
    //gl_Position =  model *  vec4(positions, 1.0);
    gl_Position = projection * model * vec4(positions, 1.0);
    //Colors=colors;
}
