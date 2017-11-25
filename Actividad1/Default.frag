#version 400
out vec4 FragColor;

void main(){
	FragColor = vec4(gl_FragCoord.z, gl_FragCoord.z, gl_FragCoord.z, 3.0f);
}