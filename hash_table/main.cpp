#include <iostream>
#include "hash_map.cpp"

using namespace std;

int main()
{
  HashMap<int, int> *h = new HashMap<int, int>;
  h->insertNode(1,1);
  h->insertNode(2,2);
  h->insertNode(3,3);
  h->display();
  cout << h->sizeofMap() <<endl;
  cout << h->deleteNode(2) << endl;
  cout << h->sizeofMap() <<endl;
  cout << h->isEmpty() << endl;
  cout << h->get(2);
  cout << endl;
  return 0;
}