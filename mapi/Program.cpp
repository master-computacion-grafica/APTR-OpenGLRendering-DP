// #include "Program.h"
//
// void Program::linkProgram()
// {
//     //crear programa
//     programId = glCreateProgram();
//
//     //por cada shader en shaderList
//     for(auto &c: shaderList)
//     { 
//         //compilar
//         Shader shader(c);
//         if(shader.compiled)
//         {
//         //atar al programa
//             glAttachShader(programId, shader.shaderId);
//         }
//     }
//     //linkar programas
//     glLinkProgram(programId);
//     
//     //test error linkados
//     GLint program_linked;
//     glGetProgramiv(programId, GL_LINK_STATUS, &program_linked);
//     if (program_linked != GL_TRUE)
//     {
//         GLsizei log_length = 0;
//         GLchar message[1024];
//         glGetProgramInfoLog(programId, 1024, &log_length, message);
//         std::cout << "ERROR Linkando programa \"" << message << "\"\n";
//     }
//     else {
//         linked = true;
//     }
//
//     readVarList();
//     //linpiar datos
//
//
// }
//
// void Program::readVarList()
// {
//     //activar este programa
//     glUseProgram(this->programId);
//     //leer identificadores de variables atributo
//         //numero de variables activas
//     int numAttributes = 0;
//     glGetProgramiv(programId, GL_ACTIVE_ATTRIBUTES, &numAttributes);
//     //por cada variable
//     for(int i=0;i<numAttributes;i++){
//         //leer su nombre
//         char name[101]; //nombre m�ximo de 100 caracteres
//         int size; //bytes de la variable
//         unsigned int type; //GLEnum para float, char, etc...
//         int length; //numero de elementos si es un array/vector
//         glGetActiveAttrib(programId, (GLuint)i, 100, &length, &size, &type, name);
//         //obtener su ubicacion (layout)
//         int layout = glGetAttribLocation(programId, name);
//         //almacenar par nombre/ubicacion
//         varList[std::string(name)] = layout;
//     }
//
//     //leer identificadores de variables uniform 
//
//     int numUniforms = 0;
//     glGetProgramiv(programId, GL_ACTIVE_UNIFORMS, &numUniforms);
//     //por cada variable
//     for (int i = 0;i < numUniforms;i++) {
//         //leer su nombre
//         char name[101]; //nombre m�ximo de 100 caracteres
//         int size; //bytes de la variable
//         unsigned int type; //GLEnum para float, char, etc...
//         int length; //numero de elementos si es un array/vector
//         glGetActiveUniform(programId, (GLuint)i, 100, &length, &size, &type, name);
//         //obtener su ubicacion (layout)
//         int layout = glGetUniformLocation(programId, name);
//         //almacenar par nombre/ubicacion
//         varList[std::string(name)] = layout;
//     }
//
// }
//
// void Program::setAttributeMetaData(string attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
// {
//     //si existe
//     if(varList.find(attribName)!=varList.end()){
//     //activar variable atributo
//
//         glEnableVertexAttribArray( varList[attribName]);
//     // 
//     //describir variable atributo
//         glVertexAttribPointer(varList[attribName], size, type, normalized, stride, pointer);
//     }
//     else {
//         cout << "ERROR Atributo " << attribName << " no encontrado\n";
//     }
// }
//
// void Program::setMVP(glm::mat4 m)
// {
//     //si existe
//     if (varList.find("MVP") != varList.end()) {
//         //actualizar variable uniform
//         glUniformMatrix4fv(varList["MVP"], 1, false, &m[0][0]);
//     }
//     else {
//         cout << "ERROR Atributo " << "MVP" << " no encontrado\n";
//     }
//     //actualizar datos
//
// }
//
// void Program::setTextureData(int textureUnit, int textureId, GLenum textureType)
// {
//     glActiveTexture(GL_TEXTURE0 + textureUnit); //activar
//     glBindTexture(textureType, textureId); //enlazar
//     glUniform1i(varList["colorText"], textureUnit); //usar en shader
//     glUniform1i(varList["useColorText"], 1); //usar en shader
// }
