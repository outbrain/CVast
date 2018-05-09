
#ifndef CVAST_VALIDATE_H
#define CVAST_VALIDATE_H

#include <string>
#include <vector>

class Validate {
public:
    template <class T, class V>
    void equal (const T& tagValue, const V& value, const std::string& path = "") {
        const std::string p = (path.empty()) ? this->path : path;

        if (tagValue != value)
            this->errors.push_back(this->invalid(p));
    }

    template <class T, class V>
    void different (const T& tagValue, const V& value, const std::string& path = "") {
        const std::string p = (path.empty()) ? this->path : path;

        if (tagValue == value)
            this->errors.push_back(this->valid(p));
    }

    std::string invalid (const std::string& path) {
        std::string err = "Uneven values at ";
        err += path;
        err += "\n";

        return err;
    }

    std::string valid (const std::string& path) {
        std::string err = "Same values at ";
        err += path;
        err += "\n";

        return err;
    }

    void printErrors () {
        if (!this->errors.empty()) {
            for (auto& e : this->errors) {
                printf("\033[1;31m%s\033[0m\n", e.c_str());
            }
        } else {
            printf("\033[1;32mAll tests passed\033[0m\n\n");
        }
    }

protected:
    std::string path;
    std::vector<std::string> errors;
};


#endif //CVAST_VALIDATE_H
