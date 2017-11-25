#version 400

in vec2 VertexTexCoord;
in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;

out vec2 InterpolatedTexCoord;
out vec3 InterpolatedColor;
out vec3 interpolatedVerNormal;
out vec3 posPix;
out vec4 PixelPositionLightSpace;

uniform mat4 mvpMatrix;
uniform mat4 ModelMatrix;
uniform mat4 LightVPMatrix;

void main(){

	mat3 NormalMatrix = transpose(inverse(mat3(ModelMatrix)));
	InterpolatedColor = VertexColor;
	posPix = vec3(ModelMatrix * vec4(VertexPosition, 1.0f));
	interpolatedVerNormal =  NormalMatrix * VertexNormal;
	InterpolatedTexCoord = VertexTexCoord;
	PixelPositionLightSpace=LightVPMatrix*vec4(posPix, 1.0);
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}