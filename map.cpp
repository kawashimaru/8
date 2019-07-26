#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

template <class K, class V>
class Map
{
private:
	K* arr1;
  V* arr2;
  int size;
public:
  Map();
  Map(const K* A, const V* B, const int& size);
  Map(const Map<K,V>& m);
  Map<K, V>& operator = (const Map<K, V>& m);
  ~Map();
	int getSize() const;
  V& operator[] (const K& key) const;
  K& operator[] (const V& key) const;
  template <class K, class V>
  friend ostream& operator << (ostream& out, const Map<K, V>& m);
}

template <class K, class V>
Map<K, V>::Map()
{
  this->size = 0;
}

template <class K, class V>
Map<K, V>::Map(const K* A, const V* B, const int& size)
{
  this->size = size;
  if (this->size > 0)
  {
    this->arr1 = new K[this->size];
		this->arr2 = new V[this->size];
		for (int i = 0; i < size; ++i)
		{
			this->arr1[i] = A[i];
			this->arr2[i] = B[i];
		}
  }
}

template <class K, class V>
Map<K, V>::Map(const Map<K, V>& m)
{
	this->size = m.getSize();
	if (this->size > 0)
	{
		this->arr1 = new K[this->size];
		this->arr2 = new V[this->size];
		for (int i = 0; i < this->size, ++i)
		{
			this->arr1[i] = m.arr1[i];
			this->arr2[i] = m.arr2[i];
		}
	}
}

template <class K, class V>
int Map<K, V>::getSize() const
{
	return this->size;
}

template <class K, class V>
Map<K, V>& Map<K, V>::operator = (const Map<K, V>& m)
{
	if (this == &m)
		return *this;
	this->~Map();
	this->size = m.getSize();
	if (this->size > 0)
	{
		this->arr1 = new K[this->size];
		this->arr2 = new V[this->size];
		for (int i = 0; i < this->size; ++i)
		{
			this->arr1[i] = m.arr1[i];
			this->arr2[i] = m.arr2[i];
		}
	}
	return *this;
}

template <class K, class V>
Map<K, V>::~Map()
{
	if (this->size > 0)
	{
		delete[] this->arr1;
		delete[] this->arr2;
		this->size = 0;
	}
}

template <class K, class V>
V& Map<K, V>::operator[](const K& key) const
{
	int i = 0;
	for (i; i < this->size; ++i)
		return (arr1[i] == key) ? arr2[i] : continue;
	cout << "ERROR! Index out of bounds." << endl;
	system("exit");
	return arr2[i];
}

template<class K, class V>
K& Map<K, V>::operator[](const V& value) const
{
	int i = 0;
	for (i; i < this->size; ++i)
		return (arr2[i] == value) ? arr1[i] : continue;
	cout << "ERROR! Index out of bounds." << endl;
	system("exit");
	return arr1[i];
}

template <class K, class V>
ostream& operator << (ostream& outputStream, const Map<K, V>& m)
{
	for (int i = 0; i < m.getSize(); ++i)
		outputStream << m.arr1[i] << \t << m.arr2[i] << endl;
	outputStream << endl;
	return outputStream;
}

int main()
{
  srand(5);
  int citiesSize = 20;
  string citiesArray[] = {"Victoria", "Nanaimo", "Calgary", "Edmonton", "Kamloops", "Prince George", "Kelowna",
                          "Seattle", "Belingham", "Whislet", "Squamish", "Abbotsford", "Penticton",
                          "Fort McMurray", "Prairie", "Yellow Knife", "Horsehoe Bay", "Langley", "White Rock"};
  Map<string, double> m1;
  cout << "The initial map m1 is " << m1 << endl;
  for (int i = 0; i < citiesSize; ++i)
  {
    string city = citiesArray[i];
    int distance = rand() % 40 + 20;
    m1.append(city, distance);
  }
  cout << "The map created m1 is now... " << m1 << endl;
  cout << "Nanaimo is " << m1["Nanaimo"] << "km away from Vancouver." << endl;
  cout << "A city that is 50km away from Vancouver is " << m1[50] << endl;
  Map<string, double> m2 = m1;
  m1.~Map();
  cout << "After deleting, the map m1 is now " << m1 << endl;
  cout << "The map m2 that was copied from m1 still is..." << m2 << endl;
  m1 = m2;
  cout << "After assigning m2 to m1, the m1 is now " << m1 << endl;
  return 0;
}
