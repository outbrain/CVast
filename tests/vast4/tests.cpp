
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include "tests.h"
#include "values.h"
#include "requirements.h"

Tests::Tests (const string& dir) : resourcesDir(dir) {
    this->startChrono();

    int i = 1;
    this->resourcesFiles = this->readDir(this->resourcesDir);

    for (auto& f : this->resourcesFiles) {
        string content = this->readFile(this->resourcesDir + "/" + f);

        printf("\033[1;34mVALUES TESTS WITH FILE %s\033[0m\n", f.c_str());
        Values values(content, i);

        printf("\033[1;34mREQUIREMENTS TESTS WITH FILE %s\033[0m\n", f.c_str());
        Requirements requirements(content, i);

        i++;
    }

    this->endChrono();
    this->printElapsedTime();
}

vector<string> Tests::readDir (const string& path) {
    DIR *dir;
    struct dirent *ent;
    vector<string> files;

    if ((dir = opendir (this->resourcesDir.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            string fn = ent->d_name;
            if (fn.substr(fn.find_last_of('.') + 1) == "xml")
                files.emplace_back(ent->d_name);
        }

        closedir (dir);
    } else {
        throw runtime_error("Cannot open directory " + path);
    }

    return files;
}

string Tests::readFile (const string& path) {
    string line;
    string content;
    ifstream f(path);

    if (f.is_open()) {

        while (getline(f, line))
            content += line;

        f.close();
    } else {
        throw runtime_error("Cannot open file " + path);
    }

    return content;
}

void Tests::startChrono () {
    this->startTime = chrono::system_clock::now();
}

void Tests::endChrono () {
    this->endTime = chrono::system_clock::now();
}

void Tests::printElapsedTime () {
    chrono::duration<double> elapsed = this->endTime - this->startTime;
    printf("elapsed: %f sec.", elapsed.count());
}
