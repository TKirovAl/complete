#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

const int maxVertices = 1000;
const int maxTexCoords = 1000;
const int maxNormals = 1000;
const int maxFaces = 1000;

// Классы для представления вершин, текстурных координат и нормалей
class Vertex {
public:
    float x, y, z;
};

class TextureCoord {
public:
    float u, v;
};

class Normal {
public:
    float nx, ny, nz;
};

// Класс для представления грани
class Face {
public:
    int vertexIndices[4];
    int textureIndices[4];
    int normalIndices[4];
};

// Массивы для хранения вершин, текстурных координат, нормалей и граней
std::array<Vertex, maxVertices> vertices;
std::array<TextureCoord, maxTexCoords> texCoords;
std::array<Normal, maxNormals> normals;
std::array<Face, maxFaces> faces;

int vertexCount = 0;
int texCoordCount = 0;
int normalCount = 0;
int faceCount = 0;

int main() {
    // Открываем файл с данными OBJ
    std::ifstream objFile("your_file.obj");
    if (!objFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::string line;
    std::string prefix;

    // Читаем файл построчно
    while (objFile >> prefix) {
        // Если префикс "v", читаем координаты вершины
        if (prefix == "v") {
            if (vertexCount < maxVertices) {
                objFile >> vertices[vertexCount].x >> vertices[vertexCount].y >> vertices[vertexCount].z;
                std::cout << "Вершина " << vertexCount << ": x=" << vertices[vertexCount].x << " y=" << vertices[vertexCount].y << " z=" << vertices[vertexCount].z << std::endl;
                vertexCount++;
            }
        } 
        // Если префикс "vt", читаем текстурные координаты
        else if (prefix == "vt") {
            if (texCoordCount < maxTexCoords) {
                objFile >> texCoords[texCoordCount].u >> texCoords[texCoordCount].v;
                std::cout << "Текстурные координаты " << texCoordCount << ": u=" << texCoords[texCoordCount].u << " v=" << texCoords[texCoordCount].v << std::endl;
                texCoordCount++;
            }
        } 
        // Если префикс "vn", читаем нормали
        else if (prefix == "vn") {
            if (normalCount < maxNormals) {
                objFile >> normals[normalCount].nx >> normals[normalCount].ny >> normals[normalCount].nz;
                std::cout << "Нормаль " << normalCount << ": nx=" << normals[normalCount].nx << " ny=" << normals[normalCount].ny << " nz=" << normals[normalCount].nz << std::endl;
                normalCount++;
            }
        } 
        // Если префикс "f", читаем данные грани
        else if (prefix == "f") {
            if (faceCount < maxFaces) {
                for (int i = 0; i < 3; i++) {
                    objFile >> faces[faceCount].vertexIndices[i] >> faces[faceCount].textureIndices[i] >> faces[faceCount].normalIndices[i];
                }
                std::cout << "Грань " << faceCount << ": ";
                for (int i = 0; i < 3; i++) {
                    std::cout << "Вершина: " << faces[faceCount].vertexIndices[i] << " Текстура: " << faces[faceCount].textureIndices[i] << " Нормаль: " << faces[faceCount].normalIndices[i] << " ";
                }
                std::cout << std::endl;
                faceCount++;
            }
        }

        std::getline(objFile, line); // Считываем остаток строки
    }

    return 0;
}
