#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
  for (int y = 0; y < world.SideSize(); y++)
  {
    for (int x = 0; x < world.SideSize(); x++)
    {
      int neighborCount = CountNeighbors(world, {x,y});
      if (world.Get({x,y}))
      {
        if (neighborCount < 2 || neighborCount > 3)
        {
          world.SetNext({x, y}, false);
        }
        else
        {
          world.SetNext({x,y}, true);
        }
      }
      else {
        if (neighborCount == 3)
        {
          world.SetNext({x,y}, true);
        }
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  int count = 0;
  for (int y = -1; y <= 1; y++)
  {
    for (int x = -1; x <= 1; x++)
    {
      if ((y != 0 || x != 0) && world.Get({point.x+x, point.y+y}))
      {
        count++;
      }
    }
  }
  return count;
}
