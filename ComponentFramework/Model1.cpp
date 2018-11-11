#include "Model1.h"
#include "Shader.h"
#include "ObjLoader.h"
#include "Camera.h"
#include "SceneEnvironment.h"
#include "Trackball.h"

namespace GAME {

	Model1::Model1(const Vec3 pos_, const Vec3 orientation_) {
		pos = pos_;
		orientation = orientation_;
		rotation = 0.0f;
		scale = 1.0f;
		shader = nullptr;
	}

	Model1::Model1(const Vec3 pos_, const Vec3 orientation_, const float rotation_, const float scale_) {
		pos = pos_;
		orientation = orientation_;
		rotation = rotation_;
		scale = scale_;
		shader = nullptr;
	}

	Model1::~Model1() {
		OnDestroy();
	}

	void Model1::setPos(const Vec3& pos_) {
		Entity::setPos(pos_);
		updateModel1Matrix();
	}

	void Model1::setOrientation(const Vec3& orientation_) {
		Entity::setOrientation(orientation_);
		updateModel1Matrix();
	}

	void Model1::updateModel1Matrix() {
		Model1Matrix = MMath::translate(pos);

		/// This transform is based on Euler angles - let's do it later
		///Model1Matrix = MMath::translate(pos) * MMath::rotate(orientation.z, Vec3(0.0f, 0.0f, 1.0f)) * MMath::rotate(orientation.x, Vec3(1.0f, 0.0f, 0.0f)) * MMath::rotate(orientation.y, Vec3(0.0f, 1.0f, 0.0f));
	}

	bool Model1::OnCreate() {
		shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");
		return true;
	}



	bool Model1::LoadMesh(const char* filename) {
		if (ObjLoader::loadOBJ(filename) == false) {
			return false;
		}
		/// Get the data out of the ObjLoader and into our own mesh
		meshes.push_back(new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords));
		return true;
	}


	void Model1::Update(const float deltaTime) {
		/// See Entity.h
		///Rotate(Vec3(0.0f, 50.0f * deltaTime, 0.0f));
	}

	void Model1::Render() const {

		GLint projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
		GLint viewMatrixID = glGetUniformLocation(shader->getProgram(), "viewMatrix");
		GLint Model1MatrixID = glGetUniformLocation(shader->getProgram(), "Model1Matrix");
		GLint normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
		GLint lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");

		glUseProgram(shader->getProgram());

		glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, Camera::currentCamera->getProjectionMatrix());
		glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, Camera::currentCamera->getViewMatrix());
		Matrix4 _ModelMatrix = MMath::rotate(rotation, 0.0f, 1.0f, 0.0f) * MMath::scale(scale, scale, scale) * Model1Matrix;
		glUniformMatrix4fv(Model1MatrixID, 1, GL_FALSE, _ModelMatrix);
		/*** If you want to use the trackball use this code instead
		glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, Model1Matrix * Trackball::getInstance()->getMatrix4());
		***/

		/// Assigning the 4x4 Model1Matrix to the 3x3 normalMatrix 
		/// copies just the upper 3x3 of the Model1Matrix
		Matrix3 normalMatrix = Matrix3(_ModelMatrix); /// Converts the 4x4 Model1 matrix to a 3x3
		/*** If you want to use the trackball use this code instead
		glUniformMatrix4fv(Model1MatrixID, 1, GL_FALSE, Model1Matrix * Trackball::getInstance()->getMatrix4());
		***/
		glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);

		glUniform3fv(lightPosID, 1, SceneEnvironment::getInstance()->getLight());

		for (Mesh* mesh : meshes) {
			mesh->Render();
		}


	}
	void Model1::OnDestroy() {
		if (shader) delete shader;
	}
}