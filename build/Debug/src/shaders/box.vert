#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform float time;

mat3 getRotationMatrix(vec3 angles) {
    vec3 cos_angles = cos(angles);
    vec3 sin_angles = sin(angles);
    return mat3(
        cos_angles.x * cos_angles.y , 
        cos_angles.x * sin_angles.y * sin_angles.z - sin_angles.x * cos_angles.z , 
        cos_angles.x * sin_angles.y * cos_angles.z + sin_angles.x * sin_angles.z   ,

        sin_angles.x * cos_angles.y,
        sin_angles.x * sin_angles.y * sin_angles.z + cos_angles.x * cos_angles.z,
        sin_angles.x * sin_angles.y * cos_angles.z - cos_angles.x * sin_angles.z,

        -sin_angles.y, 
        cos_angles.y * sin_angles.z,
        cos_angles.y * cos_angles.z

    );
}


void main(){

    mat3 rotationMatrix = getRotationMatrix(vec3(time,time,time));
    gl_Position = vec4(rotationMatrix * aPos, 1.0);
    TexCoord = aTexCoord;

}
