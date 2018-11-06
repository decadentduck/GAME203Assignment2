#ifndef MODEL0_H
#define MODEL0_H
#include <GL/glew.h>
#include "Model.h"

namespace GAME
{

	/// Forward declarations;
	class Shader;
	class QuadSphere;

	class Model1 :public Model
	{
	public:
		Model1();


		Model1(const Model1&) = delete;
		Model1(Model1&&) = delete;
		Model1& operator = (const Model1&) = delete;
		Model1& operator = (Model1&&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render(const Matrix4& projectionMatrix, const Matrix4& modelViewMatrix, const Matrix3& normalMatrix) const;
		virtual ~Model1();
		void AddMeshes(ObjLoader &object);
		void AddSprites();
		void SetLightPos(const Vec3&);
	private:

		Shader * shader;
		GLuint vbo;
		GLuint vao;
		GLint verticiesID;
		GLint normalsID;
		GLint uvCoordsID;

		GLint projectionMatrixID;
		GLint modelViewMatrixID;
		GLint normalMatrixID;
		GLint lightPosID;
		Vec3 lightPos;
	};
}
#endif
