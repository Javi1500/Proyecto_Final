#version 400

in vec2 InterpolatedTexCoord;
in vec3 InterpolatedColor;
in vec3 posPix;
in vec3 interpolatedVerNormal;
in vec4 PixelPositionLightSpace;

out vec4 FragColor;

uniform sampler2D DiffuseTexture;
uniform sampler2D ShadowMap;
uniform float positionx;
uniform float positiony;
uniform float positionz;
uniform float x;
uniform float y;
uniform float z;

float IsPixelOccluded(vec4 fragPosLightSpace){

	vec3 projCoords=(fragPosLightSpace.xyz/fragPosLightSpace.w);
	projCoords = projCoords * 0.5f + 0.5f;
	float closestDepth=texture2D(ShadowMap, projCoords.xy).r;
	float currentDepth=projCoords.z;
	float shadow=currentDepth-.009f > closestDepth ? 1.0f : 0.0f;
	return shadow;
}

void main(){

	vec3 lightColor =vec3(1.0f,1.0f,.7f);
	vec3 ambient = 0.1f*lightColor;
	vec3 luz = vec3(x,y,z);
	vec3 L =  normalize(luz-posPix);
	vec3 camara = vec3(positionx,positiony,positionz);
	vec3 diffuse = lightColor* clamp(dot(interpolatedVerNormal,L),0,40);
	vec3 V =  normalize(camara-posPix);
	vec3 R = reflect(-L,interpolatedVerNormal);
	vec3 specular = lightColor*.5f*pow(clamp(dot(V,R),0,11), 1);
	float shadow=IsPixelOccluded(PixelPositionLightSpace);
	vec3 phong = (specular+diffuse)*((1.0f-shadow)+ambient);
	FragColor = texture2D(DiffuseTexture, InterpolatedTexCoord)*vec4(phong, 1)* 1;	
}