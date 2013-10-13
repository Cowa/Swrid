#ifndef GRIDMODE_H
#define GRIDMODE_H

#include <vector>
#include <array>

class Grid;
class Element;
class GridMode
{
    public:
        virtual ~GridMode() {}
        virtual bool purge(Grid *grid) = 0;
    protected:
    private:
};

#endif // GRIDMODE_H
