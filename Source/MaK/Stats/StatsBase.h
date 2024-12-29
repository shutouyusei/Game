#pragma once

class StatsResource;

class StatsBase {
public:
  StatsBase(void (*deathCallback)() = nullptr);
  virtual ~StatsBase();

public:
private:
  // HP, MP
  StatsResource *HP_;
  StatsResource *MP_;
};
