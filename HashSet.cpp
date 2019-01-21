#include <vector>
#include <iostream>

template <class T>

class MyHashSet {
private:
	std::vector< std::vector<T> > buckets;
	int curr_vec_size;

public:
	MyHashSet() {
		curr_vec_size = 0;
	}

	void add(T key) {
		int bucket = (int)(key % 1000);

		if (bucket >= curr_vec_size) {
			// expand the 2D vector by pushing empty vectors into it
			//std::cout << "expanding vector on key/bucket: " << key << "/" << bucket << std::endl;

			for (int i = curr_vec_size; i < curr_vec_size + 10; ++i)
			{
				std::vector<T> tmp;
				buckets.push_back(tmp);
			}
			std::cout << "putting " << key << " into " << "bucket " << bucket << std::endl;
			curr_vec_size = buckets.size();

			buckets[bucket].push_back(key);
		}
		else
		{
			std::cout << "putting " << key << " into " << "bucket " << bucket << std::endl;
			buckets[bucket].push_back(key);
		}
	}

	void remove(T key) {
		int bucket = (int)(key % 1000);
		//[bucket].push_back(key);

		for (typename std::vector<T>::iterator it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it)
		{
			int val = *it;
			if (*it == key)
			{
				std::cout << "erasing " << key << " from " << "bucket " << bucket << std::endl;
				buckets[bucket].erase(it);
				break;
			}
		}
	}

	bool contains(T key) {
		//T bucket = key % 1000;
		int bucket = (int)(key % 1000);
		buckets[bucket].push_back(key);

		for (typename std::vector<T>::iterator it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it)
		{
			if (*it == key)
			{
				return true;
			}
		}
		return false;
	}

	void print() {
		for (typename std::vector< std::vector<T> >::iterator row = buckets.begin(); row != buckets.end(); ++row)
		{
			for (typename std::vector<T>::iterator col = row->begin(); col != row->end(); ++col)
			{
				if (*col != 0)
				{
					std::cout << *col << "\t";
				}
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	MyHashSet<int> *hashset = new MyHashSet<int>();

	for (int i = 0; i < 10000; i++)
	{
		hashset->add(i);
	}
	hashset->print();

	for (int i = 9000; i < 10000; i++)
	{
		hashset->remove(i);
	}

	hashset->print();

	int a;
	std::cin >> a;
}
