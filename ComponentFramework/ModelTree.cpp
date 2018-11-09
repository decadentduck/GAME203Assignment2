#include "ModelTree.h"
#include "QuadSphere.h"
#include "Shader.h"
#include "ObjLoader.h"
#include "Mesh.h"

using namespace GAME;

ModelTree::ModelTree():shader(nullptr) 
{
	OnCreate();
}

bool ModelTree::OnCreate()
{
	
	ObjLoader obj("Tree1.obj");
	
	meshes.push_back( new Mesh(GL_TRIANGLES, obj.vertices,obj.normals,obj.uvCoords));
	
	/// Create a shader with attributes
	shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");

	projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
	modelViewMatrixID = glGetUniformLocation(shader->getProgram(), "modelViewMatrix");
	normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
	lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");
	modelMatrix = MMath::translate(0.0f,0.3f,0.0f);
	return true;
}


void ModelTree::OnDestroy()
{
	glDeleteBuffers(1,  &vbo);
	if(shader) delete shader;

	for(Mesh* mesh : meshes) 
	{
		if(mesh) delete mesh;
	}	
}

void ModelTree::Update(const float deltaTime)
{
	
}

void ModelTree::SetLightPos(const Vec3& lightPos_)
{
	lightPos = lightPos_;
}


void ModelTree::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const
{
	glUseProgram(shader->getProgram());
	glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(modelViewMatrixID, 1, GL_FALSE, viewMatrix * modelMatrix * MMath::translate(-10.0f, -5.0f, 0.0f));
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	glUniform3fv(lightPosID, 1, lightPos);
	for(Mesh* mesh : meshes) 
	{
		mesh->Render();
	}
	glEnableVertexAttribArray(0); // Disable the VAO
}


ModelTree::~ModelTree()
{
	OnDestroy();
}