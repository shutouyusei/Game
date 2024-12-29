#pragma once

class StatsResource {
public:
  StatsResource(void (*deathCallback)() = nullptr) : deathCallback(deathCallback) {};
  float resource;

private:
  float MaxResource;
  void (*deathCallback)();

public:
  void IncreaseResource(float amount);
  void DecreaseResource(float amount);
};
