#include "CLI.h"

void CLI::expandStorage() {
    CShape2D **temp = new CShape2D*[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = storage[i];
    }

    delete[] storage;
    size++;
    storage = temp;
}

void CLI::uiSwitch() {
    std::cout << "Run [t]ests or start [u]I? ";
    char opt = mod_getchar();

    switch (opt) {
        case 't':
            return unit_tests();
        case 'u':
            return mainMenu();
        default:
            std::cout << "\n";
            uiSwitch();
    }
}

void CLI::mainMenu() {
    clear();

    //re-render everything to reflect changes
    canvas.clear();
    for (int i = 0; i < size; i++) {
        storage[i]->render(canvas);
    }
    canvas.render(std::cout);

    std::cout << "[c]ircle - [r]ectangle - [s]cale - [m]ove - show [a]ll - [t]otal area - [e]xit\n";
    char opt = mod_getchar();
    clear();

    switch (opt) {
        case 'c':
            addShape<CCircle>();
            break;
        case 'r':
            addShape<CRectangle>();
            break;
        case 's':
            scale();
            break;
        case 'm':
            move();
            break;
        case 'a':
            list();
            break;
        case 't':
            totalArea();
            break;
        case 'e':
            return;
        default:
            return mainMenu();
    }

    mainMenu();
}

template <typename T> void CLI::addShape() {
    clear();

    T* shape = new T();
    CShape2D &ref = *shape;
    std::cin >> ref;

    expandStorage();
    storage[size - 1] = shape;
}

void CLI::scale() {
    CShape2D *ptr = grabFromIO();
    if (ptr == nullptr) return;

    std::cout << "Input scale factor: ";
    float factor;
    std::cin >> factor;

    ptr->scale(factor);
}

void CLI::move() {
    CShape2D *ptr = grabFromIO();
    if (ptr == nullptr) return;

    float x = 0;
    float y = 0;
    std::cout << "Input x component of vector: ";
    std::cin >> x;
    std::cout << "Input y component of vector: ";
    std::cin >> y;

    ptr->move({x, y});
}

void CLI::list() {
    std::cout << "List of shapes:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "  [Shape " << i << "] " << *storage[i] << "\n";
    }

    std::cout << "\nPress enter key to continue...";
    mod_flush();
}

CLI::CLI() : canvas(20, 100), size(0) {
    storage = new CShape2D*[size];
}

CLI::~CLI() {
    for (int i = 0; i < size; i++) {
        delete storage[i];
    }
    delete[] storage;
}

void CLI::start() {
    uiSwitch();
}

void CLI::unit_tests() {
    //TODO: tests
}

void CLI::totalArea() {
    std::cout << "Total area of all shapes: ";

    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += storage[i]->area();
    }

    std::cout << sum << "\n\nPress enter key to continue...";
    mod_flush();
}

CShape2D *CLI::grabFromIO() {
    std::cout << "Enter shape ID: ";
    int id;
    std::cin >> id;

    if (id < 0 || id >= size) {
        std::cout << "Invalid shape ID.\n\nPress enter key to continue...";
        mod_flush();
        mod_flush();
        return nullptr;
    } else {
        return storage[id];
    }
}

void CLI::clear() {
    std::system(CLEAR);
}

char CLI::mod_getchar() {
    char x;
    std::cin >> x;
    mod_flush();
    return x;
}

void CLI::mod_flush() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
