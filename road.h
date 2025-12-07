#ifndef ROAD_H
#define ROAD_H

class Road {
private:
    int y_;         // posição vertical da rua
    int height_;
public:
    Road(int y = 100, int height = 100);

    int y() const;
    int height() const;
};

#endif
