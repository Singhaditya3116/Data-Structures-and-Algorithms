#include<vector>
using namespace std;


class PriorityQueue{

    vector <int> pq;
    int index;

public:

    PriorityQueue()
    {
        index=-1;
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize() //no of elements in the priority queue.
    {
        return pq.size();
    }

    int getMin()
    {
        if(pq.size()==0)
        {
            return INT_MIN; //representing priority queue is empty
        }
        return pq[0];
    }

    void insert(int data)
    {
        if(index == -1)
        {
            index++;
            pq.push_back(data);
            return;
        }
        index++;
        pq.push_back(data);

        int childIndex=index; //to up-Heapify
        int parentIndex=(childIndex-1)/2;
        while(childIndex!=0)
        {
            if(pq[parentIndex] > pq[childIndex])
            {
                int tempData=pq[childIndex]; //swapping
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=tempData;

                childIndex=parentIndex;     //changng parent and childIndex;
                parentIndex=(childIndex-1)/2;
            }
            else
            {
                break;
            }
        }
    }

    int removeMin()
    {
        if(pq.size() == 0) // if heap is empty
        {
            return INT_MIN;
        }
        int value=pq[0];
        pq[0]=pq[index];
        pq.pop_back();
        index--;
        int parentIndex=0;
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;
        int swapIndex=0;

        while(leftChildIndex <= index) //if one or both the  child is present then only run.
        {

            if(rightChildIndex > index) //if only leftchild is present.
            {
                if(pq[parentIndex] < pq[leftChildIndex])
                {
                    break;
                }
                else
                {
                    int tempData = pq[parentIndex];
                    pq[parentIndex]=pq[leftChildIndex];
                    pq[leftChildIndex]=tempData;
                    break;
                }
            }

            if(pq[parentIndex] < pq[leftChildIndex] && pq[parentIndex] < pq[rightChildIndex]) //if value is situated at the right place.
            {
                break;
            }
            else
            {
                swapIndex = (pq[leftChildIndex] < pq[rightChildIndex]) ? leftChildIndex : rightChildIndex; //finding minimum from left and right
                //cout <<"parent "<<pq[leftChildIndex]<<" "<<pq[rightChildIndex]<<" left"<<leftChildIndex<<" "<<rightChildIndex<<endl;
                int tempData = pq[swapIndex];
                pq[swapIndex]=pq[parentIndex];
                pq[parentIndex]=tempData;

                parentIndex = swapIndex;
                leftChildIndex=(2*parentIndex)+1;
                rightChildIndex=(2*parentIndex)+2;
            }

        }
        return value;
    }

};
