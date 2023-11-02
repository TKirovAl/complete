#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <cstring>

using namespace std;

class versh {
public:
    double x;
    double y;
    double z;

    versh() {

    }
    versh(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

class norm {
public:
    double x;
    double y;
    double z;

    norm() {

    }
    norm(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

class tcor {
public:
    double x;
    double y;

    tcor() {

    }
    tcor(double X, double Y) {
        x = X;
        y = Y;
    }
};

class plosk {
public:
    vector<int> x;
    vector<int> y;
    vector<int> z;
    vector<int> n;

    plosk() {

    }
};



int main() {
    vector<versh> vershs;
    vector<norm> norms;
    vector<tcor> tcors;
    vector<plosk> plosks;

    int a, b, c;

    char input[256] = "/home/avairon/CodeCPP/Grani/cube.obj";
    //cout << "insert name of file(with extension)" << "\n";
    //cin >> input;

    FILE* db = fopen(input, "r");

    char buffer[256];
    char *buff2[256];

    fseek(db, 0, SEEK_SET);

    while (fgets(buffer, sizeof(buffer), db) != NULL) {
    //cout << buffer << "\n";

    if (buffer[0] == 'v') {
        if (buffer[1] == ' ') {
            versh objV = *new versh();
            sscanf(buffer, "v %lf %lf %lf", &objV.x, &objV.y, &objV.z);
            vershs.push_back(objV);
            cout << "add objV\n";
        } 
        else if (buffer[1] == 't') {
            tcor objVT = *new tcor();
            sscanf(buffer, "vt %lf %lf", &objVT.x, &objVT.y);
            tcors.push_back(objVT);
            cout << "add objVT\n";
        } 
        else if (buffer[1] == 'n') {
            norm objVN = *new norm();
            sscanf(buffer, "vn %lf %lf %lf", &objVN.x, &objVN.y, &objVN.z);
            norms.push_back(objVN);
            cout << "add objVN\n";
        }
    } 
    else if (buffer[0] == 'f') {
        plosk objF = *new plosk();

        char* token = strtok(buffer, " ");
        while (token != NULL) {
            sscanf(token, "%d/%d/%d", &a, &b, &c);
            objF.x.push_back(a);
            objF.y.push_back(b);
            objF.z.push_back(c);

            token = strtok(NULL, " ");
        }

        plosks.push_back(objF);
        cout << "add objF\n";
    }
    }   
    cout << "cout of vershs: " << vershs.size() << "\n";
    cout << "cout of normals: " << norms.size() << "\n";
    cout << "cout of textcord: " << tcors.size() << "\n";
    cout << "cout of plosks: " << plosks.size() << "\n";

}
