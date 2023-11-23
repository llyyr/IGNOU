#include <iostream>
#include <string>

using namespace std;

class Rectangle {
private:
    double length;
    double width;
    double area;
    string color;

public:
    void set_length(double l) {
        length = l;
    }

    void set_width(double w) {
        width = w;
    }

    void set_color(const string &c) {
        color = c;
    }

    void find_area() {
        area = length * width;
    }

    bool compare_rectangles(const Rectangle &other) {
        return (area == other.area) && (color == other.color);
    }
};

int main() {
    Rectangle rect1, rect2;

    rect1.set_length(5.0);
    rect1.set_width(4.0);
    rect1.set_color("Blue");
    rect1.find_area();

    rect2.set_length(5.0);
    rect2.set_width(4.0);
    rect2.set_color("Blue");
    rect2.find_area();

    if (rect1.compare_rectangles(rect2)) {
        cout << "Matching Rectangles" << endl;
    } else {
        cout << "Non-matching Rectangles" << endl;
    }

    return 0;
}
