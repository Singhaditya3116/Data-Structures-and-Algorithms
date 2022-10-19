#include<string>
using namespace std;

template<typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode<V>* next;

    MapNode(string key,V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};


template <typename V>
class ourmap{
    MapNode<V>** buckets;
    int size; //total elements in the hash table;(how many entries in the map.
    int bucketSize; //array size

public:
    ourmap(){
        size=0;
        bucketSize=5;
        buckets= new MapNode<V>*[bucketSize];
        for(int i=0;i<bucketSize;i++)
        {
            buckets[i]=NULL;
        }
    }

    ~ourmap()
    {
        for(int i=0;i<bucketSize;i++)
        {
            delete buckets[i];
        }
        delete [] buckets;
    }


    int getSize()
    {
        return size;
    }

    V getValue(string key) //search
    {
        int bucketIndex=getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];

        while(head != NULL)
        {
            if(head->key == key)
            {
                return head->value;
            }
            head=head->next;
        }
        return NULL;
    }

    float getLoadFactor()
    {
        return (float)size/bucketSize;
    }

private:

    int getBucketIndex(string key)
    {
        int hashCode=0;
        int currentCoeff=1;
        for(int i=key.length()-1 ;i>=0;i--)
        {
            hashCode += (key[i]*currentCoeff);
            hashCode = hashCode % bucketSize;
            currentCoeff*=37;
            currentCoeff = currentCoeff % bucketSize; // my integer does nit get oveflow very quickly.
        }

        return hashCode%bucketSize;
    }

    void rehash()
    {
        MapNode<V>** temp=buckets;
        buckets = new MapNode<V>*[2*bucketSize];  //making new bucket
        for(int i=0;i<2*bucketSize;i++)
        {
            buckets[i]=NULL;
        }
        int oldBucketSize = bucketSize;
        bucketSize*=2;
        size=0;

        for(int i=0;i<oldBucketSize;i++)
        {
            MapNode<V>* head = temp[i];
            while(head != NULL)
            {
                int index = getBucketIndex(head->key);
                insert(head->key,head->value);
                head=head->next;
            }
        }

        for(int i=0;i<oldBucketSize;i++)  //erasing the old bucket
        {
            delete temp[i];
        }
        delete [] temp;

    }

public:

    void insert(string key,V value)
    {
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head != NULL)
        {
            if(head->key == key)  // if key is already present then update the value.
            {
                head->value=value;
                return;
            }
            head=head->next;
        }

        head=buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key,value);
        newNode->next = head;
        buckets[bucketIndex]=newNode;
        size++;

        float loadFactor = (float)size/(float) bucketSize;
        if(loadFactor > 0.7)
        {
            rehash();
        }
    }

    V Delete(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];

        MapNode<V>* temp=NULL; //previous node to delete the key
        while(head != NULL)
        {
            if(head ->key == key)
            {
                if(temp == NULL) //if first elemeent  is the key;
                {
                    buckets[bucketIndex]=head->next;
                }
                else
                {
                    temp->next = head->next;
                }
                V deletedData = head->value;
                head->next =NULL;
                delete head;
                size--;
                return deletedData;
            }

            temp=head;
            head=head->next;
        }
        return NULL;
    }
};
