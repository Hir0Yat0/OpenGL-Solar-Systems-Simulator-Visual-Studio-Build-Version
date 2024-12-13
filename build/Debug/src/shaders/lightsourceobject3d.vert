#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform float timeMillis;
uniform float deltaTimeMillis;

uniform float vScale0;
uniform float vScale1;
uniform float vScale2;

uniform float vPosition0;
uniform float vPosition1;
uniform float vPosition2;

uniform float vOrientation0;
uniform float vOrientation1;
uniform float vOrientation2;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

mat4 getRotationMatrix(float rx, float ry, float rz, float theta){
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    return mat4(
        cosTheta + pow(rx,2.0)*(1.0-cos(theta)), rx*ry*(1.0-cosTheta)-rz*sinTheta, rx*rz*(1.0-cosTheta) + ry*sinTheta, 0.0,
        ry*rx*(1.0-cosTheta)+rz*sinTheta, cosTheta + pow(ry,2.0)*(1.0-cosTheta), ry*rz*(1.0-cosTheta) - rx*sinTheta, 0.0,
        rz*rx*(1.0-cosTheta) - ry*sinTheta, rz*ry*(1.0-cosTheta) + rx*sinTheta, cosTheta + pow(rz,2.0)*(1.0-cosTheta), 0.0,
        0.0,0.0,0.0,1.0  
    );
}

void main(){

    vec4 vPos4 = vec4(aPos,1.0);
    // vec4 vPos4 = vec4(aPos.xyz,1.0);
    mat4 idMat4 =  mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0 
    );
    // mat4 scaleMat4 = mat4 ( 
    //     vScale0, 0.0, 0.0, 0.0,  
    //     0.0, vScale1, 0.0, 0.0,  
    //     0.0, 0.0, vScale2, 0.0,  
    //     0.0, 0.0, 0.0, 1.0  
    // );
    // // const mat4 rotationXMat4 = getRotationMatrix(1.0,0.0,0.0,vOrientation0);
    // // const mat4 rotationYMat4 = getRotationMatrix(0.0,1.0,0.0,vOrientation1);
    // // const mat4 rotationZMat4 = getRotationMatrix(0.0,0.0,1.0,vOrientation2);
    // mat4 rotationXMat4 = mat4 (
    //     1.0, 0.0, 0.0, 0.0, 
    //     0.0, cos(vOrientation0), -sin(vOrientation0), 0.0, 
    //     0.0, sin(vOrientation0), cos(vOrientation0), 0.0, 
    //     0.0, 0.0, 0.0, 1.0 
    // );
    // mat4 rotationYMat4 = mat4 (
    //     cos(vOrientation1), 0.0, -sin(vOrientation1), 0.0,
    //     0.0, 1.0, 0.0, 0.0,
    //     -sin(vOrientation1), 0.0, cos(vOrientation1), 0.0,
    //     0.0, 0.0, 0.0, 1.0
    // );
    // mat4 rotationZMat4 = mat4 (
    //     cos(vOrientation2), -sin(vOrientation2), 0.0, 0.0,
    //     sin(vOrientation2), cos(vOrientation2), 0.0, 0.0,
    //     0.0, 0.0, 1.0, 0.0,
    //     0.0, 0.0, 0.0, 1.0 
    // );
    // mat4 rotationMat4 = rotationZMat4 * rotationYMat4 * rotationXMat4;
    // mat4 translationMat4 = mat4 (
    //     1.0, 0.0, 0.0, vPosition0, 
    //     0.0, 1.0, 0.0, vPosition1, 
    //     0.0, 0.0, 1.0, vPosition2, 
    //     0.0, 0.0, 0.0, 1.0 
    // );

    // mat4 model = translationMat4 * rotationMat4 * scaleMat4 * idMat4;

    mat4 transformationMat4 = projection * view * model * idMat4;

    vec4 fPos4 = transformationMat4 * vPos4;

    // vec3 spinningVertices = getRotationMatrix(1.0,0.0,0.0,timeMillis) * aPos;

    gl_Position = fPos4;
    TexCoord = aTexCoord;

}
