#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce = Vector2f::zero();
  Vector2f massCenter = Vector2f::zero();

  // todo: add your code here to make a force towards the center of mass
  //massCenter += boid->getPosition();
  // hint: iterate over the neighborhood
  if (!neighborhood.empty())
  {
    for (const auto& theBoid:neighborhood)
    {
      massCenter += theBoid->getPosition();
    }
    // find center of mass
    massCenter /= neighborhood.size();
    cohesionForce = (massCenter - boid->getPosition());
  }

  return cohesionForce;
}