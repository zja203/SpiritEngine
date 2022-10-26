#include "platform/opengl/opengl_renderapi.hpp"
#include <GL/glew.h>

namespace Spirit {
	void OpenGLMessageCallback(unsigned source, unsigned type, unsigned id, unsigned severity, int length, const char* message, const void* userParam) {
		switch (severity) {
			case GL_DEBUG_SEVERITY_HIGH:         SPRT_CORE_CRITICAL(message); return;
			case GL_DEBUG_SEVERITY_MEDIUM:       SPRT_CORE_ERROR(message); return;
			case GL_DEBUG_SEVERITY_LOW:          SPRT_CORE_WARN(message); return;
			case GL_DEBUG_SEVERITY_NOTIFICATION: SPRT_CORE_TRACE(message); return;
		}
		
		SPRT_CORE_ASSERT(false, "Unknown severity level!");
	}

	void OpenGLRenderAPI::Init() {
	#ifdef SPRT_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);
		
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);

		glEnable(GL_DEBUG_OUTPUT);
	#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_LINE_SMOOTH);
	}

	void OpenGLRenderAPI::drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount) {
		vertexArray->Bind();
		uint32_t count = indexCount ? indexCount : vertexArray->getIndexBuffer()->getCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}
}
