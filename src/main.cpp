#include <cstring>
#include <iostream>
#include <unistd.h>

#define PRINT_MESSAGE // a simple macro definition
#define AREA(l, b) (l * b) // macro with parameter

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        std::cout<< "command line parameter[" << i << "]=" << argv[i] << std::endl;
    }
    std::cout << std::endl;

    const char optstring[] = "hc:v:";
    int option = 0;

    while((option = getopt(argc, argv, optstring)) != -1) {
        switch (option) {
            case 'h':
                    std::cout << "\nUsage: " << argv[0]
                              << " -c <path_to_config_file>"
                              << " -v <loglevel>"
                              << std::endl;
                    return 0;
            case 'c':
                    std::cout<< "Config path is " << optarg << std::endl;
                    break;
            case 'v':
                    if (!strcmp(optarg, "debug")) {
                        std::cout << "Setting loglevel to debug" << std::endl;
                    } else if (!strcmp(optarg, "info")) {
                        std::cout << "Setting loglevel to info" << std::endl;
                    } else if (!strcmp(optarg, "warning")) {
                        std::cout << "Setting loglevel to warning" << std::endl;
                    } else if (!strcmp(optarg, "error")) {
                        std::cout << "Setting loglevel to error" << std::endl;
                    } else {
                        std::cout << "Unknown loglevel: " << optarg << std::endl;
                    }
                    break;
        }
    }
    std::cout << std::endl;

    const int l1 = 10;
    const int l2 = 5;
    const int area = AREA(l1, l2);

    std::cout << "Area of rectangle is: " << area << std::endl << std::endl;

#ifdef PRINT_MESSAGE
    std::cout << "PRINT_MESSAGE is defined" << std::endl;
#else
    std::cout << "PRINT_MESSAGE is undefined" << std::endl;
#endif

    return 0;
}
