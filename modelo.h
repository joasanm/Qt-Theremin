#include <stdlib.h>

#include <glut.h>

// assimp include files. These three are usually needed.
#include <cimport.h>
#include <scene.h>
#include <postprocess.h>

class modelo{
public:
	void get_bounding_box_for_node (const struct aiNode* nd, aiVector3t<float>* min, 
		aiVector3t<float>* max, aiMatrix4x4t<float>* trafo);
	void get_bounding_box (aiVector3t<float>* min, aiVector3t<float>* max);
	void color4_to_float4(const aiColor4t<float> *c, float f[4]);
	void set_float4(float f[4], float a, float b, float c, float d);
	void apply_material(const struct aiMaterial *mtl);
	void recursive_render (const struct aiScene *sc, const struct aiNode* nd);
	int loadasset (const char* path);
	void init();
	void cmodel();
	void model();

private:
	const struct aiScene* scene;
	GLuint scene_list;
	aiVector3t<float> scene_min, scene_max, scene_center;
};
