//
//  shader.cpp
//  testOpenGLByCPlusPlus
//
//  Created by 张钰 on 2018/3/10.
//  Copyright © 2018年 张钰. All rights reserved.
//

#include "shader.hpp"

using namespace std;

namespace openGLTool {
    Shader::Shader(std::string vertexPath,std::string fragmentPath){
        
        ifstream vertexFile,fragmentFile;
        
        vertexFile.exceptions(ifstream::failbit|ifstream::badbit);
        fragmentFile.exceptions(ifstream::failbit|ifstream::badbit);
        
        string vertexCode,fragmentCode;
        try {
            vertexFile.open(vertexPath.c_str());
            fragmentFile.open(fragmentPath.c_str());
            
            stringstream vertexStream,fragmentStream;
            
            vertexStream << vertexFile.rdbuf();
            fragmentStream << fragmentFile.rdbuf();
            
            vertexCode = vertexStream.str();
            fragmentCode = fragmentStream.str();
            
            
        } catch (ifstream::failure) {
            cout << "Read File Failed" << endl;
        }
        
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vShaderCode,NULL);
        glCompileShader(vertexShader);
        
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
        glCompileShader(fragmentShader);
        
        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
        
        if (!success) {
            glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
            std::cout << "ERROR::SHADER::Fragment::COMPILATION_FAILED\n" << infoLog << endl;
            
        }
        
        //unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            cout << "ERROR::PROGRAM\n" << infoLog << endl;
        }
        
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
       
    }
    
    void Shader::use(){
        
        glUseProgram(shaderProgram);
    }
}
