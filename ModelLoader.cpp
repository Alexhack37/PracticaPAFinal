#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& pathobj) {
	
	try {
		ifstream objFile(pathobj);
		
		if (objFile.is_open()) {
			
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				
				if (line[0] == 'v' && line[1] == 'n') {
					
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normales.push_back(normal);
					
				}
				else if (line[0] == 'v') {
					
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertices.push_back(vertex);
					
				}
				else if (line[0] == 'f') {
					Triangle triangle = this->parseObjTriangle(line);
					
					this->modelo.AddTriangle(this->Center(triangle));
				}
			}
			objFile.close();
		}
		else {
			cout << "ERrror abrir archivo" << pathobj << endl;
		}
	}
	catch (exception& ex) {
		cout << "Excepcion en el archivo" << pathobj << endl;
		cout << ex.what() << endl;
	}
};

Vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	
	string typeOfPoint;
	float xCoodinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoodinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoodinate, yCoordinate, zCoordinate);
	return vectorPoint.Product(this->GetScala());
	//return vectorPoint * this->GetScala();
}

Triangle ModelLoader::parseObjTriangle(const string& line) {
	
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;


	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;



	Vector3D vertex0 = this->vertices[static_cast<long long>(idxVertex0) - 1];
	Vector3D vertex1 = this->vertices[static_cast<long long>(idxVertex1) - 1];
	Vector3D vertex2 = this->vertices[static_cast<long long>(idxVertex2) - 1];

	Vector3D normal = this->normales[static_cast<long long>(idxNormal0) - 1];


	/*Vector3D normal1 = this->normales[idxNormal1 - 1];
	Vector3D normal2 = this->normales[idxNormal2 - 1];*/
	

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);
	

	return parsedTriangle;

}

void ModelLoader::calcBoundaries(Vector3D vectorPoint){

	this->xMax = fmax(this->xMax, vectorPoint.getCoordinateX());
	this->yMax = fmax(this->yMax, vectorPoint.getCoordinateY());
	this->zMax = fmax(this->zMax, vectorPoint.getCoordinateZ());

	this->xMin = fmin(this->xMin, vectorPoint.getCoordinateX());
	this->yMin = fmin(this->yMin, vectorPoint.getCoordinateY());
	this->zMin = fmin(this->zMin, vectorPoint.getCoordinateZ());
}

Triangle ModelLoader::Center(Triangle triangle) {

	Vector3D modelCenter(this->xMin + this->getWidth() / 2.0f,
		this->yMin + this->getHeight() / 2.0f,

		this->zMin + this->getLength() / 2.0f);
	Triangle centeredTriangle(
		triangle.GetVertice1().Sub(modelCenter),
		triangle.GetVertice2().Sub(modelCenter),

		//triangle.GetVertice1() - modelCenter,
		//triangle.GetVertice2() - modelCenter,

		triangle.GetVertice3().Sub(modelCenter),
		//triangle.GetVertice3() - modelCenter,
		triangle.GetNormal1(),
		triangle.GetNormal2(),
		triangle.GetNormal3());

	return centeredTriangle;
}

void ModelLoader::Clear() {
	vertices.clear();
	normales.clear();
	modelo.Clear();
}

float ModelLoader::getWidth(){
	return xMax - xMin;
}
float ModelLoader::getHeight(){
	return yMax - yMin;
}
float ModelLoader::getLength(){
	return zMax - zMin;
}
