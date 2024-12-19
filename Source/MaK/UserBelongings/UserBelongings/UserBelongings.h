#pragma once

class DataBase;

struct BelongingAmount {
  int id;
  int amount;
};

class UserBelongings {
public:
  UserBelongings(TArray<BelongingAmount> &belongings, DataBase *dataBase);
  virtual ~UserBelongings();
  void Increase(int id, int amount);
  void Decrease(int id, int amount);
  virtual void Use(int id);
  virtual void Use(const char *name);
  // get
  TArray<BelongingAmount> GetBelonging() { return belongingAmount_; }
  DataBase *GetDataBase() { return dataBase_; }

protected:
  void Add(int id, int amount);
  void Remove(int index);

private:
  TArray<BelongingAmount> belongingAmount_;
  DataBase *dataBase_;
};
