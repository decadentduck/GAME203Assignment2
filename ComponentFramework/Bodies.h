#ifndef BODIES_H
#define BODIES_H



class Bodies 
{
<<<<<<< HEAD
	class Bodies
	{
		friend class BodyModifier;
	protected:
		Vec3 rotationDirection;
		float rotationAngle;

	public:
		Vec3 position, rotation;
		Model *model;
		Bodies(Vec3 pos, Vec3 rot, Model *model_);
		Bodies();
		~Bodies();
	};
}
=======
	friend class BodyModifier;
protected:
	Vec3 position;

	Vec3 rotationDirection;
	float rotationAngle;
	 

	Vec3 rotation;
	
>>>>>>> parent of 16c63cb... adding a model to the bodyclass

public:
	Bodies(Vec3 pos, Vec3 rot);
	Bodies();
	~Bodies();
};
#endif // !BODIES_H


