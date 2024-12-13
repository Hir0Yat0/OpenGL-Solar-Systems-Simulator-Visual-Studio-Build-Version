#include "Shape.hpp"

#include<algorithm>

Shape::Shape(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) 
: vertices{vertices}, indices{indices}, vao{}, vbo{}, ebo{}
{
    // if (!withTextures){
    //     this->initShape();
    // }
    // else {
    //     this->initShapeWithTexture();
    // }
}

Shape::~Shape() {
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    glDeleteBuffers(1, &this->ebo);
}

void Shape::initShape() {
    glGenVertexArrays(1,&this->vao);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(this->vao);

    glGenBuffers(1,&this->ebo);
    glGenBuffers(1,&this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER,this->vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertices.size(),&vertices[0],GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*this->indices.size(),&this->indices[0],GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void Shape::initShapeWithTexture(bool isLightSource) {
    glGenVertexArrays(1,&this->vao);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(this->vao);

    glGenBuffers(1,&this->ebo);
    glGenBuffers(1,&this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER,this->vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertices.size(),&vertices[0],GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*this->indices.size(),&this->indices[0],GL_STATIC_DRAW);
    
    constexpr int vertexAttributeSize = 8*sizeof(float); /*stride*/

    // vertex position
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,vertexAttributeSize,(void*)0);
    glEnableVertexAttribArray(0);

    //  texture coords
    glVertexAttribPointer(1/*offsets*/,2/*count*/,GL_FLOAT,GL_FALSE,vertexAttributeSize,(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    if (!isLightSource){
        {
            // normals
            constexpr int location = 2;
            constexpr int count = 3;
            constexpr int type = GL_FLOAT;
            constexpr int normalized = GL_FALSE;
            constexpr int offset = 5*sizeof(float);
            glVertexAttribPointer(location,count,type,normalized,vertexAttributeSize,(void*)offset);
            glEnableVertexAttribArray(location);
        }

    }

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void Shape::use() {
    glBindVertexArray(this->vao);
}

void Shape::draw() {
    this->use();
    glDrawElements(GL_TRIANGLES,this->indices.size(),GL_UNSIGNED_INT,0);
}

template<class T>
void Shape::groupVertexAttributes(std::vector<T>& out_verticeAttributes, const std::vector<std::vector<T>>& vertexAttributes, const std::vector<unsigned int>& eachAttributesLength)
{
    const unsigned int numAttributes = std::min(vertexAttributes.size(),eachAttributesLength.size());
    // find min num of vertices
    std::vector<unsigned int> numVerticesEachAttributes(numAttributes);
    for (unsigned int i = 0; i < numAttributes;i++){
        numVerticesEachAttributes[i] = eachAttributesLength[i] <= 0 ? 0: vertexAttributes[i].size() / eachAttributesLength[i];
    }
    // for (){
        
    // }
    const unsigned int numVertices = *std::min_element(numVerticesEachAttributes.begin(),numVerticesEachAttributes.end());

    for (unsigned int k = 0; k < numVertices; k++){
        for (unsigned int i = 0; i < numAttributes;i++){
            for (unsigned int j = 0; j < eachAttributesLength[j];j++){
                out_verticeAttributes.push_back(vertexAttributes[i][k*eachAttributesLength[i] + j]);
            }
        }
    }
}
