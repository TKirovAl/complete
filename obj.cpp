#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <string>

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
    if (!objFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::string line;

    // Читаем файл построчно
    while (std::getline(objFile, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        // Если префикс "v", читаем координаты вершины
        if (prefix == "v") {
            if (vertexCount < maxVertices) {
                float x, y, z;
                if ((iss >> x >> y >> z)) {
                    vertices[vertexCount].x = x;
                    vertices[vertexCount].y = y;
                    vertices[vertexCount].z = z;
                    std::cout << "Вершина " << vertexCount << ": x=" << x << " y=" << y << " z=" << z << std::endl;
                    vertexCount++;
                }
            }
        } 
        // Если префикс "vt", читаем текстурные координаты
        else if (prefix == "vt") {
            if (texCoordCount < maxTexCoords) {
                float u, v;
                if ((iss >> u >> v)) {
                    texCoords[texCoordCount].u = u;
                    texCoords[texCoordCount].v = v;
                    std::cout << "Текстурные координаты " << texCoordCount << ": u=" << u << " v=" << v << std::endl;
                    texCoordCount++;
                }
            }
        } 
        // Если префикс "vn", читаем нормали
        else if (prefix == "vn") {
            if (normalCount < maxNormals) {
                float nx, ny, nz;
                if ((iss >> nx >> ny >> nz)) {
                    normals[normalCount].nx = nx;
                    normals[normalCount].ny = ny;
                    normals[normalCount].nz = nz;
                    std::cout << "Нормаль " << normalCount << ": nx=" << nx << " ny=" << ny << " nz=" << nz << std::endl;
                    normalCount++;
                }
            }
        } 
        // Если префикс "f", читаем данные грани
        else if (prefix == "f") {
            if (faceCount < maxFaces) {
                int vIndex, tIndex, nIndex;
                for (int i = 0; i < 3; i++) {
                    if ((iss >> vIndex >> tIndex >> nIndex)) {
                        faces[faceCount].vertexIndices[i] = vIndex;
                        faces[faceCount].textureIndices[i] = tIndex;
                        faces[faceCount].normalIndices[i] = nIndex;
                    }
                }
                std::cout << "Грань " << faceCount << ": ";
                for (int i = 0; i < 3; i++) {
                    std::cout << "Вершина: " << faces[faceCount].vertexIndices[i] << " Текстура: " << faces[faceCount].textureIndices[i] << " Нормаль: " << faces[faceCount].normalIndices[i] << " ";
                }
                std::cout << std::endl;
                faceCount++;
            }
        }
    }

    return 0;
}
