#pragma once
#include "../UseHandler.h"

class LuaHandler;

class FItemUseHandler : public UseHandler {
public:
  virtual ~FItemUseHandler() = default;
  virtual void Use(const int id) override;

private:
  std::string SetItemPath(FString itemPath);
};

class FItemUseHandlerFactory : public UseHandlerFactory {
public:
  virtual ~FItemUseHandlerFactory() = default;
  virtual UseHandler *Create() override;
};
