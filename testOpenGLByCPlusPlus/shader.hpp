//
//  shader.hpp
//  testOpenGLByCPlusPlus
//
//  Created by 张钰 on 2018/3/10.
//  Copyright © 2018年 张钰. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <glad/glad.h>
#include <string>


namespace openGLTool {
    class Shader{
    public:
        Shader(std::string vertexPath,std::string fragmentPath);
        void use();
    private:
        GLuint shaderProgram;
        
    };
}



#endif /* shader_hpp */
