#include "road.h"

Road::Road(int y, int height)
    : y_(y), height_(height) {}

int Road::y() const { return y_; }
int Road::height() const { return height_; }
