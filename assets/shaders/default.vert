#version 460 core

layout (location = 0) in vec2 a_Position;

void main()
{
	vec4 position = vec4(a_Position, 0.0f, 1.0f);
	gl_Position = position;
}