#pragma once
#include "GL/glew.h"
#include <iostream>
#include <glm/glm.hpp>
static void printMat4(glm::mat4 mat) {
	for (int i(0); i < 4; i++) {
		std::cout
			<< mat[i][0] << " "
			<< mat[i][1] << " "
			<< mat[i][2] << " "
			<< mat[i][3] << " "
			<< std::endl;
	}
}
static void clearGL_CALL() {
	while (glGetError() != GL_NO_ERROR);
}

static void checkGL_CALL() {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL] error :" << error << std::endl;
	}
}

#define DEBUG
#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#define GL_CALL(x) clearGL_CALL(); x; checkGL_CALL()
#else
#define LOG(x)
#define GL_CALL(x) x
#endif