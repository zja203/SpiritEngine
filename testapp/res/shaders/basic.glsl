
#type vertex
#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 u_MVP;

void main() {
	gl_Position = u_MVP * position;
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;

void main (void) {
	color = vec4(0.75,0.1,0.1,1.0);
}
