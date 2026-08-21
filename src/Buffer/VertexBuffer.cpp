#include "VertexBuffer.h"

ZY::VertexBuffer::VertexBuffer(const VertexBufferData& data, GLenum usage)
{
	glGenBuffers(1, &id);
	bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), usage);
}

ZY::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}

void ZY::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void ZY::VertexBuffer::setAttributes(const VertexBufferLayout& attributes)
{
	this->attributes = attributes;
	calculateStride();
}

void ZY::VertexBuffer::calculateStride()
{
	for (const VertexAttribute& attribute : attributes)
	{
		stride += attribute.count * sizeof(float);
	}
}
