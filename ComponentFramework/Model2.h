#ifndef Model2_H
#define Model2_H
#include <vector>
#include "MMath.h"
#include "Mesh.h"
#include "Entity.h"

namespace GAME {

	using namespace MATH;

	class Model2 : public Entity {
		friend class BodyModifier;
	protected:
		float rotation, scale;

		class Shader *shader;

		Matrix4 Model2Matrix;
		std::vector<Mesh*> meshes;

	public:
		Model2(const Vec3 _pos, const Vec3 _orientation);
		Model2(const Vec3 _pos, const Vec3 _orientation, const float rotation_, const float scale_);
		Model2(const Model2&) = delete;
		Model2(Model2&&) = delete;
		Model2& operator = (const Model2&) = delete;
		Model2& operator = (Model2&&) = delete;

		virtual ~Model2();

		void setPos(const Vec3& pos_) override;
		void setOrientation(const Vec3& orienration_) override;
		void setScale(const float& scale_);

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Render() const;
		virtual void Update(const float deltaTime);

		virtual bool LoadMesh(const char* filename);

	protected:

		void updateModel2Matrix();
	};
} /// end of namespace

#endif