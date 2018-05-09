
#ifndef CVAST_TESTS_H
#define CVAST_TESTS_H

using namespace std;

class Tests {
private:
    const string& resourcesDir;
    vector<string> resourcesFiles;
    chrono::system_clock::time_point startTime;
    chrono::system_clock::time_point endTime;

public:
    explicit Tests (const string& dir);
    vector<string> readDir (const string& path);
    string readFile (const string& path);
    void startChrono ();
    void endChrono ();
    void printElapsedTime ();
};

#endif //CVAST_TESTS_H
