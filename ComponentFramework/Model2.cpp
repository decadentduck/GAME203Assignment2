#include "Model2.h"
#include "Shader.h"
#include "ObjLoader.h"
#include "Camera.h"
#include "SceneEnvironment.h"
#include "Trackball.h"

namespace GAME {

	Model2::Model2(const Vec3 pos_, const Vec3 orientation_) {
		pos = pos_;
		orientation = orientation_;
		rotation = 0.0f;
		scale = 1.0f;
		shader = nullptr;
	}

	Model2::Model2(const Vec3 pos_, const Vec3 orientation_, const float rotation_, const float scale_) {
		pos = pos_;
		orientation = orientation_;
		rotation = rotation_;
		scale = scale_;
		shader = nullptr;
	}

	Model2::~Model2() {
		OnDestroy();
	}

	void Model2::setPos(const Vec3& pos_) {
		Entity::setPos(pos_);
		updateModel2Matrix();
	}

	void Model2::setOrientation(const Vec3& orientation_) {
		Entity::setOrientation(orientation_);
		updateModel2Matrix();
	}
	void Model2::setScale(const float& scale_)
	{
		scale = scale_;
	}

	void Model2::updateModel2Matrix() {
		//Model2Matrix = MMath::translate(pos);
		change = true;
		/// This transform is based on Euler angles - let's do it later
		Model2Matrix = MMath::translate(pos) * MMath::rotate(orientation.z, Vec3(0.0f, 0.0f, 1.0f)) * 
			MMath::rotate(orientation.x, Vec3(1.0f, 0.0f, 0.0f)) * MMath::rotate(orientation.y, Vec3(0.0f, 1.0f, 0.0f)) * MMath::scale(scale,scale,scale);
	}

	bool Model2::OnCreate() {
		shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");
		change = false;
		return true;
	}



	bool Model2::LoadMesh(const char* filename) {
		if (ObjLoader::loadOBJ(filename) == false) {
			return false;
		}
		/// Get the data out of the ObjLoader and into our own mesh
		meshes.push_back(new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords));
		return true;
	}


	void Model2::Update(const float deltaTime) {
		//Model2::updateModel2Matrix();
		/// See Entity.h
		///Rotate(Vec3(0.0f, 50.0f * deltaTime, 0.0f));
	}

	void Model2::Render() const {

		GLint projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
		GLint viewMatrixID = glGetUniformLocation(shader->getProgram(), "viewMatrix");
		GLint modelMatrixID = glGetUniformLocation(shader->getProgram(), "modelMatrix");
		GLint normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
		GLint lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");

		glUseProgram(shader->getProgram());

		glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, Camera::currentCamera->getProjectionMatrix());
		glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, Camera::currentCamera->getViewMatrix());
		 //Use _modelMatrix if there has been no changes
		Matrix3 normalMatrix;
		if (!change)
		{
			Matrix4 _modelMatrix = MMath::rotate(rotation, 0.0f, 1.0f, 0.0f) * MMath::scale(scale, scale, scale) * Model2Matrix;
			glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, _modelMatrix);
			normalMatrix = Matrix3(_modelMatrix);
		}
		
		else
		{
			glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, Model2Matrix);
			normalMatrix = Matrix3(Model2Matrix);
		}
			 
		/*** If you want to use the trackball use this code instead
		glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, modelMatrix * Trackball::getInstance()->getMatrix4());
		***/

		/// Assigning the 4x4 modelMatrix to the 3x3 normalMatrix 
		/// copies just the upper 3x3 of the modelMatrix
	 /// Converts the 4x4 model matrix to a 3x3
													  /*** If you want to use the trackball use this code instead
													  glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, modelMatrix * Trackball::getInstance()->getMatrix4());
													  ***/
		glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);

		glUniform3fv(lightPosID, 1, SceneEnvironment::getInstance()->getLight());

		for (Mesh* mesh : meshes) {
			mesh->Render();
		}


	}
	void Model2::OnDestroy() {
		if (shader) delete shader;
	}
}