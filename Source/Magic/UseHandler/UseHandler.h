#pragma once

class UseHandler {
public:
  virtual ~UseHandler() = default;
  virtual void Use(const int id) = 0;
};

class UseHandlerFactory {
public:
  virtual ~UseHandlerFactory() = default;
  virtual UseHandler *Create() = 0;
};
