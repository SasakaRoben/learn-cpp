#include <iostream>

class Point {
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0):
        m_x {x}, m_y {y}, m_z {z}
    {}

    // Convert a Point to its negative equivalent
    Point operator- () const;

    // Return true if the point is set at the origin
    bool operator! () const;

    Point operator+ () const;

    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
    double get_z() const { return m_z; }
};

Point Point::operator- () const {
    return { -m_x, -m_y, -m_z };
}

bool Point::operator! () const {
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+ () const {
    return { m_x, m_y, m_z };
}

int main() {
    Point point {};

    if (!point) {
        std::cout << "Point is set at the origin.\n";
    }
    else {
        std::cout << "Point is not set at the origin.\n";
    }

    return 0;
}
