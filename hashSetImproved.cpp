#include <list>
#include <vector>
#include <iostream>

template <class T>
    
class MyHashSet {
    private:
            std::vector< std::list<T> > buckets;
            int curr_vec_size;
    public:
    
        MyHashSet() {
            curr_vec_size = 0;
        }

        void add(T key) {
            T bucket = key % 3;

            if(bucket >= curr_vec_size) {
                // expand the 2D list by pushing empty vectors into it
                std::cout << "expanding list on key/bucket: " << key << "/" << bucket << std::endl;

                for(int i = curr_vec_size; i < curr_vec_size + 10; ++i)
                {
                    std::list<T> tmp;

                    buckets.push_back(tmp);

                    std::cout << "pushed " << i+1 << " lists" << std::endl;
                }
                curr_vec_size = buckets.size();

                buckets[bucket].push_back(key);
            }
            else
            {
                buckets[bucket].push_back(key);
            }
        }

        void remove(T key) {
            T bucket = key % 3;
            
            buckets[bucket].remove(key);
        }

       bool contains(T key) {
            T bucket = key % 3;
            buckets[bucket].push_back(key); 
           
            for(typename std::list<T>::iterator it = buckets[bucket].begin(); it!= buckets[bucket].end(); ++it)
            {
                if(*it == key)
                {
                    return true;
                }
            }
            return false;
        }

        void print() {
            for(typename std::vector< std::list<T> >::iterator row = buckets.begin(); row != buckets.end(); ++row)
            {
                for(typename std::list<T>::iterator col = row->begin(); col != row->end(); ++col)
                {
                    std::cout << *col << "\t";
                }
                std::cout << std::endl;
            }
        }
};

int main() 
{
    MyHashSet<int> *hashset = new MyHashSet<int>();

    for(int i = 0; i < 1000; i++)
    {
        hashset->add(i);
    }

    hashset->print();

    hashset->remove(3);
    hashset->remove(13);
    hashset->remove(144);
    hashset->remove(999);
    hashset->remove(0);

    hashset->print();
}
