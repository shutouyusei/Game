#pragma once

struct FFetchedData;
class UDataTable;

class DataBase {
public:
  DataBase(UDataTable *table) : table_(table) {}
  FFetchedData *FetchData(const int id);

private:
  UDataTable *table_;
};
