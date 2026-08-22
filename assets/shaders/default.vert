#version 460 core

layout (location = 0) in vec2 a_Position;

uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	vec4 position = vec4(a_Position, 0.0f, 1.0f);
	gl_Position = u_Projection * u_View * position;
}