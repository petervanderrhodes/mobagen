#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();

  float desiredDistance = desiredMinimalDistance;

  // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
  if (!neighborhood.empty()) {
      Vector2f position = boid->transform.position;
      int countCloseFlockmates = 0;
      // todo: find and apply force only on the closest mates
      for (const auto& neighborBoid: neighborhood)
      {
        Vector2f diffVector = boid->getPosition() - neighborBoid->getPosition();
        float distance = diffVector.getMagnitude();
        if (distance < desiredDistance)
        {
          countCloseFlockmates++;
          Vector2f hat = diffVector.normalized();
          Vector2f force = hat/distance;
          separatingForce += force;
        }
      }
  }

  separatingForce = Vector2f::normalized(separatingForce);

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
