#pragma once

struct BelongingAmount {
  int id;
  int amount;
};

class UserBelongings {
public:
  UserBelongings(TArray<BelongingAmount> &belongings);
  virtual ~UserBelongings();
  void Increase(int id, int amount);
  void Decrease(int id, int amount);
  // get
  TArray<BelongingAmount> GetBelonging() { return belongingAmount_; }

protected:
  void Add(int id, int amount);
  void Remove(int index);

private:
  TArray<BelongingAmount> belongingAmount_;
};
