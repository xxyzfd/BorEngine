#version 130 // referring to OpenGL 3.0

in vec2 vertexPosition;

void main(){
	gl_Position.xy = vertexPosition; // .xy is called swizzeling in GLSL
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
}