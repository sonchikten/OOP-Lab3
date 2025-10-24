#include "../include/figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print_vertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read_from_stream(is);
    return is;
}

Figure::operator double() const {
    return this->area();
}