#include "Core.hpp"
#include <iostream>

int main(int ac, char **av) {
    std::vector<std::string> gFlagValues = {};
    std::vector<std::string> dFlagValues = {};

    for (int i = 1; i < ac; ++i) {
        if (std::string(av[i]) == "-g" && i + 1 < ac) {
            gFlagValues.push_back(av[i + 1]);
            ++i;
        } else if (std::string(av[i]) == "-d" && i + 1 < ac) {
            dFlagValues.push_back(av[i + 1]);
            ++i;
        }
    }

    std::cout << gFlagValues.size() << " game DLLs loaded." << std::endl;
    std::cout << dFlagValues.size() << " display DLLs loaded." << std::endl;
    ArcaTek::Core core(gFlagValues, dFlagValues);

    core.run();
    return 0;
}
