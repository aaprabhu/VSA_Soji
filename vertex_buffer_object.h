#ifndef VERTEX_BUFFER_OBJECT_IS_INCLUDED
#define VERTEX_BUFFER_OBJECT_IS_INCLUDED
/* { */

#include <ysgl.h>

class VertexBufferObject
{
private:
	VertexBufferObject &operator=(const VertexBufferObject &);
	VertexBufferObject(const VertexBufferObject &);

protected:
    GLuint vboIdent;

public:
    VertexBufferObject()
    {
        vboIdent=0;
    }
    ~VertexBufferObject()
    {
        CleanUp();
    }
    void CleanUp(void)
    {
        if(0!=vboIdent)
        {
            glDeleteBuffers(1,&vboIdent);
            vboIdent=0;
        }
    }
    void CreateBuffer(GLuint totalSizeInByte)
    {
        glGenBuffers(1,&vboIdent);
        glBindBuffer(GL_ARRAY_BUFFER,vboIdent);
        glBufferData(GL_ARRAY_BUFFER,totalSizeInByte,nullptr,GL_STATIC_DRAW);
    }
    GLuint GetVboIdent(void) const
    {
        return vboIdent;
    }
    GLuint GetZeroPointer(void)
    {
        return 0;
    }
    template <class T>
    GLuint PushBufferSubData(GLuint &currentPtr,GLuint n,const T incoming[])
    {
        auto returnPtr=currentPtr;
        auto bufLength=sizeof(T)*n;
        glBufferSubData(GL_ARRAY_BUFFER,currentPtr,bufLength,incoming);
        currentPtr+=bufLength;
        return returnPtr;
    }
};

class VertexBufferObjectVtxNomCol : public VertexBufferObject
{
public:
    GLuint vtxPtr,nomPtr,colPtr;
    VertexBufferObjectVtxNomCol()
    {
        vtxPtr=0;
        nomPtr=0;
        colPtr=0;
    }
};

/* } */
#endif
