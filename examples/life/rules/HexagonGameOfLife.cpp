//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
#include <iostream>

void HexagonGameOfLife::Step(World& world) {
  for (int y = 0; y < world.SideSize(); y++)
  {
    for (int x = 0; x < world.SideSize(); x++)
    {
      int neighborCount = CountNeighbors(world, {x,y});
      if (world.Get({x,y}))
      {
        //std::cout << "(" << x << ", " << y << ")'s neighbor count is: " << neighborCount << std::endl;
        if (neighborCount != 2)
        {
          world.SetNext({x, y}, false);
        }
        else
        {
          world.SetNext({x,y}, true);
        }
      }
      else {
        if (neighborCount == 2)
        {
          world.SetNext({x,y}, true);
        }
      }
    }
  }
}
int HexagonGameOfLife::CountNeighbors(World& world, Point2D point) {
  int count = 0;
  int evenOrOddMod = 0;
  int xMin;
  int xMax;

  if (point.y % 2 == 1) //odd
  {
    evenOrOddMod = -1;
    xMin = 0;
    xMax = 1;
  }
  else
  {
    evenOrOddMod = 1;
    xMin = -1;
    xMax = 0;
  }
  //going through x=-1 since the only neighbor to check is (-1,0) relative to point (for odd)
  //going through x=1 since the only neighbor to check is (1,0) relative to point (for even)
  if (world.Get({point.x+evenOrOddMod, point.y}))
  {
    count++;
  }
  //checking other neighbors except (0,0) relative to point
  for (int x = xMin; x <= xMax; x++)
  {
    for (int y = -1; y <=1; y++)
    {
      if ((y != 0 || x != 0) && world.Get({point.x+x, point.y+y}))
      {
        count++;
      }
    }
  }
  return count;
}
