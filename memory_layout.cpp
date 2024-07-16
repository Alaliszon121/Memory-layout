#include <iostream>
#include <utility>

/*
class String {
public:
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        std::cout << "Constructor: " << data << "\n";
    }

    ~String() {
        delete[] data;
        std::cout << "Destructor\n";
    }

    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor: " << data << "\n";
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment: " << data << "\n";
        }
        return *this;
    }

private:
    char* data;
    size_t size;
};
*/
class Object {
public:
    void equals()
    {
        std::cout << "Object enter" << "\n";
        std::cout << "Object exit" << "\n";
    };

    int m_data = 0;
};

class Rectangle : public Object
{
public:
    // virtual void equals() override
    // {
    //     std::cout << "Rectangle enter" << "\n";
    //     Object::equals();
    //     std::cout << "Rectangle exit" << "\n";
    // }

    int m_dataRect = 0;
};

class Image : public Object {
public:
    // virtual void equals() override
    // {
    //     std::cout << "Image enter" << "\n";
    //     Object::equals();
    //     std::cout << "Image exit" << "\n";
    // }

    int m_dataImage = 0;
};

class Button : public Rectangle, public Image {
public:
    // virtual void equals() override
    // {
    //     std::cout << "Button enter" << "\n";
    //     Rectangle::equals();
    //     Image::equals();
    //     std::cout << "Button exit" << "\n";
    // }

    int m_dataButton = 0;
};

/*
          Object
          /    \
    Rectangle  Image
          \    /
          Button
*/

constexpr size_t size_Object = sizeof(Object);
constexpr size_t size_Rectangle = sizeof(Rectangle);
constexpr size_t size_Image = sizeof(Image);
constexpr size_t size_Button = sizeof(Button);

/*
Object memory layout (16 B):
    vtable pointer - 8 B   -> [0]=Object::equals
    m_data - 4 B
    padding - 4 B

Rectangle memory layout (24 B):
    vtable pointer - 8 B   -> [0]=Rectangle::equals
    m_data - 4 B
    padding - 4 B
    m_dataRect - 4 B
    padding - 4 B

Image memory layout (24 B):
    vtable pointer - 8 B   -> [0]=Image::equals
    m_data - 4 B
    padding - 4 B
    m_dataImage - 4 B
    padding - 4 B

Button memory layout (56 B):
    vtable pointer - 8 B   -> [0]=Image::equals
    m_data - 4 B
    padding - 4 B
    m_dataRectangle - 4 B
    padding - 4 B
    vtable pointer - 8 B   -> [0]=Rectangle::equals
    m_data - 4 B
    padding - 4 B
    m_dataImage - 4 B
    padding - 4 B
    m_dataButton - 4b
    padding - 4 B

*/

int main() {
    //String source("Hello, World!");
    //String destination = std::move(source);

    Button b;

    return 0;
}
