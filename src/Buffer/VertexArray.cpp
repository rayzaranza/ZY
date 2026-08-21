#include "VertexArray.h"
#include <glad/glad.h>


ZY::VertexArray::VertexArray()
{
	glGenVertexArrays(1, &id);
	bind();
}

ZY::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id);

}

void ZY::VertexArray::bind() const
{
	glBindVertexArray(id);
}

void ZY::VertexArray::addBuffer(const VertexBuffer& buffer, const IndexBuffer& indexBuffer)
{
	bind();
	buffer.bind();
	indexBuffer.bind();
	indicesCount = indexBuffer.count;

	for (const VertexAttribute& attribute : buffer.attributes)
	{
		const void* offset{ (const void*)(sizeof(float) * attribute.count * attribute.location) };
		glEnableVertexAttribArray(attribute.location);
		glVertexAttribPointer(attribute.location, attribute.count, attribute.type, GL_FALSE, buffer.stride, offset);
	}
}
