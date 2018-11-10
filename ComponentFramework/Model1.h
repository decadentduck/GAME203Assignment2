#ifndef Model1_H
#define Model1_H
#include <vector>
#include "MMath.h"
#include "Mesh.h"
#include "Entity.h"

namespace GAME {

	using namespace MATH;

	class Model1 : public Entity {
		friend class BodyModifier;
	protected:
		float rotation, scale;

		class Shader *shader;

		Matrix4 Model1Matrix;
		std::vector<Mesh*> meshes;

	public:
		Model1(const Vec3 _pos, const Vec3 _orientation);
		Model1(const Vec3 _pos, const Vec3 _orientation, const float rotation_, const float scale_);
		Model1(const Model1&) = delete;
		Model1(Model1&&) = delete;
		Model1& operator = (const Model1&) = delete;
		Model1& operator = (Model1&&) = delete;

		virtual ~Model1();

		void setPos(const Vec3& pos_) override;
		void setOrientation(const Vec3& orienration_) override;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Render() const;
		virtual void Update(const float deltaTime);

		virtual bool LoadMesh(const char* filename);

	protected:

		void updateModel1Matrix();
	};
} /// end of namespace

#endif