#pragma once

class DataBase;

struct Belonging {
  int id;
  int amount;
};

class UserBelongings {
public:
  UserBelongings(TArray<Belonging> &belongings, DataBase *dataBase);
  virtual ~UserBelongings();
  void Increase(int id, int amount);
  void Decrease(int id, int amount);
  virtual void Use(int id);
  virtual void Use(const char *name);
  //get
  TArray<Belonging> GetBelonging() { return belongings_; }
  DataBase *GetDataBase() { return dataBase_; }

protected:
  void Add(int id, int amount);
  void Remove(int index);

private:
  TArray<Belonging> belongings_;
  DataBase *dataBase_;
};
